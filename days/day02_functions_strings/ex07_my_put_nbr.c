#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}

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

int main(void)
{
    my_put_nbr(0);
    my_putchar('\n');
    my_put_nbr(42);
    my_putchar('\n');
    my_put_nbr(-2026);
    my_putchar('\n');
    return 0;
}
