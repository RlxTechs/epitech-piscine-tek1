#include <stdio.h>

int is_prime(int nb)
{
    int i = 2;

    if (nb < 2) {
        return 0;
    }
    while (i * i <= nb) {
        if (nb % i == 0) {
            return 0;
        }
        i = i + 1;
    }
    return 1;
}

int main(void)
{
    printf("2 prime? %d\n", is_prime(2));
    printf("17 prime? %d\n", is_prime(17));
    printf("21 prime? %d\n", is_prime(21));
    printf("1 prime? %d\n", is_prime(1));
    return 0;
}
