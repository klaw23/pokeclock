//
// "Pokémon of the day" face
//
// +----------------------------------------------------------+
// | #025 Pikachu                          Mon · Sep 7 · 12:34 |
// |            |  Electric                                    |
// |   sprite   |  0.4 m · 6.0 kg                              |
// |   (2x)     |  When several of these POKéMON gather,       |
// |            |  their electricity could build and cause ... |
// |-----------------------------------------------------------|
// |  HP    ATK    DEF    SP.A    SP.D    SPD                  |
// |  35    55     40     50      50      90                   |
// +----------------------------------------------------------+
//

#include "pokemon.h"

#include "lvgl/lvgl.h"
#include "lvgl/utils.h"
#include "pokemon/pokemon_data.h"
#include <stdio.h>
#include <time.h>

LV_FONT_DECLARE(pokedex_name);
LV_FONT_DECLARE(pokedex_text);

lv_helper_view_mode_pokemon_data_t lv_helper_view_mode_pokemon_data;

// Layout for the 264x176 e-ink display
#define SCREEN_WIDTH 264
#define MARGIN 4
#define HEADER_HEIGHT 26
#define SPRITE_COLUMN_WIDTH 112
#define SPRITE_COLUMN_HEIGHT 112
#define INFO_X (SPRITE_COLUMN_WIDTH + MARGIN)
#define INFO_WIDTH (SCREEN_WIDTH - INFO_X - MARGIN)
#define INFO_LINE_SPACE -3
#define SUMMARY_HEIGHT 28
#define ENTRY_Y (HEADER_HEIGHT + SUMMARY_HEIGHT + 4)
#define STATS_Y 146
#define ENTRY_HEIGHT (STATS_Y - 6 - ENTRY_Y)
#define STAT_COUNT 6
#define STAT_WIDTH (SCREEN_WIDTH / STAT_COUNT)

static const char *stat_names[STAT_COUNT] = {"HP",   "ATK",  "DEF",
                                             "SP.A", "SP.D", "SPD"};

static lv_obj_t *name_label;
static lv_obj_t *datetime_label;
static lv_obj_t *sprite_img;
static lv_obj_t *summary_label;
static lv_obj_t *entry_label;
static lv_obj_t *stat_labels[STAT_COUNT];

static uint16_t active_index = UINT16_MAX;

static lv_obj_t *create_label(lv_obj_t *parent, const lv_font_t *font) {
  lv_obj_t *label = lv_label_create(parent);
  lv_obj_set_style_text_font(label, font, LV_PART_MAIN);
  return label;
}

void lv_helper_pokemon_create() {
  lv_obj_t *screen = lv_screen_active();
  active_index = UINT16_MAX;

  // Header: name on the left, date and time on the right
  name_label = create_label(screen, &pokedex_name);
  lv_obj_align(name_label, LV_ALIGN_TOP_LEFT, MARGIN, 2);

  datetime_label = create_label(screen, &pokedex_text);
  lv_obj_align(datetime_label, LV_ALIGN_TOP_RIGHT, -MARGIN, 8);

  // Left column: sprite, positioned once the Pokémon is known
  sprite_img = lv_image_create(screen);
  lv_image_set_antialias(sprite_img, false);

  // Right column: type + size, then the Pokédex entry
  summary_label = create_label(screen, &pokedex_text);
  lv_obj_set_pos(summary_label, INFO_X, HEADER_HEIGHT);
  lv_obj_set_size(summary_label, INFO_WIDTH, SUMMARY_HEIGHT);
  lv_obj_set_style_text_line_space(summary_label, INFO_LINE_SPACE,
                                   LV_PART_MAIN);

  entry_label = create_label(screen, &pokedex_text);
  lv_obj_set_pos(entry_label, INFO_X, ENTRY_Y);
  lv_obj_set_size(entry_label, INFO_WIDTH, ENTRY_HEIGHT);
  lv_obj_set_style_text_line_space(entry_label, INFO_LINE_SPACE, LV_PART_MAIN);
  lv_label_set_long_mode(entry_label, LV_LABEL_LONG_DOT);

  // Divider above the stats row
  lv_obj_t *divider = lv_obj_create(screen);
  lv_obj_remove_style_all(divider);
  lv_obj_set_pos(divider, MARGIN, STATS_Y - 4);
  lv_obj_set_size(divider, SCREEN_WIDTH - 2 * MARGIN, 1);
  lv_obj_set_style_bg_color(divider, lv_color_black(), LV_PART_MAIN);
  lv_obj_set_style_bg_opa(divider, LV_OPA_COVER, LV_PART_MAIN);

  // Stats row: label above value, one tile per stat
  for (int i = 0; i < STAT_COUNT; i++) {
    stat_labels[i] = create_label(screen, &pokedex_text);
    lv_obj_set_pos(stat_labels[i], i * STAT_WIDTH, STATS_Y);
    lv_obj_set_width(stat_labels[i], STAT_WIDTH);
    lv_obj_set_style_text_align(stat_labels[i], LV_TEXT_ALIGN_CENTER,
                                LV_PART_MAIN);
    lv_obj_set_style_text_line_space(stat_labels[i], -4, LV_PART_MAIN);
  }
}

static void set_pokemon(const pokemon_entry_t *pokemon) {
  static char buf[64];

  snprintf(buf, sizeof(buf), "#%03u %s", (unsigned)pokemon->number,
           pokemon->name);
  lv_label_set_text(name_label, buf);

  snprintf(buf, sizeof(buf), "%s\n%u.%u m · %u.%u kg", pokemon->types,
           pokemon->height_dm / 10, pokemon->height_dm % 10,
           pokemon->weight_hg / 10, pokemon->weight_hg % 10);
  lv_label_set_text(summary_label, buf);

  lv_label_set_text(entry_label, pokemon->entry);

  // Center the sprite in its column
  lv_image_set_src(sprite_img, pokemon->sprite);
  lv_obj_set_pos(
      sprite_img,
      (SPRITE_COLUMN_WIDTH - (int32_t)pokemon->sprite->header.w) / 2,
      HEADER_HEIGHT +
          (SPRITE_COLUMN_HEIGHT - (int32_t)pokemon->sprite->header.h) / 2);

  uint8_t stat_values[STAT_COUNT] = {pokemon->hp,
                                     pokemon->attack,
                                     pokemon->defense,
                                     pokemon->special_attack,
                                     pokemon->special_defense,
                                     pokemon->speed};
  for (int i = 0; i < STAT_COUNT; i++) {
    snprintf(buf, sizeof(buf), "%s\n%u", stat_names[i], stat_values[i]);
    lv_label_set_text(stat_labels[i], buf);
  }
}

void lv_helper_pokemon_update(lv_helper_view_mode_pokemon_data_t *data) {
  static struct tm timeinfo;
  static char datetime_str[32];
  static char weekday_str[4];
  static char month_str[4];

  localtime_r(&data->curtime, &timeinfo);
  strftime(weekday_str, sizeof(weekday_str), "%a", &timeinfo);
  strftime(month_str, sizeof(month_str), "%b", &timeinfo);
  unsigned hour = timeinfo.tm_hour;
  if (!data->hour24) {
    hour = hour % 12 == 0 ? 12 : hour % 12;
  }
  snprintf(datetime_str, sizeof(datetime_str), "%s · %s %u · %u:%02u",
           weekday_str, month_str, timeinfo.tm_mday, hour, timeinfo.tm_min);
  set_text_if_changed(datetime_label, datetime_str);

  uint16_t index = data->pokemon_index;
  if (index >= pokemon_entries_count) {
    index = 0;
  }
  // Only rebuild the Pokémon widgets when the day rolls over to avoid
  // needless e-ink refreshes.
  if (index != active_index) {
    set_pokemon(&pokemon_entries[index]);
    active_index = index;
  }
}
