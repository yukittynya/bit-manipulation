#include "lib.h"
#include <stdint.h>

//Basic
inline bool bit_is_set(uint32_t value, uint8_t bit_position) {
  return (value & (1u << bit_position)) != 0;
}

inline void bit_set(uint32_t* value, uint8_t bit_position) {
    *value |= (1u << bit_position);
}

inline void bit_unset(uint32_t* value, uint8_t bit_position) {
    *value &= ~(1u << bit_position);
}

inline void bit_toggle(uint32_t* value, uint8_t bit_position) {
  *value ^= (1u << bit_position); 
}

//Range
char* extract_range(uint32_t value, uint8_t start, uint8_t num_bits) {
  char* result = (char*) malloc(num_bits + 1);

  uint32_t mask = ((1u << num_bits) - 1) << start;
  uint32_t desired_range = (value & mask) >> start;

  for (int i = 0; i < num_bits; i++) {
    result[num_bits - i - 1] = (bit_is_set(desired_range, i)) ? '1' : '0'; 
  }

  result[num_bits] = '\0';

  return result;
}

//Printing and to strings
char* binary_to_string(uint32_t value) {
  const size_t size = sizeof(value) * 8;

  char* result = (char*) malloc(size + 1);

  for (int i = 0; i < size; i++) {
    result[i] = bit_is_set(value, size - i - 1) ? '1' : '0';
  }

  result[size] = '\0';

  return result;
} 

void print_binary(uint32_t value) {
  const size_t size = sizeof(uint32_t) * 8;

  for (int i = 0; i < size; i++) {
    bit_is_set(value, size - i - 1) ? printf("%c", '1') : printf("%c", '0');
  }
}

void pretty_print_binary(uint32_t value) {
  const size_t size = sizeof(uint32_t) * 8;

  for (int i = 0; i < size; i++) {
    bit_is_set(value, size - i - 1) ? printf("%c", '1') : printf("%c", '0');

    if ((i + 1) % 8 == 0) {
      printf(" ");
    }
  }


  printf("\n");
}
