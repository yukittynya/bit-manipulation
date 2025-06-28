#ifndef LIB_H
#define LIB_H

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

bool bit_is_set(uint32_t value, uint8_t bit_position); 
uint32_t bit_set(uint32_t value, uint8_t bit_position); 
uint32_t bit_unset(uint32_t value, uint8_t bit_position); 
uint32_t bit_toggle(uint32_t value, uint8_t bit_position);

char* binary_to_string(uint32_t value); 

void print_binary(uint32_t value); 
void pretty_print_binary(uint32_t value); 

#endif // !LIB_H
