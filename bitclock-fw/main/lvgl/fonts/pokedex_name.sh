npx lv_font_conv \
    --bpp 1 \
    --format lvgl \
    --font Overpass/Overpass-Bold.ttf \
    --range 0x20-0x7E,0xE9,0x2019,0x2640,0x2642 \
    --size 16 \
    --output "pokedex_name.c"
