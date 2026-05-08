#include <stdio.h>

int my_strlen(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i = i + 1;
    }
    return i;
}

int main(void)
{
    printf("%d\n", my_strlen("RlxTechs"));
    printf("%d\n", my_strlen("Piscine"));
    return 0;
}
