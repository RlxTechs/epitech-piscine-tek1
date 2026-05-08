#include <stdio.h>

int my_strlen(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i = i + 1;
    }
    return i;
}

int contains(char *text, char *pattern)
{
    int i = 0;
    int j = 0;

    if (pattern[0] == '\0') {
        return 1;
    }
    while (text[i] != '\0') {
        j = 0;
        while (text[i + j] != '\0' && pattern[j] != '\0' && text[i + j] == pattern[j]) {
            j = j + 1;
        }
        if (pattern[j] == '\0') {
            return 1;
        }
        i = i + 1;
    }
    return 0;
}

int main(void)
{
    printf("%d\n", contains("Hello RlxTechs", "Rlx"));
    printf("%d\n", contains("Hello RlxTechs", "Python"));
    return 0;
}
