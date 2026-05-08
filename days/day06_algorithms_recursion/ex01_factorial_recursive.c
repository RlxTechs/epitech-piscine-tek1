#include <stdio.h>

int factorial_recursive(int n)
{
    if (n < 0) {
        return -1;
    }
    if (n == 0 || n == 1) {
        return 1;
    }
    return n * factorial_recursive(n - 1);
}

int main(void)
{
    printf("6! = %d\n", factorial_recursive(6));
    printf("1! = %d\n", factorial_recursive(1));
    printf("-2! = %d\n", factorial_recursive(-2));
    return 0;
}
