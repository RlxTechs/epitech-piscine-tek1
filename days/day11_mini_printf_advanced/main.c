#include <stdio.h>
#include "my_printf.h"

int main(void)
{
    int count = 0;

    my_printf("=== Mini printf advanced ===\n");
    my_printf("Char: %c\n", 'R');
    my_printf("String: %s\n", "RlxTechs");
    my_printf("Signed d: %d\n", -2026);
    my_printf("Signed i: %i\n", 2026);
    my_printf("Unsigned: %u\n", 4294967295u);
    my_printf("Hex lower 255: %x\n", 255u);
    my_printf("Hex upper 255: %X\n", 255u);
    my_printf("Octal 255: %o\n", 255u);
    my_printf("Binary 10: %b\n", 10u);
    my_printf("Percent: %%\n");
    my_printf("Mixed: %s %d %u %x %X %o %b %%\n", "RLX", -42, 42u, 255u, 255u, 255u, 10u);
    count = my_printf("Count check: %s %d %x\n", "score", 123, 255u);
    printf("my_printf returned: %d\n", count);
    return 0;
}
