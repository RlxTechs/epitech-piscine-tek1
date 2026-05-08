#include <stdio.h>

void my_swap(int *a, int *b)
{
    int temp = *a;

    *a = *b;
    *b = temp;
}

int main(void)
{
    int x = 10;
    int y = 20;

    printf("Before: x=%d y=%d\n", x, y);
    my_swap(&x, &y);
    printf("After: x=%d y=%d\n", x, y);
    return 0;
}
