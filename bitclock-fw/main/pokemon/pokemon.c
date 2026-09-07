#include "pokemon.h"

uint16_t pokemon_index_for_day(const struct tm *timeinfo) {
  // Hash the calendar day so the pick is stable across reboots and doesn't
  // need any persisted state, while still jumping around the Pokédex.
  uint32_t key =
      (uint32_t)(timeinfo->tm_year + 1900) * 366u + (uint32_t)timeinfo->tm_yday;
  uint32_t hash = key * 0x9E3779B1u;
  hash ^= hash >> 16;
  hash *= 0x85EBCA6Bu;
  hash ^= hash >> 13;
  hash *= 0xC2B2AE35u;
  hash ^= hash >> 16;
  return (uint16_t)(hash % pokemon_entries_count);
}

const pokemon_entry_t *pokemon_of_the_day(const struct tm *timeinfo) {
  return &pokemon_entries[pokemon_index_for_day(timeinfo)];
}
