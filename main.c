#include "lib.h"

int main(int argc, char** argv) {
  uint32_t value = 5;

  printf("Binary of %d\n", value);
  pretty_print_binary(value);

  printf("\nSetting Bit 2...\n");
  value = bit_set(value, 2);
  pretty_print_binary(value);

  printf("\nClearing Bit 0...\n");
  value = bit_unset(value, 0);
  pretty_print_binary(value);

  printf("\nToggling bit 3...\n");
  value = bit_toggle(value, 3);
  pretty_print_binary(value);

  printf("\nRange 29 - 32...\n");
  char* result = extract_range(value, 29, 32);
  printf("%s\n", result);
}
