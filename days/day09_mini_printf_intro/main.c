#include <stdio.h>
#include "my_printf.h"

int main(void)
{
    int count = 0;

    my_printf("=== Mini printf intro ===\n");
    my_printf("Char: %c\n", 'R');
    my_printf("String: %s\n", "RlxTechs");
    my_printf("Number positive: %d\n", 2026);
    my_printf("Number negative: %i\n", -42);
    my_printf("Percent: %%\n");
    my_printf("Multiple: %s %c %d %%\n", "TEK", '1', 100);
    count = my_printf("Count this line: %s %d\n", "score", 123);
    printf("my_printf returned: %d\n", count);
    return 0;
}
