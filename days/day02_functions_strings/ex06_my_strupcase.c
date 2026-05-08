#include <stdio.h>

char *my_strupcase(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] = str[i] - 32;
        }
        i = i + 1;
    }
    return str;
}

int main(void)
{
    char text[] = "RlxTechs piscine tek1";

    my_strupcase(text);
    printf("%s\n", text);
    return 0;
}
