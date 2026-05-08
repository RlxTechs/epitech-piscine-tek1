#include <stdio.h>
#include "memory_lab.h"

void debug_print_ptr(const char *label, void *ptr)
{
    if (label == NULL) {
        label = "pointer";
    }
    if (ptr == NULL) {
        printf("[DEBUG] %s = NULL\\n", label);
    } else {
        printf("[DEBUG] %s = %p\\n", label, ptr);
    }
}
