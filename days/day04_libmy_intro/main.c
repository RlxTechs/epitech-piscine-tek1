#include "my.h"

int main(void)
{
    char buffer[100];

    my_putstr("=== Test Libmy ===\n");
    my_putstr("Message: ");
    my_putstr("Hello RlxTechs\n");

    my_putstr("Length of RlxTechs: ");
    my_put_nbr(my_strlen("RlxTechs"));
    my_putchar('\n');

    my_strcpy(buffer, "Copied text from libmy");
    my_putstr("Copy result: ");
    my_putstr(buffer);
    my_putchar('\n');

    my_putstr("Compare abc / abc: ");
    my_put_nbr(my_strcmp("abc", "abc"));
    my_putchar('\n');

    my_putstr("Compare abc / abd: ");
    my_put_nbr(my_strcmp("abc", "abd"));
    my_putchar('\n');

    my_putstr("Number test: ");
    my_put_nbr(-2026);
    my_putchar('\n');

    return 0;
}
