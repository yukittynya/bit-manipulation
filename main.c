#include "lib.h"
#include <stdio.h>
#include <sys/resource.h>

void print_memory_usage() {
    struct rusage usage;
    getrusage(RUSAGE_SELF, &usage);
    printf("\nPeak memory usage: %ld KB\n", usage.ru_maxrss);
}

int main(int argc, char** argv) {
  uint32_t value = 5;

  printf("Binary of %d\n", value);
  pretty_print_binary(value);

  printf("\nSetting Bit 10...\n");
  bit_set(&value, 10);
  pretty_print_binary(value);

  printf("\nClearing Bit 0...\n");
  bit_unset(&value, 0);
  pretty_print_binary(value);

  printf("\nToggling bit 3...\n");
  bit_toggle(&value, 3);
  pretty_print_binary(value);

  printf("\nRange of 4 bits starting from bit 1...\n");
  char* result = extract_range(value, 1, 4);
  printf("%s\n", result);

  printf("\nBit extract of 4 bits starting from 1...\n");
  printf("%d\n", bit_extract(value, 1, 4));

  printf("\nInserting 6 into value at 2 for 4 bits...\nBefore: ");
  pretty_print_binary(value);
  insert_bits(&value, 6, 2, 4);
  printf("Now: ");
  pretty_print_binary(value);

  printf("\nToggled bit count: %d\n", toggled_bit_count(value));
  printf("\nFirst toggled bit: %d\n", first_toggled_bit(value));
  printf("\nLast toggled bit: %d\n", last_toggled_bit(value));

  uint32_t a = 32, b = 16;
  printf("\na=%d, b=%d\n", a, b);
  swap_vars(&a, &b);
  printf("\na=%d, b=%d\n", a, b);

  print_memory_usage();
}
