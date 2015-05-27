#include <stddef.h>
#include <stdint.h>

#include "vga.h"

size_t terminal_row;
size_t terminal_column;
uint8_t terminal_colour;
uint16_t *terminal_buffer;

void term_putentryat(char c, uint8_t colour, size_t x, size_t y);
void term_putchar(char c);
void term_init(void);
void term_write(const char *data, size_t size);
void term_print(const char *str);
size_t strlen(const char *str);

void term_init(void) {
  terminal_row = 0;
  terminal_column = 0;
  terminal_colour = vga_make_colour(VGA_LIGHT_GREY, VGA_BLACK);
  terminal_buffer = VGA_MEMORY_BASE;
  for (size_t y = 0; y < VGA_HEIGHT; ++y) {
    for (size_t x = 0; x < VGA_WIDTH; ++x) {
      term_putentryat(' ', terminal_colour, x, y);
    }
  }
  vga_set_cursor(0, 0);
}

void term_putentryat(char c, uint8_t colour, size_t x, size_t y) {
  const size_t index = y * VGA_WIDTH + x;
  terminal_buffer[index] = vga_make_cell(c, colour);
}

void term_putchar(char c) {
  if (c == '\n') {
    terminal_row++;
    terminal_column = 0;
  } else if (c == '\t') {
    terminal_column = (terminal_column + 8) & ~(8 - 1);
  } else {
    term_putentryat(c, terminal_colour, terminal_column, terminal_row);
    terminal_column++;
  }
  if (terminal_column >= VGA_WIDTH) {
    terminal_column = 0;
    terminal_row++;
  }
  if (terminal_row >= VGA_HEIGHT) {
    terminal_row = 0; // TODO Replace with code to shift all lines up (will lose top)
  }
}

void term_write(const char *data, size_t size) {
  for (size_t i = 0; i < size; ++i) {
    term_putchar(data[i]);
    vga_set_cursor(terminal_column, terminal_row);
  }
}

void term_print(const char *str) {
  term_write(str, strlen(str));
}

size_t strlen(const char *str) {
  size_t result = 0;
  while (str[++result]) ;
  return result;
}
