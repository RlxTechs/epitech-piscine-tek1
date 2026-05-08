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

void sort_array(int *array, int size)
{
    int i = 0;
    int j = 0;
    int temp = 0;

    while (i < size - 1) {
        j = 0;
        while (j < size - 1 - i) {
            if (array[j] > array[j + 1]) {
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
            j = j + 1;
        }
        i = i + 1;
    }
}

int main(void)
{
    int numbers[] = {9, 4, 1, 7, 3, 8};

    print_array(numbers, 6);
    sort_array(numbers, 6);
    print_array(numbers, 6);
    return 0;
}
