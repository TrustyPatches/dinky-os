#include "port-io.h"
#include "vga.h"

void fb_move_cursor(unsigned short pos) {
  outb(VGA_COMMAND_PORT, VGA_HIGH_BYTE_COMMAND);
  outb(VGA_DATA_PORT, ((pos >> 8) & 0x00FF));
  outb(VGA_COMMAND_PORT, VGA_LOW_BYTE_COMMAND);
  outb(VGA_DATA_PORT, pos & 0x00FF);
}

int fb_write(char *buf, unsigned int len) {
  unsigned int i;
  for (i = 0; i < len; ++i) {
  }
  fb_move_cursor((short)len);
  return len;
}
