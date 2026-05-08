#include <stdio.h>

int main(void)
{
    int number = 42;
    int *ptr = &number;

    printf("number = %d\n", number);
    printf("address of number = %p\n", (void *)&number);
    printf("ptr contains = %p\n", (void *)ptr);
    printf("value pointed by ptr = %d\n", *ptr);
    return 0;
}
