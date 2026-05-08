#include "my_printf.h"

static int handle_format(char specifier, va_list args)
{
    if (specifier == 'c') {
        return my_putchar((char)va_arg(args, int));
    }
    if (specifier == 's') {
        return my_putstr(va_arg(args, char *));
    }
    if (specifier == 'd' || specifier == 'i') {
        return my_put_nbr(va_arg(args, int));
    }
    if (specifier == '%') {
        return my_putchar('%');
    }
    my_putchar('%');
    my_putchar(specifier);
    return 2;
}

int my_printf(const char *format, ...)
{
    va_list args;
    int i = 0;
    int count = 0;

    if (format == 0) {
        return -1;
    }
    va_start(args, format);
    while (format[i] != '\0') {
        if (format[i] == '%' && format[i + 1] != '\0') {
            count = count + handle_format(format[i + 1], args);
            i = i + 2;
        } else {
            count = count + my_putchar(format[i]);
            i = i + 1;
        }
    }
    va_end(args);
    return count;
}
