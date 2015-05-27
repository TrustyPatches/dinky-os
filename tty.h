#ifndef _KERNEL_TTY_H_
#define _KERNEL_TTY_H

#include <stddef.h>

void term_init(void);
void term_putchar(char c);
void term_write(const char *data, size_t size);
void term_print(const char *str);

#endif
