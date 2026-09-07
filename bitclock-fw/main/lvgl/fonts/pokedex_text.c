/*******************************************************************************
 * Size: 12 px
 * Bpp: 1
 * Opts: --bpp 1 --format lvgl --font Overpass/Overpass-Medium.ttf --range
 *0x20-0x7E,0xB7,0xE9,0x2019,0x2640,0x2642 --size 12 --output pokedex_text.c
 ******************************************************************************/

#ifdef LV_LVGL_H_INCLUDE_SIMPLE
#include "lvgl.h"
#else
#include "lvgl/lvgl.h"
#endif

#ifndef POKEDEX_TEXT
#define POKEDEX_TEXT 1
#endif

#if POKEDEX_TEXT

/*-----------------
 *    BITMAPS
 *----------------*/

/*Store the image of the glyphs*/
static LV_ATTRIBUTE_LARGE_CONST const uint8_t glyph_bitmap[] = {
    /* U+0020 " " */
    0x0,

    /* U+0021 "!" */
    0xaa, 0xa3,

    /* U+0022 "\"" */
    0xbb, 0xa0,

    /* U+0023 "#" */
    0x2c, 0x53, 0xfa, 0x44, 0x9f, 0x92, 0x28,

    /* U+0024 "$" */
    0x23, 0xa3, 0x6, 0xc, 0x31, 0x71, 0x0,

    /* U+0025 "%" */
    0x63, 0x49, 0x25, 0xd, 0x80, 0xb0, 0xa4, 0x92, 0xc6,

    /* U+0026 "&" */
    0x30, 0x91, 0x21, 0x8d, 0x51, 0xa3, 0x3b,

    /* U+0027 "'" */
    0xe0,

    /* U+0028 "(" */
    0x4a, 0x49, 0x26, 0x40,

    /* U+0029 ")" */
    0x48, 0x92, 0x4b, 0x40,

    /* U+002A "*" */
    0x27, 0xdc, 0xa5, 0x0,

    /* U+002B "+" */
    0x20, 0x8f, 0xc8, 0x20,

    /* U+002C "," */
    0xf8,

    /* U+002D "-" */
    0xe0,

    /* U+002E "." */
    0xc0,

    /* U+002F "/" */
    0xc, 0x21, 0x84, 0x30, 0x86, 0x10, 0xc2, 0x0,

    /* U+0030 "0" */
    0x7b, 0x28, 0x61, 0x86, 0x1c, 0x9e,

    /* U+0031 "1" */
    0x75, 0x55,

    /* U+0032 "2" */
    0x7b, 0x10, 0x43, 0x39, 0x8c, 0x3f,

    /* U+0033 "3" */
    0x74, 0x42, 0x60, 0x86, 0x2e,

    /* U+0034 "4" */
    0x8, 0x30, 0xa3, 0x44, 0x9f, 0xc2, 0x4,

    /* U+0035 "5" */
    0x7d, 0x4, 0x1e, 0x4, 0x10, 0xde,

    /* U+0036 "6" */
    0x18, 0x84, 0x3e, 0x8e, 0x18, 0x5e,

    /* U+0037 "7" */
    0xf8, 0x44, 0x22, 0x10, 0x84,

    /* U+0038 "8" */
    0x72, 0x28, 0x9e, 0xce, 0x18, 0x5e,

    /* U+0039 "9" */
    0x7a, 0x18, 0x61, 0x7c, 0x21, 0x9c,

    /* U+003A ":" */
    0xc0, 0xc0,

    /* U+003B ";" */
    0xc0, 0xd8,

    /* U+003C "<" */
    0x4, 0x7e, 0x38, 0x38, 0x10,

    /* U+003D "=" */
    0xfc, 0xf, 0xc0,

    /* U+003E ">" */
    0x3, 0x83, 0x87, 0xe2, 0x0,

    /* U+003F "?" */
    0x74, 0x62, 0x31, 0x18, 0x6,

    /* U+0040 "@" */
    0x3c, 0x42, 0x9d, 0xa5, 0xa5, 0xbe, 0x40, 0x38,

    /* U+0041 "A" */
    0x30, 0x60, 0xe2, 0x44, 0x9f, 0xa1, 0x43,

    /* U+0042 "B" */
    0xfa, 0x18, 0x7e, 0x86, 0x18, 0x7e,

    /* U+0043 "C" */
    0x39, 0x18, 0x20, 0x82, 0x4, 0x5e,

    /* U+0044 "D" */
    0xf2, 0x28, 0x61, 0x86, 0x18, 0xbc,

    /* U+0045 "E" */
    0xfc, 0x21, 0xe8, 0x42, 0x1f,

    /* U+0046 "F" */
    0xfc, 0x21, 0xe8, 0x42, 0x10,

    /* U+0047 "G" */
    0x39, 0x18, 0x20, 0x8e, 0x14, 0x5e,

    /* U+0048 "H" */
    0x86, 0x18, 0x7f, 0x86, 0x18, 0x61,

    /* U+0049 "I" */
    0xff,

    /* U+004A "J" */
    0x8, 0x42, 0x10, 0x86, 0x2e,

    /* U+004B "K" */
    0x8a, 0x4b, 0x3c, 0xd2, 0x68, 0xa1,

    /* U+004C "L" */
    0x84, 0x21, 0x8, 0x42, 0x1f,

    /* U+004D "M" */
    0x83, 0x8f, 0x1f, 0x7a, 0xb5, 0x64, 0xc9,

    /* U+004E "N" */
    0x87, 0x1e, 0x69, 0x96, 0x78, 0xe1,

    /* U+004F "O" */
    0x38, 0x8a, 0xc, 0x18, 0x30, 0x51, 0x1c,

    /* U+0050 "P" */
    0xfa, 0x18, 0x61, 0xfa, 0x8, 0x20,

    /* U+0051 "Q" */
    0x38, 0x8a, 0xc, 0x18, 0x31, 0x53, 0x1e, 0x0,

    /* U+0052 "R" */
    0xfa, 0x18, 0x61, 0xfa, 0x68, 0xa3,

    /* U+0053 "S" */
    0x74, 0x60, 0xc1, 0x86, 0x2e,

    /* U+0054 "T" */
    0xfc, 0x82, 0x8, 0x20, 0x82, 0x8,

    /* U+0055 "U" */
    0x86, 0x18, 0x61, 0x86, 0x1c, 0xde,

    /* U+0056 "V" */
    0x86, 0x1c, 0xd2, 0x48, 0xc3, 0xc,

    /* U+0057 "W" */
    0x99, 0x4c, 0xa6, 0x53, 0xa6, 0x73, 0x31, 0x98, 0x84,

    /* U+0058 "X" */
    0x8d, 0x27, 0xc, 0x31, 0x4c, 0xa3,

    /* U+0059 "Y" */
    0xc6, 0x88, 0xa1, 0x41, 0x2, 0x4, 0x8,

    /* U+005A "Z" */
    0xfc, 0x21, 0x84, 0x21, 0xc, 0x3f,

    /* U+005B "[" */
    0xf2, 0x49, 0x24, 0x9c,

    /* U+005C "\\" */
    0x81, 0x4, 0x8, 0x20, 0x41, 0x2, 0x8, 0x10,

    /* U+005D "]" */
    0xe4, 0x92, 0x49, 0x3c,

    /* U+005E "^" */
    0x31, 0xc4, 0xb2,

    /* U+005F "_" */
    0xfc,

    /* U+0060 "`" */
    0xc8,

    /* U+0061 "a" */
    0x70, 0x5f, 0x18, 0xbc,

    /* U+0062 "b" */
    0x84, 0x3d, 0x18, 0xc6, 0x3e,

    /* U+0063 "c" */
    0x74, 0xa1, 0x9, 0xb8,

    /* U+0064 "d" */
    0x8, 0x5f, 0x18, 0xc6, 0x2f,

    /* U+0065 "e" */
    0x7a, 0x2f, 0xe0, 0xc1, 0xe0,

    /* U+0066 "f" */
    0x74, 0xf4, 0x44, 0x44,

    /* U+0067 "g" */
    0x7c, 0x63, 0x18, 0xbc, 0x26,

    /* U+0068 "h" */
    0x84, 0x3d, 0x18, 0xc6, 0x31,

    /* U+0069 "i" */
    0xbf,

    /* U+006A "j" */
    0x20, 0x92, 0x49, 0x3c,

    /* U+006B "k" */
    0x84, 0x2d, 0xce, 0x5a, 0x53,

    /* U+006C "l" */
    0xff,

    /* U+006D "m" */
    0xf7, 0x44, 0x62, 0x31, 0x18, 0x8c, 0x44,

    /* U+006E "n" */
    0xf4, 0x63, 0x18, 0xc4,

    /* U+006F "o" */
    0x74, 0x63, 0x18, 0xb8,

    /* U+0070 "p" */
    0xf4, 0x63, 0x18, 0xfa, 0x10,

    /* U+0071 "q" */
    0x7c, 0x63, 0x18, 0xbc, 0x21,

    /* U+0072 "r" */
    0xf2, 0x49, 0x0,

    /* U+0073 "s" */
    0xf4, 0xb8, 0x61, 0x38,

    /* U+0074 "t" */
    0x44, 0xf4, 0x44, 0x47,

    /* U+0075 "u" */
    0x8c, 0x63, 0x18, 0xbc,

    /* U+0076 "v" */
    0x45, 0x26, 0x8e, 0x30, 0xc0,

    /* U+0077 "w" */
    0x49, 0x59, 0x57, 0x56, 0x36, 0x26,

    /* U+0078 "x" */
    0x4c, 0xe3, 0xc, 0x69, 0x30,

    /* U+0079 "y" */
    0x45, 0x36, 0x8a, 0x30, 0x43, 0x8,

    /* U+007A "z" */
    0xf3, 0x24, 0x8f,

    /* U+007B "{" */
    0x34, 0x44, 0x84, 0x44, 0x43,

    /* U+007C "|" */
    0xff, 0xff, 0x80,

    /* U+007D "}" */
    0xc2, 0x22, 0x12, 0x22, 0x2c,

    /* U+007E "~" */
    0xe6, 0x60,

    /* U+00B7 "·" */
    0xc0,

    /* U+00E9 "é" */
    0x18, 0x87, 0xa2, 0xfe, 0xc, 0x1e,

    /* U+2019 "’" */
    0xd8,

    /* U+2640 "♀" */
    0x74, 0x63, 0x17, 0x13, 0xc4, 0x20,

    /* U+2642 "♂" */
    0x1e, 0xd, 0xec, 0x58, 0x91, 0x1c, 0x0};

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
     .adv_w = 46,
     .box_w = 1,
     .box_h = 1,
     .ofs_x = 0,
     .ofs_y = 0},
    {.bitmap_index = 1,
     .adv_w = 54,
     .box_w = 2,
     .box_h = 8,
     .ofs_x = 1,
     .ofs_y = 0},
    {.bitmap_index = 3,
     .adv_w = 80,
     .box_w = 4,
     .box_h = 3,
     .ofs_x = 1,
     .ofs_y = 5},
    {.bitmap_index = 5,
     .adv_w = 132,
     .box_w = 7,
     .box_h = 8,
     .ofs_x = 1,
     .ofs_y = 0},
    {.bitmap_index = 12,
     .adv_w = 114,
     .box_w = 5,
     .box_h = 10,
     .ofs_x = 1,
     .ofs_y = -1},
    {.bitmap_index = 19,
     .adv_w = 166,
     .box_w = 9,
     .box_h = 8,
     .ofs_x = 1,
     .ofs_y = 0},
    {.bitmap_index = 28,
     .adv_w = 132,
     .box_w = 7,
     .box_h = 8,
     .ofs_x = 1,
     .ofs_y = 0},
    {.bitmap_index = 35,
     .adv_w = 43,
     .box_w = 1,
     .box_h = 3,
     .ofs_x = 1,
     .ofs_y = 5},
    {.bitmap_index = 36,
     .adv_w = 68,
     .box_w = 3,
     .box_h = 9,
     .ofs_x = 1,
     .ofs_y = -1},
    {.bitmap_index = 40,
     .adv_w = 68,
     .box_w = 3,
     .box_h = 9,
     .ofs_x = 0,
     .ofs_y = -1},
    {.bitmap_index = 44,
     .adv_w = 104,
     .box_w = 5,
     .box_h = 5,
     .ofs_x = 1,
     .ofs_y = 3},
    {.bitmap_index = 48,
     .adv_w = 123,
     .box_w = 6,
     .box_h = 5,
     .ofs_x = 1,
     .ofs_y = 1},
    {.bitmap_index = 52,
     .adv_w = 45,
     .box_w = 2,
     .box_h = 3,
     .ofs_x = 1,
     .ofs_y = -1},
    {.bitmap_index = 53,
     .adv_w = 78,
     .box_w = 3,
     .box_h = 1,
     .ofs_x = 1,
     .ofs_y = 3},
    {.bitmap_index = 54,
     .adv_w = 44,
     .box_w = 2,
     .box_h = 1,
     .ofs_x = 1,
     .ofs_y = 0},
    {.bitmap_index = 55,
     .adv_w = 96,
     .box_w = 6,
     .box_h = 10,
     .ofs_x = 0,
     .ofs_y = -2},
    {.bitmap_index = 63,
     .adv_w = 124,
     .box_w = 6,
     .box_h = 8,
     .ofs_x = 1,
     .ofs_y = 0},
    {.bitmap_index = 69,
     .adv_w = 73,
     .box_w = 2,
     .box_h = 8,
     .ofs_x = 1,
     .ofs_y = 0},
    {.bitmap_index = 71,
     .adv_w = 118,
     .box_w = 6,
     .box_h = 8,
     .ofs_x = 1,
     .ofs_y = 0},
    {.bitmap_index = 77,
     .adv_w = 115,
     .box_w = 5,
     .box_h = 8,
     .ofs_x = 1,
     .ofs_y = 0},
    {.bitmap_index = 82,
     .adv_w = 121,
     .box_w = 7,
     .box_h = 8,
     .ofs_x = 1,
     .ofs_y = 0},
    {.bitmap_index = 89,
     .adv_w = 119,
     .box_w = 6,
     .box_h = 8,
     .ofs_x = 0,
     .ofs_y = 0},
    {.bitmap_index = 95,
     .adv_w = 116,
     .box_w = 6,
     .box_h = 8,
     .ofs_x = 1,
     .ofs_y = 0},
    {.bitmap_index = 101,
     .adv_w = 101,
     .box_w = 5,
     .box_h = 8,
     .ofs_x = 1,
     .ofs_y = 0},
    {.bitmap_index = 106,
     .adv_w = 118,
     .box_w = 6,
     .box_h = 8,
     .ofs_x = 1,
     .ofs_y = 0},
    {.bitmap_index = 112,
     .adv_w = 116,
     .box_w = 6,
     .box_h = 8,
     .ofs_x = 1,
     .ofs_y = 0},
    {.bitmap_index = 118,
     .adv_w = 44,
     .box_w = 2,
     .box_h = 5,
     .ofs_x = 1,
     .ofs_y = 0},
    {.bitmap_index = 120,
     .adv_w = 44,
     .box_w = 2,
     .box_h = 7,
     .ofs_x = 1,
     .ofs_y = -2},
    {.bitmap_index = 122,
     .adv_w = 123,
     .box_w = 6,
     .box_h = 6,
     .ofs_x = 1,
     .ofs_y = 1},
    {.bitmap_index = 127,
     .adv_w = 123,
     .box_w = 6,
     .box_h = 3,
     .ofs_x = 1,
     .ofs_y = 2},
    {.bitmap_index = 130,
     .adv_w = 123,
     .box_w = 6,
     .box_h = 6,
     .ofs_x = 1,
     .ofs_y = 1},
    {.bitmap_index = 135,
     .adv_w = 98,
     .box_w = 5,
     .box_h = 8,
     .ofs_x = 1,
     .ofs_y = 0},
    {.bitmap_index = 140,
     .adv_w = 157,
     .box_w = 8,
     .box_h = 8,
     .ofs_x = 1,
     .ofs_y = 0},
    {.bitmap_index = 148,
     .adv_w = 133,
     .box_w = 7,
     .box_h = 8,
     .ofs_x = 1,
     .ofs_y = 0},
    {.bitmap_index = 155,
     .adv_w = 128,
     .box_w = 6,
     .box_h = 8,
     .ofs_x = 1,
     .ofs_y = 0},
    {.bitmap_index = 161,
     .adv_w = 124,
     .box_w = 6,
     .box_h = 8,
     .ofs_x = 1,
     .ofs_y = 0},
    {.bitmap_index = 167,
     .adv_w = 133,
     .box_w = 6,
     .box_h = 8,
     .ofs_x = 1,
     .ofs_y = 0},
    {.bitmap_index = 173,
     .adv_w = 117,
     .box_w = 5,
     .box_h = 8,
     .ofs_x = 1,
     .ofs_y = 0},
    {.bitmap_index = 178,
     .adv_w = 109,
     .box_w = 5,
     .box_h = 8,
     .ofs_x = 1,
     .ofs_y = 0},
    {.bitmap_index = 183,
     .adv_w = 132,
     .box_w = 6,
     .box_h = 8,
     .ofs_x = 1,
     .ofs_y = 0},
    {.bitmap_index = 189,
     .adv_w = 136,
     .box_w = 6,
     .box_h = 8,
     .ofs_x = 1,
     .ofs_y = 0},
    {.bitmap_index = 195,
     .adv_w = 55,
     .box_w = 1,
     .box_h = 8,
     .ofs_x = 1,
     .ofs_y = 0},
    {.bitmap_index = 196,
     .adv_w = 106,
     .box_w = 5,
     .box_h = 8,
     .ofs_x = 0,
     .ofs_y = 0},
    {.bitmap_index = 201,
     .adv_w = 130,
     .box_w = 6,
     .box_h = 8,
     .ofs_x = 1,
     .ofs_y = 0},
    {.bitmap_index = 207,
     .adv_w = 108,
     .box_w = 5,
     .box_h = 8,
     .ofs_x = 1,
     .ofs_y = 0},
    {.bitmap_index = 212,
     .adv_w = 155,
     .box_w = 7,
     .box_h = 8,
     .ofs_x = 1,
     .ofs_y = 0},
    {.bitmap_index = 219,
     .adv_w = 137,
     .box_w = 6,
     .box_h = 8,
     .ofs_x = 1,
     .ofs_y = 0},
    {.bitmap_index = 225,
     .adv_w = 140,
     .box_w = 7,
     .box_h = 8,
     .ofs_x = 1,
     .ofs_y = 0},
    {.bitmap_index = 232,
     .adv_w = 122,
     .box_w = 6,
     .box_h = 8,
     .ofs_x = 1,
     .ofs_y = 0},
    {.bitmap_index = 238,
     .adv_w = 140,
     .box_w = 7,
     .box_h = 9,
     .ofs_x = 1,
     .ofs_y = -1},
    {.bitmap_index = 246,
     .adv_w = 129,
     .box_w = 6,
     .box_h = 8,
     .ofs_x = 1,
     .ofs_y = 0},
    {.bitmap_index = 252,
     .adv_w = 116,
     .box_w = 5,
     .box_h = 8,
     .ofs_x = 1,
     .ofs_y = 0},
    {.bitmap_index = 257,
     .adv_w = 113,
     .box_w = 6,
     .box_h = 8,
     .ofs_x = 1,
     .ofs_y = 0},
    {.bitmap_index = 263,
     .adv_w = 134,
     .box_w = 6,
     .box_h = 8,
     .ofs_x = 1,
     .ofs_y = 0},
    {.bitmap_index = 269,
     .adv_w = 127,
     .box_w = 6,
     .box_h = 8,
     .ofs_x = 1,
     .ofs_y = 0},
    {.bitmap_index = 275,
     .adv_w = 162,
     .box_w = 9,
     .box_h = 8,
     .ofs_x = 1,
     .ofs_y = 0},
    {.bitmap_index = 284,
     .adv_w = 121,
     .box_w = 6,
     .box_h = 8,
     .ofs_x = 1,
     .ofs_y = 0},
    {.bitmap_index = 290,
     .adv_w = 126,
     .box_w = 7,
     .box_h = 8,
     .ofs_x = 0,
     .ofs_y = 0},
    {.bitmap_index = 297,
     .adv_w = 124,
     .box_w = 6,
     .box_h = 8,
     .ofs_x = 1,
     .ofs_y = 0},
    {.bitmap_index = 303,
     .adv_w = 73,
     .box_w = 3,
     .box_h = 10,
     .ofs_x = 1,
     .ofs_y = -2},
    {.bitmap_index = 307,
     .adv_w = 96,
     .box_w = 6,
     .box_h = 10,
     .ofs_x = 0,
     .ofs_y = -2},
    {.bitmap_index = 315,
     .adv_w = 73,
     .box_w = 3,
     .box_h = 10,
     .ofs_x = 0,
     .ofs_y = -2},
    {.bitmap_index = 319,
     .adv_w = 123,
     .box_w = 6,
     .box_h = 4,
     .ofs_x = 1,
     .ofs_y = 4},
    {.bitmap_index = 322,
     .adv_w = 94,
     .box_w = 6,
     .box_h = 1,
     .ofs_x = 0,
     .ofs_y = -2},
    {.bitmap_index = 323,
     .adv_w = 77,
     .box_w = 3,
     .box_h = 2,
     .ofs_x = 1,
     .ofs_y = 7},
    {.bitmap_index = 324,
     .adv_w = 103,
     .box_w = 5,
     .box_h = 6,
     .ofs_x = 1,
     .ofs_y = 0},
    {.bitmap_index = 328,
     .adv_w = 109,
     .box_w = 5,
     .box_h = 8,
     .ofs_x = 1,
     .ofs_y = 0},
    {.bitmap_index = 333,
     .adv_w = 99,
     .box_w = 5,
     .box_h = 6,
     .ofs_x = 1,
     .ofs_y = 0},
    {.bitmap_index = 337,
     .adv_w = 109,
     .box_w = 5,
     .box_h = 8,
     .ofs_x = 1,
     .ofs_y = 0},
    {.bitmap_index = 342,
     .adv_w = 105,
     .box_w = 6,
     .box_h = 6,
     .ofs_x = 1,
     .ofs_y = 0},
    {.bitmap_index = 347,
     .adv_w = 66,
     .box_w = 4,
     .box_h = 8,
     .ofs_x = 1,
     .ofs_y = 0},
    {.bitmap_index = 351,
     .adv_w = 109,
     .box_w = 5,
     .box_h = 8,
     .ofs_x = 1,
     .ofs_y = -2},
    {.bitmap_index = 356,
     .adv_w = 110,
     .box_w = 5,
     .box_h = 8,
     .ofs_x = 1,
     .ofs_y = 0},
    {.bitmap_index = 361,
     .adv_w = 51,
     .box_w = 1,
     .box_h = 8,
     .ofs_x = 1,
     .ofs_y = 0},
    {.bitmap_index = 362,
     .adv_w = 51,
     .box_w = 3,
     .box_h = 10,
     .ofs_x = -1,
     .ofs_y = -2},
    {.bitmap_index = 366,
     .adv_w = 104,
     .box_w = 5,
     .box_h = 8,
     .ofs_x = 1,
     .ofs_y = 0},
    {.bitmap_index = 371,
     .adv_w = 52,
     .box_w = 1,
     .box_h = 8,
     .ofs_x = 1,
     .ofs_y = 0},
    {.bitmap_index = 372,
     .adv_w = 164,
     .box_w = 9,
     .box_h = 6,
     .ofs_x = 1,
     .ofs_y = 0},
    {.bitmap_index = 379,
     .adv_w = 110,
     .box_w = 5,
     .box_h = 6,
     .ofs_x = 1,
     .ofs_y = 0},
    {.bitmap_index = 383,
     .adv_w = 108,
     .box_w = 5,
     .box_h = 6,
     .ofs_x = 1,
     .ofs_y = 0},
    {.bitmap_index = 387,
     .adv_w = 109,
     .box_w = 5,
     .box_h = 8,
     .ofs_x = 1,
     .ofs_y = -2},
    {.bitmap_index = 392,
     .adv_w = 109,
     .box_w = 5,
     .box_h = 8,
     .ofs_x = 1,
     .ofs_y = -2},
    {.bitmap_index = 397,
     .adv_w = 76,
     .box_w = 3,
     .box_h = 6,
     .ofs_x = 1,
     .ofs_y = 0},
    {.bitmap_index = 400,
     .adv_w = 92,
     .box_w = 5,
     .box_h = 6,
     .ofs_x = 1,
     .ofs_y = 0},
    {.bitmap_index = 404,
     .adv_w = 74,
     .box_w = 4,
     .box_h = 8,
     .ofs_x = 1,
     .ofs_y = 0},
    {.bitmap_index = 408,
     .adv_w = 110,
     .box_w = 5,
     .box_h = 6,
     .ofs_x = 1,
     .ofs_y = 0},
    {.bitmap_index = 412,
     .adv_w = 101,
     .box_w = 6,
     .box_h = 6,
     .ofs_x = 0,
     .ofs_y = 0},
    {.bitmap_index = 417,
     .adv_w = 139,
     .box_w = 8,
     .box_h = 6,
     .ofs_x = 0,
     .ofs_y = 0},
    {.bitmap_index = 423,
     .adv_w = 103,
     .box_w = 6,
     .box_h = 6,
     .ofs_x = 0,
     .ofs_y = 0},
    {.bitmap_index = 428,
     .adv_w = 104,
     .box_w = 6,
     .box_h = 8,
     .ofs_x = 0,
     .ofs_y = -2},
    {.bitmap_index = 434,
     .adv_w = 99,
     .box_w = 4,
     .box_h = 6,
     .ofs_x = 1,
     .ofs_y = 0},
    {.bitmap_index = 437,
     .adv_w = 72,
     .box_w = 4,
     .box_h = 10,
     .ofs_x = 0,
     .ofs_y = -2},
    {.bitmap_index = 442,
     .adv_w = 54,
     .box_w = 1,
     .box_h = 17,
     .ofs_x = 1,
     .ofs_y = -4},
    {.bitmap_index = 445,
     .adv_w = 72,
     .box_w = 4,
     .box_h = 10,
     .ofs_x = 0,
     .ofs_y = -2},
    {.bitmap_index = 450,
     .adv_w = 123,
     .box_w = 6,
     .box_h = 2,
     .ofs_x = 1,
     .ofs_y = 3},
    {.bitmap_index = 452,
     .adv_w = 44,
     .box_w = 2,
     .box_h = 1,
     .ofs_x = 1,
     .ofs_y = 4},
    {.bitmap_index = 453,
     .adv_w = 105,
     .box_w = 6,
     .box_h = 8,
     .ofs_x = 1,
     .ofs_y = 0},
    {.bitmap_index = 459,
     .adv_w = 45,
     .box_w = 2,
     .box_h = 3,
     .ofs_x = 1,
     .ofs_y = 5},
    {.bitmap_index = 460,
     .adv_w = 129,
     .box_w = 5,
     .box_h = 9,
     .ofs_x = 2,
     .ofs_y = 0},
    {.bitmap_index = 466,
     .adv_w = 129,
     .box_w = 7,
     .box_h = 7,
     .ofs_x = 1,
     .ofs_y = 0}};

/*---------------------
 *  CHARACTER MAPPING
 *--------------------*/

static const uint16_t unicode_list_1[] = {0x0, 0x32, 0x1f62, 0x2589, 0x258b};

/*Collect the unicode lists and glyph_id offsets*/
static const lv_font_fmt_txt_cmap_t cmaps[] = {
    {.range_start = 32,
     .range_length = 95,
     .glyph_id_start = 1,
     .unicode_list = NULL,
     .glyph_id_ofs_list = NULL,
     .list_length = 0,
     .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_TINY},
    {.range_start = 183,
     .range_length = 9612,
     .glyph_id_start = 96,
     .unicode_list = unicode_list_1,
     .glyph_id_ofs_list = NULL,
     .list_length = 5,
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
const lv_font_t pokedex_text = {
#else
lv_font_t pokedex_text = {
#endif
    .get_glyph_dsc =
        lv_font_get_glyph_dsc_fmt_txt, /*Function pointer to get glyph's data*/
    .get_glyph_bitmap =
        lv_font_get_bitmap_fmt_txt, /*Function pointer to get glyph's bitmap*/
    .line_height = 17, /*The maximum line height required by the font*/
    .base_line = 4,    /*Baseline measured from the bottom of the line*/
#if !(LVGL_VERSION_MAJOR == 6 && LVGL_VERSION_MINOR == 0)
    .subpx = LV_FONT_SUBPX_NONE,
#endif
#if LV_VERSION_CHECK(7, 4, 0) || LVGL_VERSION_MAJOR >= 8
    .underline_position = -1,
    .underline_thickness = 1,
#endif
    .dsc = &font_dsc, /*The custom font data. Will be accessed by
                         `get_glyph_bitmap/dsc` */
#if LV_VERSION_CHECK(8, 2, 0) || LVGL_VERSION_MAJOR >= 9
    .fallback = NULL,
#endif
    .user_data = NULL,
};

#endif /*#if POKEDEX_TEXT*/
