#include <stdio.h>

void print_array(int *array, int size)
{
    int i = 0;

    while (i < size) {
        printf("%d\n", array[i]);
        i = i + 1;
    }
}

int main(void)
{
    int numbers[] = {4, 8, 15, 16, 23, 42};

    print_array(numbers, 6);
    return 0;
}
