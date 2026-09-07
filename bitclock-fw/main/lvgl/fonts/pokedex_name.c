/*******************************************************************************
 * Size: 16 px
 * Bpp: 1
 * Opts: --bpp 1 --format lvgl --font Overpass/Overpass-Bold.ttf --range
 *0x20-0x7E,0xE9,0x2019,0x2640,0x2642 --size 16 --output pokedex_name.c
 ******************************************************************************/

#ifdef LV_LVGL_H_INCLUDE_SIMPLE
#include "lvgl.h"
#else
#include "lvgl/lvgl.h"
#endif

#ifndef POKEDEX_NAME
#define POKEDEX_NAME 1
#endif

#if POKEDEX_NAME

/*-----------------
 *    BITMAPS
 *----------------*/

/*Store the image of the glyphs*/
static LV_ATTRIBUTE_LARGE_CONST const uint8_t glyph_bitmap[] = {
    /* U+0020 " " */
    0x0,

    /* U+0021 "!" */
    0xff, 0xff, 0xff,

    /* U+0022 "\"" */
    0xde, 0xf7, 0xbd, 0x80,

    /* U+0023 "#" */
    0x13, 0xc, 0xc3, 0x31, 0xfe, 0xff, 0x8c, 0x83, 0x63, 0xfe, 0xff, 0x99, 0x86,
    0x61, 0x98,

    /* U+0024 "$" */
    0x18, 0x71, 0xf6, 0x7c, 0x1c, 0x1e, 0x1e, 0x1e, 0xf, 0x1e, 0x37, 0xc7, 0x86,
    0x0,

    /* U+0025 "%" */
    0x78, 0x4f, 0xcc, 0xcc, 0x8c, 0xd8, 0xff, 0x7, 0xa0, 0x6, 0xe0, 0xdf, 0xd,
    0xb1, 0x9b, 0x31, 0xf3, 0xe,

    /* U+0026 "&" */
    0x3c, 0x1f, 0x86, 0x61, 0x98, 0x3c, 0xe, 0x7, 0xd3, 0x3c, 0xc7, 0x31, 0xcf,
    0xf9, 0xf7,

    /* U+0027 "'" */
    0xff, 0xc0,

    /* U+0028 "(" */
    0x36, 0x6e, 0xcc, 0xcc, 0xcc, 0xc6, 0x63,

    /* U+0029 ")" */
    0xc6, 0x67, 0x33, 0x33, 0x33, 0x36, 0x6c,

    /* U+002A "*" */
    0x18, 0x18, 0x7e, 0xff, 0x3c, 0x3c, 0x66, 0x24,

    /* U+002B "+" */
    0x18, 0x18, 0x18, 0xff, 0xff, 0x18, 0x18, 0x18,

    /* U+002C "," */
    0xff, 0x80,

    /* U+002D "-" */
    0xff,

    /* U+002E "." */
    0xfc,

    /* U+002F "/" */
    0x3, 0x7, 0x6, 0x6, 0xc, 0xc, 0x18, 0x18, 0x30, 0x30, 0x30, 0x60, 0x60,
    0xc0, 0xc0,

    /* U+0030 "0" */
    0x3c, 0x7e, 0x66, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0x66, 0x7e, 0x3c,

    /* U+0031 "1" */
    0x3f, 0xf3, 0x33, 0x33, 0x33, 0x33,

    /* U+0032 "2" */
    0x3c, 0x7e, 0xe3, 0x3, 0x3, 0xe, 0x1e, 0x38, 0x70, 0xe0, 0xff, 0xff,

    /* U+0033 "3" */
    0x39, 0xff, 0x18, 0x30, 0x67, 0x8f, 0x3, 0x7, 0x8f, 0xf3, 0xc0,

    /* U+0034 "4" */
    0x3, 0x3, 0x83, 0xc3, 0xe3, 0xb1, 0x99, 0x8d, 0xff, 0xff, 0x81, 0x80, 0xc0,
    0x60,

    /* U+0035 "5" */
    0x7f, 0x7f, 0x60, 0x60, 0x7c, 0x7e, 0x23, 0x3, 0x3, 0x47, 0x7e, 0x3c,

    /* U+0036 "6" */
    0x2, 0x1e, 0x3c, 0x70, 0x60, 0xdc, 0xfe, 0xe7, 0xc3, 0xc3, 0xe7, 0x7e, 0x3c,

    /* U+0037 "7" */
    0xff, 0xff, 0x6, 0xe, 0xc, 0x18, 0x18, 0x38, 0x30, 0x30, 0x30, 0x30,

    /* U+0038 "8" */
    0x3c, 0xff, 0xc3, 0xc3, 0x7e, 0x7e, 0xe7, 0xc3, 0xc3, 0xe7, 0x7e, 0x3c,

    /* U+0039 "9" */
    0x3c, 0x7e, 0xc7, 0xc3, 0xc3, 0x7f, 0x3f, 0x7, 0x6, 0x1e, 0x3c, 0x30,

    /* U+003A ":" */
    0xfc, 0xf, 0xc0,

    /* U+003B ";" */
    0xfc, 0xf, 0xf8,

    /* U+003C "<" */
    0x3, 0xf, 0x3e, 0xf0, 0xf0, 0x7c, 0x1f, 0x3,

    /* U+003D "=" */
    0xff, 0xff, 0x0, 0x0, 0xff, 0xff,

    /* U+003E ">" */
    0x80, 0xf0, 0x7c, 0x1f, 0xf, 0x7c, 0xf0, 0xc0,

    /* U+003F "?" */
    0x3c, 0xff, 0x1e, 0x30, 0xe1, 0x86, 0xc, 0x0, 0x30, 0x60, 0xc0,

    /* U+0040 "@" */
    0xf, 0x83, 0xfe, 0x70, 0x66, 0xeb, 0xcf, 0xbd, 0x93, 0xd9, 0x7d, 0xfe, 0xef,
    0xc7, 0x0, 0x3f, 0x1, 0xf0,

    /* U+0041 "A" */
    0x6, 0x1, 0xc0, 0x3c, 0xf, 0x81, 0xb0, 0x33, 0xc, 0x61, 0xfc, 0x3f, 0xcc,
    0x19, 0x83, 0x30, 0x30,

    /* U+0042 "B" */
    0xfe, 0x7f, 0xb0, 0xd8, 0x6c, 0x37, 0xfb, 0xfd, 0x83, 0xc1, 0xe0, 0xff,
    0xdf, 0xc0,

    /* U+0043 "C" */
    0x1e, 0x3f, 0x98, 0xd8, 0xc, 0x6, 0x3, 0x1, 0x80, 0xc0, 0x31, 0x9f, 0xc7,
    0xc0,

    /* U+0044 "D" */
    0xfc, 0x7f, 0x30, 0xd8, 0x7c, 0x1e, 0xf, 0x7, 0x83, 0xc3, 0xe1, 0xbf, 0x9f,
    0x80,

    /* U+0045 "E" */
    0xff, 0xff, 0xc0, 0xc0, 0xc0, 0xfc, 0xfc, 0xc0, 0xc0, 0xc0, 0xff, 0xff,

    /* U+0046 "F" */
    0xff, 0xff, 0xc0, 0xc0, 0xc0, 0xfc, 0xfc, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0,

    /* U+0047 "G" */
    0x1e, 0x3f, 0x98, 0xfc, 0xc, 0x6, 0x3, 0x1f, 0x8f, 0xe1, 0xb1, 0xdf, 0xc3,
    0xc0,

    /* U+0048 "H" */
    0xc1, 0xe0, 0xf0, 0x78, 0x3c, 0x1f, 0xff, 0xff, 0x83, 0xc1, 0xe0, 0xf0,
    0x78, 0x30,

    /* U+0049 "I" */
    0xff, 0xff, 0xff,

    /* U+004A "J" */
    0x6, 0xc, 0x18, 0x30, 0x60, 0xc1, 0x83, 0x7, 0x9f, 0xf3, 0xc0,

    /* U+004B "K" */
    0xc3, 0x63, 0xb3, 0x99, 0x8d, 0xc7, 0xe3, 0xf9, 0xcc, 0xc7, 0x61, 0xb0,
    0xf8, 0x30,

    /* U+004C "L" */
    0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xff, 0xff,

    /* U+004D "M" */
    0xc0, 0xf8, 0x7e, 0x1f, 0x87, 0xf3, 0xfc, 0xfd, 0xef, 0x7b, 0xde, 0xf3,
    0x3c, 0xcf, 0x23,

    /* U+004E "N" */
    0xc1, 0xf0, 0xfc, 0x7e, 0x3f, 0x9e, 0xef, 0x37, 0x9f, 0xc7, 0xe1, 0xf0,
    0xf8, 0x30,

    /* U+004F "O" */
    0x1e, 0x1f, 0xe6, 0x1b, 0x87, 0xc0, 0xf0, 0x3c, 0xf, 0x3, 0xe1, 0xd8, 0x67,
    0xf8, 0x78,

    /* U+0050 "P" */
    0xfe, 0xfe, 0xc3, 0xc3, 0xc3, 0xfe, 0xfc, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0,

    /* U+0051 "Q" */
    0x1e, 0x1f, 0xe6, 0x1b, 0x87, 0xc0, 0xf0, 0x3c, 0xf, 0x3, 0xe7, 0xd9, 0xe7,
    0xf8, 0x7e, 0x1, 0x80,

    /* U+0052 "R" */
    0xff, 0x7f, 0xf0, 0x78, 0x3c, 0x1f, 0xfb, 0xf9, 0x8c, 0xc7, 0x61, 0xb0,
    0xd8, 0x30,

    /* U+0053 "S" */
    0x3c, 0xfe, 0xc7, 0xc0, 0xf0, 0x7c, 0x1e, 0x7, 0x43, 0xe3, 0xfe, 0x3c,

    /* U+0054 "T" */
    0xff, 0xff, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18,

    /* U+0055 "U" */
    0xc1, 0xe0, 0xf0, 0x78, 0x3c, 0x1e, 0xf, 0x7, 0x83, 0xc1, 0xf1, 0xdf, 0xc7,
    0xc0,

    /* U+0056 "V" */
    0xc1, 0xe0, 0xf8, 0xec, 0x66, 0x33, 0xb8, 0xd8, 0x6c, 0x36, 0xe, 0x7, 0x3,
    0x80,

    /* U+0057 "W" */
    0xc6, 0x3c, 0x63, 0xce, 0x6c, 0xe6, 0xef, 0x66, 0xb6, 0x7b, 0x67, 0x9c,
    0x79, 0xc7, 0x1c, 0x31, 0xc3, 0xc,

    /* U+0058 "X" */
    0xe3, 0xb1, 0x9d, 0xc6, 0xc3, 0xc0, 0xe0, 0x70, 0x7c, 0x36, 0x33, 0xb8,
    0xd8, 0x30,

    /* U+0059 "Y" */
    0xe1, 0xd8, 0x67, 0x38, 0xcc, 0x3f, 0x7, 0x80, 0xc0, 0x30, 0xc, 0x3, 0x0,
    0xc0, 0x30,

    /* U+005A "Z" */
    0xff, 0xff, 0x6, 0xe, 0xc, 0x18, 0x38, 0x30, 0x60, 0x60, 0xff, 0xff,

    /* U+005B "[" */
    0xff, 0xcc, 0xcc, 0xcc, 0xcc, 0xcc, 0xff,

    /* U+005C "\\" */
    0xc0, 0xe0, 0x60, 0x60, 0x30, 0x30, 0x18, 0x18, 0x1c, 0xc, 0xc, 0x6, 0x6,
    0x3, 0x3,

    /* U+005D "]" */
    0xff, 0x33, 0x33, 0x33, 0x33, 0x33, 0xff,

    /* U+005E "^" */
    0x18, 0x18, 0x3c, 0x3c, 0x66, 0x66, 0xc3,

    /* U+005F "_" */
    0xff, 0xff,

    /* U+0060 "`" */
    0xe3, 0xc,

    /* U+0061 "a" */
    0x3c, 0xfc, 0x1b, 0xff, 0xf8, 0xf1, 0xff, 0x76,

    /* U+0062 "b" */
    0xc1, 0x83, 0x7, 0xcf, 0xd9, 0xf1, 0xe3, 0xc7, 0x9f, 0xf7, 0xc0,

    /* U+0063 "c" */
    0x3c, 0xff, 0x9e, 0xc, 0x18, 0x39, 0xbf, 0x3c,

    /* U+0064 "d" */
    0x6, 0xc, 0x19, 0xf7, 0xfc, 0xf1, 0xe3, 0xc7, 0xcd, 0xf9, 0xf0,

    /* U+0065 "e" */
    0x3c, 0x7e, 0xc6, 0xfe, 0xff, 0xc0, 0xe4, 0x7e, 0x3c,

    /* U+0066 "f" */
    0x7b, 0xd9, 0xff, 0xb1, 0x8c, 0x63, 0x18, 0xc0,

    /* U+0067 "g" */
    0x3e, 0xff, 0x9e, 0x3c, 0x78, 0xf9, 0xbf, 0x3e, 0xc, 0x78, 0xe0,

    /* U+0068 "h" */
    0xc1, 0x83, 0x6, 0xef, 0xf8, 0xf1, 0xe3, 0xc7, 0x8f, 0x1e, 0x30,

    /* U+0069 "i" */
    0xf3, 0xff, 0xff,

    /* U+006A "j" */
    0x33, 0x3, 0x33, 0x33, 0x33, 0x33, 0x37, 0xe0,

    /* U+006B "k" */
    0x1, 0x83, 0x6, 0xc, 0xdb, 0x3c, 0x7c, 0xf9, 0xbb, 0x36, 0x7c, 0x60,

    /* U+006C "l" */
    0xff, 0xff, 0xff,

    /* U+006D "m" */
    0xfd, 0xef, 0xff, 0xc6, 0x3c, 0x63, 0xc6, 0x3c, 0x63, 0xc6, 0x3c, 0x63,
    0xc6, 0x30,

    /* U+006E "n" */
    0xfd, 0xff, 0x1e, 0x3c, 0x78, 0xf1, 0xe3, 0xc6,

    /* U+006F "o" */
    0x38, 0xfb, 0xbe, 0x3c, 0x78, 0xfb, 0xbe, 0x38,

    /* U+0070 "p" */
    0xf9, 0xfb, 0x3e, 0x3c, 0x78, 0xf3, 0xfe, 0xf9, 0x83, 0x6, 0x0,

    /* U+0071 "q" */
    0x3e, 0xff, 0x9e, 0x3c, 0x78, 0xf9, 0xbf, 0x3e, 0xc, 0x18, 0x30,

    /* U+0072 "r" */
    0xff, 0xf1, 0x8c, 0x63, 0x18, 0xc0,

    /* U+0073 "s" */
    0x7b, 0xfc, 0xb8, 0x78, 0x74, 0xff, 0x78,

    /* U+0074 "t" */
    0x3, 0x18, 0xcf, 0xfd, 0x8c, 0x63, 0x18, 0xf3, 0x80,

    /* U+0075 "u" */
    0xc7, 0x8f, 0x1e, 0x3c, 0x78, 0xf1, 0xff, 0x7e,

    /* U+0076 "v" */
    0x63, 0x63, 0x63, 0x36, 0x36, 0x36, 0x1c, 0x1c, 0x1c,

    /* U+0077 "w" */
    0xcc, 0xf3, 0x3d, 0xcf, 0x7b, 0x7f, 0x9d, 0xe7, 0x39, 0xce, 0x33, 0x0,

    /* U+0078 "x" */
    0x63, 0x1b, 0x8f, 0x83, 0x81, 0xc0, 0xf0, 0xd8, 0xee, 0x63, 0x0,

    /* U+0079 "y" */
    0x63, 0x31, 0x98, 0xc6, 0xc3, 0x61, 0xb0, 0x70, 0x38, 0x1c, 0xc, 0x6, 0x7,
    0x0,

    /* U+007A "z" */
    0x7e, 0xfc, 0x30, 0xe3, 0x86, 0x1c, 0x7f, 0xfe,

    /* U+007B "{" */
    0x19, 0xd8, 0xc6, 0x33, 0x98, 0x63, 0x18, 0xc6, 0x1c, 0x60,

    /* U+007C "|" */
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0,

    /* U+007D "}" */
    0xc7, 0xc, 0x63, 0x18, 0xe7, 0x31, 0x8c, 0x63, 0x73, 0x0,

    /* U+007E "~" */
    0x72, 0xfe, 0xce,

    /* U+00E9 "é" */
    0xc, 0x18, 0x0, 0x3c, 0x7e, 0xc6, 0xfe, 0xff, 0xc0, 0xe4, 0x7e, 0x3c,

    /* U+2019 "’" */
    0xff, 0x80,

    /* U+2640 "♀" */
    0x79, 0x9a, 0x14, 0x2f, 0xcf, 0x4, 0x7f, 0x10, 0x20, 0x40,

    /* U+2642 "♂" */
    0x7, 0x80, 0xc0, 0xaf, 0x9c, 0xc4, 0x22, 0x11, 0x98, 0x78, 0x0};

/*---------------------
 *  GLYPH DESCRIPTION
 *--------------------*/

static const lv_font_fmt_txt_glyph_dsc_t glyph_dsc[] = {
    {.bitmap_index = 0,
     .adv_w = 0,
     .box_w = 0,
     .box_h = 0,
     .ofs_x = 0,
     .ofs_y = 0} /* id = 0 reserved */,
    {.bitmap_index = 0,
     .adv_w = 64,
     .box_w = 1,
     .box_h = 1,
     .ofs_x = 0,
     .ofs_y = 0},
    {.bitmap_index = 1,
     .adv_w = 77,
     .box_w = 2,
     .box_h = 12,
     .ofs_x = 1,
     .ofs_y = 0},
    {.bitmap_index = 4,
     .adv_w = 113,
     .box_w = 5,
     .box_h = 5,
     .ofs_x = 1,
     .ofs_y = 7},
    {.bitmap_index = 8,
     .adv_w = 180,
     .box_w = 10,
     .box_h = 12,
     .ofs_x = 1,
     .ofs_y = 0},
    {.bitmap_index = 23,
     .adv_w = 154,
     .box_w = 7,
     .box_h = 15,
     .ofs_x = 1,
     .ofs_y = -2},
    {.bitmap_index = 37,
     .adv_w = 218,
     .box_w = 12,
     .box_h = 12,
     .ofs_x = 1,
     .ofs_y = 0},
    {.bitmap_index = 55,
     .adv_w = 182,
     .box_w = 10,
     .box_h = 12,
     .ofs_x = 1,
     .ofs_y = 0},
    {.bitmap_index = 70,
     .adv_w = 63,
     .box_w = 2,
     .box_h = 5,
     .ofs_x = 1,
     .ofs_y = 7},
    {.bitmap_index = 72,
     .adv_w = 95,
     .box_w = 4,
     .box_h = 14,
     .ofs_x = 1,
     .ofs_y = -2},
    {.bitmap_index = 79,
     .adv_w = 95,
     .box_w = 4,
     .box_h = 14,
     .ofs_x = 1,
     .ofs_y = -2},
    {.bitmap_index = 86,
     .adv_w = 141,
     .box_w = 8,
     .box_h = 8,
     .ofs_x = 0,
     .ofs_y = 4},
    {.bitmap_index = 94,
     .adv_w = 163,
     .box_w = 8,
     .box_h = 8,
     .ofs_x = 1,
     .ofs_y = 2},
    {.bitmap_index = 102,
     .adv_w = 64,
     .box_w = 2,
     .box_h = 5,
     .ofs_x = 1,
     .ofs_y = -2},
    {.bitmap_index = 104,
     .adv_w = 106,
     .box_w = 4,
     .box_h = 2,
     .ofs_x = 1,
     .ofs_y = 4},
    {.bitmap_index = 105,
     .adv_w = 62,
     .box_w = 2,
     .box_h = 3,
     .ofs_x = 1,
     .ofs_y = 0},
    {.bitmap_index = 106,
     .adv_w = 134,
     .box_w = 8,
     .box_h = 15,
     .ofs_x = 0,
     .ofs_y = -3},
    {.bitmap_index = 121,
     .adv_w = 168,
     .box_w = 8,
     .box_h = 12,
     .ofs_x = 1,
     .ofs_y = 0},
    {.bitmap_index = 133,
     .adv_w = 102,
     .box_w = 4,
     .box_h = 12,
     .ofs_x = 0,
     .ofs_y = 0},
    {.bitmap_index = 139,
     .adv_w = 157,
     .box_w = 8,
     .box_h = 12,
     .ofs_x = 1,
     .ofs_y = 0},
    {.bitmap_index = 151,
     .adv_w = 153,
     .box_w = 7,
     .box_h = 12,
     .ofs_x = 1,
     .ofs_y = 0},
    {.bitmap_index = 162,
     .adv_w = 164,
     .box_w = 9,
     .box_h = 12,
     .ofs_x = 1,
     .ofs_y = 0},
    {.bitmap_index = 176,
     .adv_w = 156,
     .box_w = 8,
     .box_h = 12,
     .ofs_x = 0,
     .ofs_y = 0},
    {.bitmap_index = 188,
     .adv_w = 157,
     .box_w = 8,
     .box_h = 13,
     .ofs_x = 1,
     .ofs_y = 0},
    {.bitmap_index = 201,
     .adv_w = 137,
     .box_w = 8,
     .box_h = 12,
     .ofs_x = 1,
     .ofs_y = 0},
    {.bitmap_index = 213,
     .adv_w = 161,
     .box_w = 8,
     .box_h = 12,
     .ofs_x = 1,
     .ofs_y = 0},
    {.bitmap_index = 225,
     .adv_w = 157,
     .box_w = 8,
     .box_h = 12,
     .ofs_x = 1,
     .ofs_y = 0},
    {.bitmap_index = 237,
     .adv_w = 62,
     .box_w = 2,
     .box_h = 9,
     .ofs_x = 1,
     .ofs_y = 0},
    {.bitmap_index = 240,
     .adv_w = 62,
     .box_w = 2,
     .box_h = 11,
     .ofs_x = 1,
     .ofs_y = -2},
    {.bitmap_index = 243,
     .adv_w = 163,
     .box_w = 8,
     .box_h = 8,
     .ofs_x = 1,
     .ofs_y = 2},
    {.bitmap_index = 251,
     .adv_w = 163,
     .box_w = 8,
     .box_h = 6,
     .ofs_x = 1,
     .ofs_y = 3},
    {.bitmap_index = 257,
     .adv_w = 163,
     .box_w = 8,
     .box_h = 8,
     .ofs_x = 1,
     .ofs_y = 2},
    {.bitmap_index = 265,
     .adv_w = 131,
     .box_w = 7,
     .box_h = 12,
     .ofs_x = 1,
     .ofs_y = 0},
    {.bitmap_index = 276,
     .adv_w = 214,
     .box_w = 12,
     .box_h = 12,
     .ofs_x = 1,
     .ofs_y = 0},
    {.bitmap_index = 294,
     .adv_w = 184,
     .box_w = 11,
     .box_h = 12,
     .ofs_x = 0,
     .ofs_y = 0},
    {.bitmap_index = 311,
     .adv_w = 177,
     .box_w = 9,
     .box_h = 12,
     .ofs_x = 1,
     .ofs_y = 0},
    {.bitmap_index = 325,
     .adv_w = 163,
     .box_w = 9,
     .box_h = 12,
     .ofs_x = 1,
     .ofs_y = 0},
    {.bitmap_index = 339,
     .adv_w = 182,
     .box_w = 9,
     .box_h = 12,
     .ofs_x = 1,
     .ofs_y = 0},
    {.bitmap_index = 353,
     .adv_w = 160,
     .box_w = 8,
     .box_h = 12,
     .ofs_x = 1,
     .ofs_y = 0},
    {.bitmap_index = 365,
     .adv_w = 147,
     .box_w = 8,
     .box_h = 12,
     .ofs_x = 1,
     .ofs_y = 0},
    {.bitmap_index = 377,
     .adv_w = 174,
     .box_w = 9,
     .box_h = 12,
     .ofs_x = 1,
     .ofs_y = 0},
    {.bitmap_index = 391,
     .adv_w = 185,
     .box_w = 9,
     .box_h = 12,
     .ofs_x = 1,
     .ofs_y = 0},
    {.bitmap_index = 405,
     .adv_w = 76,
     .box_w = 2,
     .box_h = 12,
     .ofs_x = 1,
     .ofs_y = 0},
    {.bitmap_index = 408,
     .adv_w = 143,
     .box_w = 7,
     .box_h = 12,
     .ofs_x = 1,
     .ofs_y = 0},
    {.bitmap_index = 419,
     .adv_w = 181,
     .box_w = 9,
     .box_h = 12,
     .ofs_x = 1,
     .ofs_y = 0},
    {.bitmap_index = 433,
     .adv_w = 145,
     .box_w = 8,
     .box_h = 12,
     .ofs_x = 1,
     .ofs_y = 0},
    {.bitmap_index = 445,
     .adv_w = 207,
     .box_w = 10,
     .box_h = 12,
     .ofs_x = 1,
     .ofs_y = 0},
    {.bitmap_index = 460,
     .adv_w = 184,
     .box_w = 9,
     .box_h = 12,
     .ofs_x = 1,
     .ofs_y = 0},
    {.bitmap_index = 474,
     .adv_w = 185,
     .box_w = 10,
     .box_h = 12,
     .ofs_x = 1,
     .ofs_y = 0},
    {.bitmap_index = 489,
     .adv_w = 163,
     .box_w = 8,
     .box_h = 12,
     .ofs_x = 1,
     .ofs_y = 0},
    {.bitmap_index = 501,
     .adv_w = 185,
     .box_w = 10,
     .box_h = 13,
     .ofs_x = 1,
     .ofs_y = -1},
    {.bitmap_index = 518,
     .adv_w = 177,
     .box_w = 9,
     .box_h = 12,
     .ofs_x = 1,
     .ofs_y = 0},
    {.bitmap_index = 532,
     .adv_w = 157,
     .box_w = 8,
     .box_h = 12,
     .ofs_x = 1,
     .ofs_y = 0},
    {.bitmap_index = 544,
     .adv_w = 154,
     .box_w = 8,
     .box_h = 12,
     .ofs_x = 1,
     .ofs_y = 0},
    {.bitmap_index = 556,
     .adv_w = 182,
     .box_w = 9,
     .box_h = 12,
     .ofs_x = 1,
     .ofs_y = 0},
    {.bitmap_index = 570,
     .adv_w = 175,
     .box_w = 9,
     .box_h = 12,
     .ofs_x = 1,
     .ofs_y = 0},
    {.bitmap_index = 584,
     .adv_w = 217,
     .box_w = 12,
     .box_h = 12,
     .ofs_x = 1,
     .ofs_y = 0},
    {.bitmap_index = 602,
     .adv_w = 174,
     .box_w = 9,
     .box_h = 12,
     .ofs_x = 1,
     .ofs_y = 0},
    {.bitmap_index = 616,
     .adv_w = 175,
     .box_w = 10,
     .box_h = 12,
     .ofs_x = 0,
     .ofs_y = 0},
    {.bitmap_index = 631,
     .adv_w = 164,
     .box_w = 8,
     .box_h = 12,
     .ofs_x = 1,
     .ofs_y = 0},
    {.bitmap_index = 643,
     .adv_w = 101,
     .box_w = 4,
     .box_h = 14,
     .ofs_x = 2,
     .ofs_y = -2},
    {.bitmap_index = 650,
     .adv_w = 134,
     .box_w = 8,
     .box_h = 15,
     .ofs_x = 0,
     .ofs_y = -3},
    {.bitmap_index = 665,
     .adv_w = 101,
     .box_w = 4,
     .box_h = 14,
     .ofs_x = 1,
     .ofs_y = -2},
    {.bitmap_index = 672,
     .adv_w = 163,
     .box_w = 8,
     .box_h = 7,
     .ofs_x = 1,
     .ofs_y = 6},
    {.bitmap_index = 679,
     .adv_w = 127,
     .box_w = 8,
     .box_h = 2,
     .ofs_x = 0,
     .ofs_y = -3},
    {.bitmap_index = 681,
     .adv_w = 119,
     .box_w = 5,
     .box_h = 3,
     .ofs_x = 1,
     .ofs_y = 10},
    {.bitmap_index = 683,
     .adv_w = 143,
     .box_w = 7,
     .box_h = 9,
     .ofs_x = 1,
     .ofs_y = 0},
    {.bitmap_index = 691,
     .adv_w = 148,
     .box_w = 7,
     .box_h = 12,
     .ofs_x = 1,
     .ofs_y = 0},
    {.bitmap_index = 702,
     .adv_w = 139,
     .box_w = 7,
     .box_h = 9,
     .ofs_x = 1,
     .ofs_y = 0},
    {.bitmap_index = 710,
     .adv_w = 148,
     .box_w = 7,
     .box_h = 12,
     .ofs_x = 1,
     .ofs_y = 0},
    {.bitmap_index = 721,
     .adv_w = 143,
     .box_w = 8,
     .box_h = 9,
     .ofs_x = 1,
     .ofs_y = 0},
    {.bitmap_index = 730,
     .adv_w = 93,
     .box_w = 5,
     .box_h = 12,
     .ofs_x = 1,
     .ofs_y = 0},
    {.bitmap_index = 738,
     .adv_w = 148,
     .box_w = 7,
     .box_h = 12,
     .ofs_x = 1,
     .ofs_y = -3},
    {.bitmap_index = 749,
     .adv_w = 152,
     .box_w = 7,
     .box_h = 12,
     .ofs_x = 1,
     .ofs_y = 0},
    {.bitmap_index = 760,
     .adv_w = 72,
     .box_w = 2,
     .box_h = 12,
     .ofs_x = 1,
     .ofs_y = 0},
    {.bitmap_index = 763,
     .adv_w = 72,
     .box_w = 4,
     .box_h = 15,
     .ofs_x = -1,
     .ofs_y = -3},
    {.bitmap_index = 771,
     .adv_w = 143,
     .box_w = 7,
     .box_h = 13,
     .ofs_x = 1,
     .ofs_y = 0},
    {.bitmap_index = 783,
     .adv_w = 74,
     .box_w = 2,
     .box_h = 12,
     .ofs_x = 1,
     .ofs_y = 0},
    {.bitmap_index = 786,
     .adv_w = 224,
     .box_w = 12,
     .box_h = 9,
     .ofs_x = 1,
     .ofs_y = 0},
    {.bitmap_index = 800,
     .adv_w = 152,
     .box_w = 7,
     .box_h = 9,
     .ofs_x = 1,
     .ofs_y = 0},
    {.bitmap_index = 808,
     .adv_w = 145,
     .box_w = 7,
     .box_h = 9,
     .ofs_x = 1,
     .ofs_y = 0},
    {.bitmap_index = 816,
     .adv_w = 148,
     .box_w = 7,
     .box_h = 12,
     .ofs_x = 1,
     .ofs_y = -3},
    {.bitmap_index = 827,
     .adv_w = 148,
     .box_w = 7,
     .box_h = 12,
     .ofs_x = 1,
     .ofs_y = -3},
    {.bitmap_index = 838,
     .adv_w = 107,
     .box_w = 5,
     .box_h = 9,
     .ofs_x = 1,
     .ofs_y = 0},
    {.bitmap_index = 844,
     .adv_w = 126,
     .box_w = 6,
     .box_h = 9,
     .ofs_x = 1,
     .ofs_y = 0},
    {.bitmap_index = 851,
     .adv_w = 100,
     .box_w = 5,
     .box_h = 13,
     .ofs_x = 1,
     .ofs_y = 0},
    {.bitmap_index = 860,
     .adv_w = 152,
     .box_w = 7,
     .box_h = 9,
     .ofs_x = 1,
     .ofs_y = 0},
    {.bitmap_index = 868,
     .adv_w = 143,
     .box_w = 8,
     .box_h = 9,
     .ofs_x = 0,
     .ofs_y = 0},
    {.bitmap_index = 877,
     .adv_w = 191,
     .box_w = 10,
     .box_h = 9,
     .ofs_x = 1,
     .ofs_y = 0},
    {.bitmap_index = 889,
     .adv_w = 148,
     .box_w = 9,
     .box_h = 9,
     .ofs_x = 0,
     .ofs_y = 0},
    {.bitmap_index = 900,
     .adv_w = 145,
     .box_w = 9,
     .box_h = 12,
     .ofs_x = 0,
     .ofs_y = -3},
    {.bitmap_index = 914,
     .adv_w = 139,
     .box_w = 7,
     .box_h = 9,
     .ofs_x = 1,
     .ofs_y = 0},
    {.bitmap_index = 922,
     .adv_w = 98,
     .box_w = 5,
     .box_h = 15,
     .ofs_x = 1,
     .ofs_y = -3},
    {.bitmap_index = 932,
     .adv_w = 77,
     .box_w = 2,
     .box_h = 25,
     .ofs_x = 1,
     .ofs_y = -6},
    {.bitmap_index = 939,
     .adv_w = 98,
     .box_w = 5,
     .box_h = 15,
     .ofs_x = 0,
     .ofs_y = -3},
    {.bitmap_index = 949,
     .adv_w = 163,
     .box_w = 8,
     .box_h = 3,
     .ofs_x = 1,
     .ofs_y = 4},
    {.bitmap_index = 952,
     .adv_w = 143,
     .box_w = 8,
     .box_h = 12,
     .ofs_x = 1,
     .ofs_y = 0},
    {.bitmap_index = 964,
     .adv_w = 64,
     .box_w = 2,
     .box_h = 5,
     .ofs_x = 1,
     .ofs_y = 7},
    {.bitmap_index = 966,
     .adv_w = 172,
     .box_w = 7,
     .box_h = 11,
     .ofs_x = 2,
     .ofs_y = 0},
    {.bitmap_index = 976,
     .adv_w = 172,
     .box_w = 9,
     .box_h = 9,
     .ofs_x = 1,
     .ofs_y = 0}};

/*---------------------
 *  CHARACTER MAPPING
 *--------------------*/

static const uint16_t unicode_list_1[] = {0x0, 0x1f30, 0x2557, 0x2559};

/*Collect the unicode lists and glyph_id offsets*/
static const lv_font_fmt_txt_cmap_t cmaps[] = {
    {.range_start = 32,
     .range_length = 95,
     .glyph_id_start = 1,
     .unicode_list = NULL,
     .glyph_id_ofs_list = NULL,
     .list_length = 0,
     .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_TINY},
    {.range_start = 233,
     .range_length = 9562,
     .glyph_id_start = 96,
     .unicode_list = unicode_list_1,
     .glyph_id_ofs_list = NULL,
     .list_length = 4,
     .type = LV_FONT_FMT_TXT_CMAP_SPARSE_TINY}};

/*--------------------
 *  ALL CUSTOM DATA
 *--------------------*/

#if LVGL_VERSION_MAJOR == 8
/*Store all the custom data of the font*/
static lv_font_fmt_txt_glyph_cache_t cache;
#endif

#if LVGL_VERSION_MAJOR >= 8
static const lv_font_fmt_txt_dsc_t font_dsc = {
#else
static lv_font_fmt_txt_dsc_t font_dsc = {
#endif
    .glyph_bitmap = glyph_bitmap,
    .glyph_dsc = glyph_dsc,
    .cmaps = cmaps,
    .kern_dsc = NULL,
    .kern_scale = 0,
    .cmap_num = 2,
    .bpp = 1,
    .kern_classes = 0,
    .bitmap_format = 0,
#if LVGL_VERSION_MAJOR == 8
    .cache = &cache
#endif
};

/*-----------------
 *  PUBLIC FONT
 *----------------*/

/*Initialize a public general font descriptor*/
#if LVGL_VERSION_MAJOR >= 8
const lv_font_t pokedex_name = {
#else
lv_font_t pokedex_name = {
#endif
    .get_glyph_dsc =
        lv_font_get_glyph_dsc_fmt_txt, /*Function pointer to get glyph's data*/
    .get_glyph_bitmap =
        lv_font_get_bitmap_fmt_txt, /*Function pointer to get glyph's bitmap*/
    .line_height = 25, /*The maximum line height required by the font*/
    .base_line = 6,    /*Baseline measured from the bottom of the line*/
#if !(LVGL_VERSION_MAJOR == 6 && LVGL_VERSION_MINOR == 0)
    .subpx = LV_FONT_SUBPX_NONE,
#endif
#if LV_VERSION_CHECK(7, 4, 0) || LVGL_VERSION_MAJOR >= 8
    .underline_position = -2,
    .underline_thickness = 1,
#endif
    .dsc = &font_dsc, /*The custom font data. Will be accessed by
                         `get_glyph_bitmap/dsc` */
#if LV_VERSION_CHECK(8, 2, 0) || LVGL_VERSION_MAJOR >= 9
    .fallback = NULL,
#endif
    .user_data = NULL,
};

#endif /*#if POKEDEX_NAME*/
