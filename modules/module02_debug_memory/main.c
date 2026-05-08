#include <stdio.h>
#include "memory_lab.h"

int main(void)
{
    char *name = NULL;
    char *message = NULL;
    int *numbers = NULL;

    printf("=== RLX Memory Lab ===\\n");

    name = safe_strdup("RlxTechs");
    debug_print_ptr("name", name);

    message = safe_join("Hello ", name);
    debug_print_ptr("message", message);

    numbers = create_int_array(5, 0);
    debug_print_ptr("numbers", numbers);

    if (numbers != NULL) {
        fill_sequence(numbers, 5);
        printf("array_sum = %d\\n", array_sum(numbers, 5));
    }

    if (message != NULL) {
        printf("message = %s\\n", message);
        printf("message length = %d\\n", my_strlen_safe(message));
    }

    SAFE_FREE(numbers);
    SAFE_FREE(message);
    SAFE_FREE(name);

    debug_print_ptr("numbers after free", numbers);
    debug_print_ptr("message after free", message);
    debug_print_ptr("name after free", name);

    return 0;
}
