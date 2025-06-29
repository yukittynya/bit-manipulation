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

//Range
char* extract_range(uint32_t value, uint8_t start, uint8_t num_bits); 
uint32_t bit_extract(uint32_t value, uint8_t start, uint8_t num_bits);
void insert_bits(uint32_t* value, uint32_t src, uint8_t start, uint8_t num_bits);

//Printing and to strings
char* binary_to_string(uint32_t value); 

void print_binary(uint32_t value); 
void pretty_print_binary(uint32_t value); 

#endif // !LIB_H
