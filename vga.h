#ifndef _KERNEL_VGA_H
#define _KERNEL_VGA_H

#include <stdint.h>
#include <stddef.h>

#define VGA_COMMAND_PORT  0x3D4
#define VGA_DATA_PORT     0x3D5

#define VGA_HIGH_BYTE_COMMAND 14
#define VGA_LOW_BYTE_COMMAND  15

static const size_t VGA_WIDTH  = 80;
static const size_t VGA_HEIGHT = 25;

static uint16_t const *VGA_MEMORY_BASE = (uint16_t *)0x000B8000;

enum vga_colour {
  VGA_BLACK = 0,
  VGA_BLUE = 1,
  VGA_GREEN = 2,
  VGA_CYAN = 3,
  VGA_RED = 4,
  VGA_MAGENTA = 5,
  VGA_BROWN = 6,
  VGA_LIGHT_GREY = 7,
  VGA_DARK_GREY = 8,
  VGA_LIGHT_BLUE = 9,
  VGA_LIGHT_GREEN = 10,
  VGA_LIGHT_CYAN = 11,
  VGA_LIGHT_RED = 12,
  VGA_LIGHT_MAGENTA = 13,
  VGA_LIGHT_BROWN = 14,
  VG_WHITE = 15
};

uint8_t vga_make_colour(enum vga_colour fg, enum vga_colour bg);
uint16_t vga_make_cell(char c, uint8_t colour);
void vga_move_cursor(unsigned short pos);

#endif
