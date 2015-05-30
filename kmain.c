#include "tty.h"
#include "vga.h"

void kinit() {
  term_init();
}

void kmain() {
  term_init();
  term_print("\n\t\t\t     ====================");
  term_print("\n\t\t\t     Welcome to Dinky-OS!");
  term_print("\n\t\t\t     ====================\n\n");
  term_print("Under construction...");

  //asm volatile ("int $0x00");
  //asm volatile ("int $0x0A");
}
