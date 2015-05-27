#include "tty.h"

void kmain() {
  term_init();
  term_putchar('H');
  term_putchar('e');
  term_putchar('l');
  term_putchar('l');
  term_putchar('o');
  term_putchar('!');
}
