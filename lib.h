#ifndef LIB_H
#define LIB_H

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

//Basic 
bool bit_is_set(uint32_t value, uint8_t bit_position); 
void bit_set(uint32_t* value, uint8_t bit_position); 
void bit_unset(uint32_t* value, uint8_t bit_position); 
void bit_toggle(uint32_t* value, uint8_t bit_position);

//Counting and searching
uint8_t toggled_bit_count(uint32_t value);
int8_t first_toggled_bit(uint32_t value);
int8_t last_toggled_bit(uint32_t value);

//Range
char* extract_range(uint32_t value, uint8_t start, uint8_t num_bits); 
uint32_t bit_extract(uint32_t value, uint8_t start, uint8_t num_bits);
void insert_bits(uint32_t* value, uint32_t src, uint8_t start, uint8_t num_bits);

//Util functions?? dont know what to know name int
void swap_vars(uint32_t* a, uint32_t* b); 
bool is_even(uint32_t* value);
bool is_odd(uint32_t* value);

//Printing and to strings
char* binary_to_string(uint32_t value); 

void print_binary(uint32_t value); 
void pretty_print_binary(uint32_t value); 

#endif // !LIB_H
