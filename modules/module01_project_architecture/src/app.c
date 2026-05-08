#include <stdio.h>
#include <stdlib.h>
#include "app.h"

void app_print_banner(void)
{
    printf("=== RLX C Project Architecture Module ===\\n");
    printf("Usage:\\n");
    printf("  app_architecture add 10 5\\n");
    printf("  app_architecture mul 10 5\\n");
}

int app_run(int argc, char **argv)
{
    int a = 0;
    int b = 0;

    if (argc == 1) {
        app_print_banner();
        return 0;
    }
    if (argc != 4) {
        printf("Invalid usage.\\n");
        app_print_banner();
        return 1;
    }
    a = atoi(argv[2]);
    b = atoi(argv[3]);
    if (my_str_equals(argv[1], "add") == 1) {
        printf("%d\\n", add_numbers(a, b));
        return 0;
    }
    if (my_str_equals(argv[1], "mul") == 1) {
        printf("%d\\n", multiply_numbers(a, b));
        return 0;
    }
    printf("Unknown command: %s\\n", argv[1]);
    return 1;
}
