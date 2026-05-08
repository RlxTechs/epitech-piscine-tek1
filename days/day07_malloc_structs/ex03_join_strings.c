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

char *join_strings(char *a, char *b)
{
    int len_a = my_strlen(a);
    int len_b = my_strlen(b);
    char *result = malloc(sizeof(char) * (len_a + len_b + 1));
    int i = 0;
    int j = 0;

    if (result == NULL) {
        return NULL;
    }
    while (a[i] != '\0') {
        result[i] = a[i];
        i = i + 1;
    }
    while (b[j] != '\0') {
        result[i + j] = b[j];
        j = j + 1;
    }
    result[i + j] = '\0';
    return result;
}

int main(void)
{
    char *text = join_strings("Hello ", "RlxTechs");

    if (text == NULL) {
        return 1;
    }
    printf("%s\n", text);
    free(text);
    return 0;
}
