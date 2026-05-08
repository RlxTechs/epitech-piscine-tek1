#include <stdio.h>

void find_min_max(int *array, int size, int *min, int *max)
{
    int i = 1;

    *min = array[0];
    *max = array[0];

    while (i < size) {
        if (array[i] < *min) {
            *min = array[i];
        }
        if (array[i] > *max) {
            *max = array[i];
        }
        i = i + 1;
    }
}

int main(void)
{
    int numbers[] = {12, 4, 99, -3, 42};
    int min = 0;
    int max = 0;

    find_min_max(numbers, 5, &min, &max);
    printf("min = %d\n", min);
    printf("max = %d\n", max);
    return 0;
}
