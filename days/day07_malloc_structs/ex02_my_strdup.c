#include <stdio.h>
#include <stdlib.h>

int my_strlen(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i = i + 1;
    }
    return i;
}

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

char *my_strdup(char *src)
{
    int len = my_strlen(src);
    char *copy = malloc(sizeof(char) * (len + 1));

    if (copy == NULL) {
        return NULL;
    }
    my_strcpy(copy, src);
    return copy;
}

int main(void)
{
    char *copy = my_strdup("RlxTechs malloc training");

    if (copy == NULL) {
        return 1;
    }
    printf("%s\n", copy);
    free(copy);
    return 0;
}
