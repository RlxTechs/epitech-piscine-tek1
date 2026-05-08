#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}

void my_putstr(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        my_putchar(str[i]);
        i = i + 1;
    }
}

int main(void)
{
    my_putstr("RlxTechs\n");
    my_putstr("Piscine TEK1\n");
    return 0;
}
