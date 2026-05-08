#include <stdio.h>

char *my_strcpy(char *dest, char *src)
{
    int i = 0;

    while (src[i] != '\0') {
        dest[i] = src[i];
        i = i + 1;
    }
    dest[i] = '\0';
    return dest;
}

int main(void)
{
    char buffer[100];

    my_strcpy(buffer, "Hello RlxTechs");
    printf("%s\n", buffer);
    return 0;
}
