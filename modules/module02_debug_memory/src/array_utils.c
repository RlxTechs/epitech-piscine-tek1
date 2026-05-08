#include "memory_lab.h"

int *create_int_array(int size, int initial_value)
{
    int *array = NULL;
    int i = 0;

    if (size <= 0) {
        return NULL;
    }
    array = safe_malloc(sizeof(int) * size);
    if (array == NULL) {
        return NULL;
    }
    while (i < size) {
        array[i] = initial_value;
        i = i + 1;
    }
    return array;
}

void fill_sequence(int *array, int size)
{
    int i = 0;

    if (array == NULL || size <= 0) {
        return;
    }
    while (i < size) {
        array[i] = i + 1;
        i = i + 1;
    }
}

int array_sum(int *array, int size)
{
    int i = 0;
    int sum = 0;

    if (array == NULL || size <= 0) {
        return 0;
    }
    while (i < size) {
        sum = sum + array[i];
        i = i + 1;
    }
    return sum;
}
