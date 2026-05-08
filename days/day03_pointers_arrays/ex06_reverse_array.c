#include <stdio.h>

void print_array(int *array, int size)
{
    int i = 0;

    while (i < size) {
        printf("%d", array[i]);
        if (i + 1 < size) {
            printf(" ");
        }
        i = i + 1;
    }
    printf("\n");
}

void reverse_array(int *array, int size)
{
    int left = 0;
    int right = size - 1;
    int temp = 0;

    while (left < right) {
        temp = array[left];
        array[left] = array[right];
        array[right] = temp;
        left = left + 1;
        right = right - 1;
    }
}

int main(void)
{
    int numbers[] = {1, 2, 3, 4, 5};

    print_array(numbers, 5);
    reverse_array(numbers, 5);
    print_array(numbers, 5);
    return 0;
}
