#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}

int main(void)
{
    char letter = 'R';

    my_putchar(letter);
    my_putchar('\n');
    return 0;
}
