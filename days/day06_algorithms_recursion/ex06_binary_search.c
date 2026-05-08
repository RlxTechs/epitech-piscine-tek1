#include <stdio.h>

int binary_search(int *array, int size, int target)
{
    int left = 0;
    int right = size - 1;
    int middle = 0;

    while (left <= right) {
        middle = left + (right - left) / 2;
        if (array[middle] == target) {
            return middle;
        }
        if (array[middle] < target) {
            left = middle + 1;
        } else {
            right = middle - 1;
        }
    }
    return -1;
}

int main(void)
{
    int numbers[] = {1, 3, 5, 7, 9, 11, 15};

    printf("index of 7 = %d\n", binary_search(numbers, 7, 7));
    printf("index of 15 = %d\n", binary_search(numbers, 7, 15));
    printf("index of 4 = %d\n", binary_search(numbers, 7, 4));
    return 0;
}
