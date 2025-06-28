#include "lib.h"

int main(int argc, char** argv) {
  uint32_t value = 5;

  pretty_print_binary(value);

  printf("Setting Bit 2...\n");
  value = bit_set(value, 2);
  pretty_print_binary(value);

  printf("Clearing Bit 0...\n");
  value = bit_unset(value, 0);
  pretty_print_binary(value);

  printf("Toggling bit 3...\n");
  value = bit_toggle(value, 3);
  pretty_print_binary(value);
}
