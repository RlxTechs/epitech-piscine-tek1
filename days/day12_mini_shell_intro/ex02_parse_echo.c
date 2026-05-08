#include <stdio.h>

char *skip_spaces(char *str)
{
    int i = 0;

    while (str[i] == ' ' || str[i] == '\t') {
        i = i + 1;
    }
    return str + i;
}

int main(void)
{
    char line[] = "echo    hello RLX";
    char *text = line + 4;

    text = skip_spaces(text);
    printf("%s\\n", text);
    return 0;
}
