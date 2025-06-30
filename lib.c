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

//Counting and searching
uint8_t toggled_bit_count(uint32_t value) {
  uint8_t result = 0;

  for (uint8_t i = 0; i < (sizeof(value) * 8); i++) {
    if (bit_is_set(value, 0)) result++;

    value >>= 1;
  }

  return result;
}

int8_t first_toggled_bit(uint32_t value) {
  for (uint8_t i = 0; i < (sizeof(value) * 8); i++) {
    if (bit_is_set(value, 0)  ) return i;

    value >>= 1;
  }

  return -1;
}

int8_t last_toggled_bit(uint32_t value) {
  for (uint8_t i = (sizeof(value) * 8 - 1); i >= 0; i--) {
    if (bit_is_set(value, i)) return i;
  }

  return -1;
}

//Range
char* extract_range(uint32_t value, uint8_t start, uint8_t num_bits) {
  char* result = (char*) malloc(num_bits + 1);

  uint32_t mask = ((1u << num_bits) - 1) << start;
  uint32_t desired_range = (value & mask) >> start;

  for (uint8_t i = 0; i < num_bits; i++) {
    result[num_bits - i - 1] = (bit_is_set(desired_range, i)) ? '1' : '0'; 
  }

  result[num_bits] = '\0';

  return result;
}

uint32_t bit_extract(uint32_t value, uint8_t start, uint8_t num_bits) {
  uint32_t mask = (1u << num_bits) - 1;
  
  return (value >> start) & mask; 
}

void insert_bits(uint32_t* value, uint32_t src, uint8_t start, uint8_t num_bits) {
  uint32_t mask = (1u << num_bits) - 1; 

  *value &= ~(mask << start);        
  *value |= ((src & mask) << start);  
}

//Utility functions
inline void swap_vars(uint32_t *a, uint32_t *b) {
  *a ^= *b;
  *b ^= *a;
  *a ^= *b;
}

inline bool is_even(uint32_t* value) {
  return (*value & 1u) == 0;
}

inline bool is_odd(uint32_t* value) {
  return (*value & 1u) == 1;
}

//Printing and to strings
char* binary_to_string(uint32_t value) {
  const size_t size = sizeof(value) * 8;

  char* result = (char*) malloc(size + 1);

  for (uint8_t i = 0; i < size; i++) {
    result[i] = bit_is_set(value, size - i - 1) ? '1' : '0';
  }

  result[size] = '\0';

  return result;
} 

void print_binary(uint32_t value) {
  const size_t size = sizeof(uint32_t) * 8;

  for (uint8_t i = 0; i < size; i++) {
    bit_is_set(value, size - i - 1) ? printf("%c", '1') : printf("%c", '0');
  }
}

void pretty_print_binary(uint32_t value) {
  const size_t size = sizeof(uint32_t) * 8;

  for (uint8_t i = 0; i < size; i++) {
    bit_is_set(value, size - i - 1) ? printf("%c", '1') : printf("%c", '0');

    if ((i + 1) % 8 == 0) {
      printf(" ");
    }
  }


  printf("\n");
}
