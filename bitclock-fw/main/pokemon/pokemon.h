#pragma once

#include "pokemon_data.h"
#include <stdint.h>
#include <time.h>

// Index into pokemon_entries for the given local date. The same Pokémon is
// returned for the whole day and a different, pseudo-random one the next day.
uint16_t pokemon_index_for_day(const struct tm *timeinfo);

const pokemon_entry_t *pokemon_of_the_day(const struct tm *timeinfo);
