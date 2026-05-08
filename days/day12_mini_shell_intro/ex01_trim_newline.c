#include <stdio.h>

int my_strlen(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i = i + 1;
    }
    return i;
}

void trim_newline(char *str)
{
    int len = my_strlen(str);

    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }
}

int main(void)
{
    char text[] = "hello\\n";

    trim_newline(text);
    printf("[%s]\\n", text);
    return 0;
}
