#include <stdio.h>
#include <stdlib.h>

int *create_array(int size)
{
    int *array = malloc(sizeof(int) * size);
    int i = 0;

    if (array == NULL) {
        return NULL;
    }
    while (i < size) {
        array[i] = i * 10;
        i = i + 1;
    }
    return array;
}

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

int main(void)
{
    int size = 6;
    int *array = create_array(size);

    if (array == NULL) {
        return 1;
    }
    print_array(array, size);
    free(array);
    return 0;
}
