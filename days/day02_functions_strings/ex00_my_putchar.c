#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}

int main(void)
{
    my_putchar('R');
    my_putchar('L');
    my_putchar('X');
    my_putchar('\n');
    return 0;
}
