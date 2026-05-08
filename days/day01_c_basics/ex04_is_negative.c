#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}

void is_negative(int number)
{
    if (number < 0) {
        my_putchar('N');
    } else {
        my_putchar('P');
    }
    my_putchar('\n');
}

int main(void)
{
    is_negative(-7);
    is_negative(0);
    is_negative(12);
    return 0;
}
