#include <stdio.h>

int my_power(int nb, int power)
{
    if (power < 0) {
        return 0;
    }
    if (power == 0) {
        return 1;
    }
    return nb * my_power(nb, power - 1);
}

int main(void)
{
    printf("2^8 = %d\n", my_power(2, 8));
    printf("5^0 = %d\n", my_power(5, 0));
    printf("3^4 = %d\n", my_power(3, 4));
    return 0;
}
