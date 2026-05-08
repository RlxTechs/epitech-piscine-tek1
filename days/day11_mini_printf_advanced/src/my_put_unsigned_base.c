#include "my_printf.h"

int my_strlen(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i = i + 1;
    }
    return i;
}

int my_put_unsigned_base(unsigned int nb, char *base)
{
    unsigned int base_len = (unsigned int)my_strlen(base);
    int count = 0;

    if (base_len < 2) {
        return 0;
    }
    if (nb >= base_len) {
        count = count + my_put_unsigned_base(nb / base_len, base);
    }
    count = count + my_putchar(base[nb % base_len]);
    return count;
}
