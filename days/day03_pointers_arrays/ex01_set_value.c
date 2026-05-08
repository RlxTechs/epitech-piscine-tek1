#include <stdio.h>

void set_to_100(int *number)
{
    *number = 100;
}

int main(void)
{
    int value = 10;

    printf("Before: %d\n", value);
    set_to_100(&value);
    printf("After: %d\n", value);
    return 0;
}
