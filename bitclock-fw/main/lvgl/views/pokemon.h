#include <stdbool.h>
#include <stdint.h>
#include <time.h>

typedef struct {
  time_t curtime;
  bool hour24;
  uint16_t pokemon_index; // Index into pokemon_entries
} lv_helper_view_mode_pokemon_data_t;
extern lv_helper_view_mode_pokemon_data_t lv_helper_view_mode_pokemon_data;

void lv_helper_pokemon_create();
void lv_helper_pokemon_update(lv_helper_view_mode_pokemon_data_t *data);
