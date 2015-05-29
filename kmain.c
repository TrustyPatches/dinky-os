#include "tty.h"
#include "vga.h"
#include "descriptor-tables.h"

void kinit() {
  descriptor_tables_init();
  term_init();
}

void kmain() {
  term_init();
  term_print("\n\t\t\t     ====================");
  term_print("\n\t\t\t     Welcome to Dinky-OS!");
  term_print("\n\t\t\t     ====================\n\n");
  term_print("Under construction...");

  //asm volatile ("int $0x03");
  //asm volatile ("int $0x0A");
}
