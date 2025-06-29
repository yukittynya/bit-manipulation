#include "lib.h"

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
}
