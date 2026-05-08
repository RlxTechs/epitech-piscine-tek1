#ifndef MY_PRINTF_H_
#define MY_PRINTF_H_

#include <stdarg.h>

int my_putchar(char c);
int my_putstr(char *str);
int my_put_nbr(int nb);
int my_put_unsigned_base(unsigned int nb, char *base);
int my_printf(const char *format, ...);

#endif
