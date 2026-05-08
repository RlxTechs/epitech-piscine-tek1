#include "my_printf.h"

int my_put_nbr(int nb)
{
    long number = nb;
    int count = 0;

    if (number < 0) {
        count = count + my_putchar('-');
        number = number * -1;
    }
    if (number >= 10) {
        count = count + my_put_nbr(number / 10);
    }
    count = count + my_putchar((number % 10) + '0');
    return count;
}
