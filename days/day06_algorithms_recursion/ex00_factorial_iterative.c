#include <stdio.h>

int factorial_iterative(int n)
{
    int result = 1;
    int i = 1;

    if (n < 0) {
        return -1;
    }
    while (i <= n) {
        result = result * i;
        i = i + 1;
    }
    return result;
}

int main(void)
{
    printf("5! = %d\n", factorial_iterative(5));
    printf("0! = %d\n", factorial_iterative(0));
    printf("-3! = %d\n", factorial_iterative(-3));
    return 0;
}
