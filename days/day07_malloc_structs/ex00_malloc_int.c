#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *number = malloc(sizeof(int));

    if (number == NULL) {
        return 1;
    }
    *number = 42;
    printf("number = %d\n", *number);
    free(number);
    return 0;
}
