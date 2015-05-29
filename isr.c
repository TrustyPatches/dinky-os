#include "isr.h"
#include "tty.h"

void isr_handler(registers_t regs) {
  term_print("Recieved interrupt!\n");
}

