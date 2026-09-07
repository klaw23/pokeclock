# Pokémon of the day

Display mode that shows a different Generation I Pokémon every day: its
Red/Blue sprite, Pokédex entry, type, height, weight and base stats, with the
date and time in the corner.

All data is compiled into the firmware (`pokemon_data.c`, `pokemon_sprites.c`,
roughly 180 KB of flash) so the view works offline. The Pokémon is chosen by
hashing the local calendar date, so it stays the same all day, changes at
midnight and survives reboots without any saved state.

## Regenerating the data

`generate.py` downloads names, Pokédex entries, stats and the Generation I
gray sprites from [PokéAPI](https://pokeapi.co), upscales the 56x56 sprites 2x,
dithers them to 1-bit and writes the C files.

```sh
pip install pillow
python3 generate.py            # Generation I (default)
python3 generate.py --max-id 251
```

Downloads are cached in `cache/` (git-ignored). Run `clang-format` on the
output if it is not on your `PATH` when generating.

## Fonts

The view uses two fonts generated with `lv_font_conv` in `../lvgl/fonts/`:

- `pokedex_name` – Overpass Bold 16 px, for the Pokémon name
- `pokedex_text` – Overpass Medium 12 px, for everything else

See `pokedex_name.sh` and `pokedex_text.sh` next to them.
