#!/usr/bin/env python3
"""
Generate the on-device Pokémon dataset used by the "Pokémon of the day" view.

Downloads Pokédex data and Generation I (Red/Blue) sprites from PokéAPI, then
emits two C files next to this script:

  pokemon_data.c     Name, genus, type(s), Pokédex entry, size and base stats
  pokemon_sprites.c  1-bit LVGL images (upscaled, dithered) of each Pokémon

Everything is stored in flash so the device never needs network access to show
the view. Re-run this script to change the roster or presentation:

  python3 generate.py                # first 151 Pokémon (Generation I)
  python3 generate.py --max-id 251   # up to Generation II

Requires: python3, pillow (`pip install pillow`).
"""

import argparse
import json
import os
import re
import shutil
import subprocess
import sys
import urllib.request
from pathlib import Path

try:
    from PIL import Image
except ImportError:  # pragma: no cover
    sys.exit("pillow is required: pip install pillow")

API = "https://pokeapi.co/api/v2"
SPRITES = (
    "https://raw.githubusercontent.com/PokeAPI/sprites/master/sprites/pokemon/"
    "versions/generation-i/red-blue/transparent/gray/{id}.png"
)

# Pokédex entry preference. The Red/Blue text is short enough for the 2.7"
# screen and matches the Generation I sprites. Later games are fallbacks for
# Pokémon that did not exist yet.
VERSION_PREFERENCE = [
    "red",
    "blue",
    "yellow",
    "gold",
    "silver",
    "crystal",
    "ruby",
    "sapphire",
    "emerald",
    "firered",
    "leafgreen",
    "diamond",
    "pearl",
    "platinum",
    "heartgold",
    "soulsilver",
    "black",
    "white",
    "x",
    "y",
    "sun",
    "moon",
    "sword",
    "shield",
]

# Ordered dither for the 2x2 block each source pixel becomes after upscaling.
# Index = how many pixels of the block are black. Positions listed in the order
# they turn black as the source pixel gets darker.
DITHER_ORDER = [(0, 0), (1, 1), (0, 1), (1, 0)]


def fetch(url: str, dest: Path, binary: bool = False):
    if dest.exists() and dest.stat().st_size > 0:
        return dest.read_bytes() if binary else dest.read_text()
    dest.parent.mkdir(parents=True, exist_ok=True)
    req = urllib.request.Request(url, headers={"User-Agent": "bitclock-pokemon-generator"})
    with urllib.request.urlopen(req, timeout=30) as resp:
        data = resp.read()
    dest.write_bytes(data)
    return data if binary else data.decode("utf-8")


def clean_text(text: str) -> str:
    text = text.replace("\xad", "")  # soft hyphen
    text = text.replace("‘", "'").replace("“", '"').replace("”", '"')
    text = text.replace("\x0c", " ").replace("\n", " ").replace("\r", " ")
    text = re.sub(r"\s+", " ", text).strip()
    return text


def pick_english(items, key):
    for item in items:
        if item["language"]["name"] == "en":
            return item[key]
    return None


def pick_entry(flavor_texts):
    by_version = {}
    for entry in flavor_texts:
        if entry["language"]["name"] != "en":
            continue
        version = entry["version"]["name"]
        by_version.setdefault(version, clean_text(entry["flavor_text"]))
    for version in VERSION_PREFERENCE:
        if version in by_version:
            return by_version[version]
    if by_version:
        return next(iter(by_version.values()))
    return "No Pokédex data available."


def c_string(text: str) -> str:
    out = []
    for ch in text:
        if ch == '"':
            out.append('\\"')
        elif ch == "\\":
            out.append("\\\\")
        elif ord(ch) < 0x20:
            out.append(" ")
        else:
            out.append(ch)
    return '"' + "".join(out) + '"'


def sprite_bits(png_bytes: bytes, tmp: Path, scale: int):
    """Return (width, height, stride, rows) for a 1-bit upscaled sprite."""
    tmp.write_bytes(png_bytes)
    img = Image.open(tmp).convert("RGBA")
    bbox = img.getbbox()
    if bbox:
        img = img.crop(bbox)
    src_w, src_h = img.size
    w, h = src_w * scale, src_h * scale
    stride = (w + 7) // 8

    # Darkness per source pixel: 0 (white/transparent) .. 1 (black)
    px = img.load()
    rows = []
    for y in range(h):
        row = bytearray(stride)
        for x in range(w):
            r, g, b, a = px[x // scale, y // scale]
            if a < 128:
                darkness = 0.0
            else:
                darkness = 1.0 - (0.299 * r + 0.587 * g + 0.114 * b) / 255.0
            black_count = int(round(darkness * len(DITHER_ORDER)))
            if scale >= 2:
                pos = (x % 2, y % 2)
                black = DITHER_ORDER.index(pos) < black_count
            else:
                black = darkness >= 0.5
            if black:
                row[x // 8] |= 1 << (7 - (x % 8))
        rows.append(bytes(row))
    return w, h, stride, rows


def hex_block(data: bytes, indent: str = "        ") -> str:
    lines = []
    for i in range(0, len(data), 12):
        chunk = data[i : i + 12]
        lines.append(indent + ", ".join(f"0x{b:02x}" for b in chunk) + ",")
    return "\n".join(lines)


def main():
    here = Path(__file__).resolve().parent
    parser = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    parser.add_argument("--max-id", type=int, default=151, help="Highest national Pokédex number to include")
    parser.add_argument("--min-id", type=int, default=1)
    parser.add_argument("--scale", type=int, default=2, help="Integer upscale applied to the 56x56 sprites")
    parser.add_argument("--cache", type=Path, default=here / "cache", help="Download cache directory")
    parser.add_argument("--out", type=Path, default=here, help="Output directory for the C files")
    args = parser.parse_args()

    entries = []
    sprites = []
    tmp_png = args.cache / "tmp.png"
    args.cache.mkdir(parents=True, exist_ok=True)

    for pid in range(args.min_id, args.max_id + 1):
        species = json.loads(fetch(f"{API}/pokemon-species/{pid}", args.cache / "species" / f"{pid}.json"))
        pokemon = json.loads(fetch(f"{API}/pokemon/{pid}", args.cache / "pokemon" / f"{pid}.json"))
        png = fetch(SPRITES.format(id=pid), args.cache / "sprites" / f"{pid}.png", binary=True)

        name = pick_english(species["names"], "name") or pokemon["name"].title()
        genus = pick_english(species["genera"], "genus") or ""
        types = [t["type"]["name"].capitalize() for t in sorted(pokemon["types"], key=lambda t: t["slot"])]
        stats = {s["stat"]["name"]: s["base_stat"] for s in pokemon["stats"]}
        entry = pick_entry(species["flavor_text_entries"])

        entries.append(
            {
                "number": pid,
                "name": name,
                "genus": genus,
                "types": " · ".join(types),
                "entry": entry,
                "height_dm": pokemon["height"],
                "weight_hg": pokemon["weight"],
                "hp": stats.get("hp", 0),
                "attack": stats.get("attack", 0),
                "defense": stats.get("defense", 0),
                "special_attack": stats.get("special-attack", 0),
                "special_defense": stats.get("special-defense", 0),
                "speed": stats.get("speed", 0),
            }
        )
        sprites.append(sprite_bits(png, tmp_png, args.scale))
        print(f"#{pid:03d} {name:<12} {types!s:<22} {sprites[-1][0]}x{sprites[-1][1]} {len(entry)} chars", file=sys.stderr)

    if tmp_png.exists():
        tmp_png.unlink()

    header = (
        "//\n"
        "// GENERATED FILE - do not edit by hand.\n"
        "// Regenerate with: python3 pokemon/generate.py\n"
        "// Data and sprites courtesy of PokéAPI (https://pokeapi.co).\n"
        "//\n\n"
    )

    # Sprites
    out = [header, '#include "lvgl/lvgl.h"\n\n']
    out.append("#ifndef LV_ATTRIBUTE_MEM_ALIGN\n#define LV_ATTRIBUTE_MEM_ALIGN\n#endif\n\n")
    palette = bytes([0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0xFF])  # transparent, black
    for e, (w, h, stride, rows) in zip(entries, sprites):
        var = f"pokemon_sprite_{e['number']:03d}_map"
        out.append(f"static const LV_ATTRIBUTE_MEM_ALIGN LV_ATTRIBUTE_LARGE_CONST uint8_t {var}[] = {{\n")
        out.append(hex_block(palette + b"".join(rows)))
        out.append("\n};\n\n")
    out.append("const lv_image_dsc_t pokemon_sprites[] = {\n")
    for e, (w, h, stride, rows) in zip(entries, sprites):
        var = f"pokemon_sprite_{e['number']:03d}_map"
        out.append(
            "    {\n"
            "        .header.magic = LV_IMAGE_HEADER_MAGIC,\n"
            "        .header.cf = LV_COLOR_FORMAT_I1,\n"
            "        .header.flags = 0,\n"
            f"        .header.w = {w},\n"
            f"        .header.h = {h},\n"
            f"        .header.stride = {stride},\n"
            f"        .data_size = sizeof({var}),\n"
            f"        .data = {var},\n"
            "    },\n"
        )
    out.append("};\n")
    (args.out / "pokemon_sprites.c").write_text("".join(out), encoding="utf-8")

    # Data table
    out = [header, '#include "pokemon_data.h"\n\n']
    out.append("const pokemon_entry_t pokemon_entries[] = {\n")
    for i, e in enumerate(entries):
        out.append(
            "    {\n"
            f"        .number = {e['number']},\n"
            f"        .name = {c_string(e['name'])},\n"
            f"        .genus = {c_string(e['genus'])},\n"
            f"        .types = {c_string(e['types'])},\n"
            f"        .entry = {c_string(e['entry'])},\n"
            f"        .height_dm = {e['height_dm']},\n"
            f"        .weight_hg = {e['weight_hg']},\n"
            f"        .hp = {e['hp']},\n"
            f"        .attack = {e['attack']},\n"
            f"        .defense = {e['defense']},\n"
            f"        .special_attack = {e['special_attack']},\n"
            f"        .special_defense = {e['special_defense']},\n"
            f"        .speed = {e['speed']},\n"
            f"        .sprite = &pokemon_sprites[{i}],\n"
            "    },\n"
        )
    out.append("};\n\n")
    out.append(f"const uint16_t pokemon_entries_count = {len(entries)};\n")
    (args.out / "pokemon_data.c").write_text("".join(out), encoding="utf-8")

    clang_format = shutil.which("clang-format")
    if clang_format:
        subprocess.run([clang_format, "-i", str(args.out / "pokemon_sprites.c"), str(args.out / "pokemon_data.c")], check=False)

    total_sprite_bytes = sum(len(palette) + stride * h for (_, h, stride, _) in sprites)
    total_text = sum(len(e["entry"].encode()) + len(e["name"]) + len(e["genus"]) + len(e["types"]) for e in entries)
    print(
        f"Wrote {len(entries)} Pokémon: ~{total_sprite_bytes // 1024} KB sprites, ~{total_text // 1024} KB text",
        file=sys.stderr,
    )


if __name__ == "__main__":
    main()
