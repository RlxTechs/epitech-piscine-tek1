#include "my_printf.h"

int my_putstr(char *str)
{
    int i = 0;
    int count = 0;

    if (str == 0) {
        return my_putstr("(null)");
    }
    while (str[i] != '\0') {
        count = count + my_putchar(str[i]);
        i = i + 1;
    }
    return count;
}
