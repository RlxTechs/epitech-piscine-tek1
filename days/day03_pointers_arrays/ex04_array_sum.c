#include <stdio.h>

int array_sum(int *array, int size)
{
    int i = 0;
    int sum = 0;

    while (i < size) {
        sum = sum + array[i];
        i = i + 1;
    }
    return sum;
}

int main(void)
{
    int numbers[] = {10, 20, 30, 40};

    printf("sum = %d\n", array_sum(numbers, 4));
    return 0;
}
