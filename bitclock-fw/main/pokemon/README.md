# Pokémon of the day

Display mode that shows a different Pokémon every day: its sprite, Pokédex
entry, type, height, weight and base stats, with the date and time in the
corner.

All data is compiled into the firmware (`pokemon_data.c`, `pokemon_sprites.c`)
so the view works offline. The Pokémon is chosen by hashing the local calendar
date, so it stays the same all day, changes at midnight and survives reboots
without any saved state.

The roster is the whole National Pokédex (#0001–#1025), roughly 1 MB of
flash.

## Regenerating the data

`generate.py` downloads names, Pokédex entries, stats and sprites from
[PokéAPI](https://pokeapi.co), dithers the sprites to 1-bit and writes the C
files. Each Pokémon keeps era-appropriate pixel art by using the oldest game
that has it: Red/Blue gray for Generation I, then Crystal, Emerald, Platinum,
Black/White, and PokéAPI's default sprites for anything newer. Sprites are
upscaled by the largest integer factor that fits the view's 112x112 column.

```sh
pip install pillow
python3 generate.py            # the whole National Pokédex (default)
python3 generate.py --max-id 151
```

Downloads are cached in `cache/` (git-ignored). Run `clang-format` on the
output if it is not on your `PATH` when generating.

## Fonts

The view uses two fonts generated with `lv_font_conv` in `../lvgl/fonts/`:

- `pokedex_name` – Overpass Bold 16 px, for the Pokémon name
- `pokedex_text` – Overpass Medium 12 px, for everything else

See `pokedex_name.sh` and `pokedex_text.sh` next to them.
