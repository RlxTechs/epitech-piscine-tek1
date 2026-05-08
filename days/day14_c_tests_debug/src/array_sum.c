#include "project.h"

int array_sum(int *array, int size)
{
    int i = 0;
    int sum = 0;

    if (array == 0 || size <= 0) {
        return 0;
    }
    while (i < size) {
        sum = sum + array[i];
        i = i + 1;
    }
    return sum;
}
