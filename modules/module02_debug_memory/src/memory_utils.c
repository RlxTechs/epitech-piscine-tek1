#include <stdio.h>
#include <stdlib.h>
#include "memory_lab.h"

void *safe_malloc(size_t size)
{
    void *ptr = NULL;

    if (size == 0) {
        return NULL;
    }
    ptr = malloc(size);
    if (ptr == NULL) {
        printf("safe_malloc: allocation failed for %zu bytes\\n", size);
        return NULL;
    }
    return ptr;
}

int is_null(void *ptr)
{
    if (ptr == NULL) {
        return 1;
    }
    return 0;
}
