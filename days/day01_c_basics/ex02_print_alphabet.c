#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}

void print_alphabet(void)
{
    char c = 'a';

    while (c <= 'z') {
        my_putchar(c);
        c = c + 1;
    }
    my_putchar('\n');
}

int main(void)
{
    print_alphabet();
    return 0;
}
