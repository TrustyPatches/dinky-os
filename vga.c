#include "port-io.h"
#include "vga.h"

uint8_t make_colour(enum vga_colour fg, enum vga_colour bg) {
  return bg << 4 | fg;
}

uint16_t make_vga_cell(char c, uint8_t colour) {
  uint16_t char16 = c;
  uint16_t colour16 = colour;
  return colour16 << 8 | char16;
}

void vga_move_cursor(unsigned short pos) {
  outb(VGA_COMMAND_PORT, VGA_HIGH_BYTE_COMMAND);
  outb(VGA_DATA_PORT, ((pos >> 8) & 0x00FF));
  outb(VGA_COMMAND_PORT, VGA_LOW_BYTE_COMMAND);
  outb(VGA_DATA_PORT, pos & 0x00FF);
}

