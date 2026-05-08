#include <stdio.h>

int absolute(int nb)
{
    if (nb < 0) {
        return -nb;
    }
    return nb;
}

int gcd(int a, int b)
{
    int temp = 0;

    a = absolute(a);
    b = absolute(b);
    while (b != 0) {
        temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main(void)
{
    printf("gcd(48, 18) = %d\n", gcd(48, 18));
    printf("gcd(100, 25) = %d\n", gcd(100, 25));
    printf("gcd(-42, 14) = %d\n", gcd(-42, 14));
    return 0;
}
