#include "my.h"

void my_put_nbr(int nb)
{
    long number = nb;

    if (number < 0) {
        my_putchar('-');
        number = number * -1;
    }
    if (number >= 10) {
        my_put_nbr(number / 10);
    }
    my_putchar((number % 10) + '0');
}
