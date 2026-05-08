#include <stdio.h>

char lower_char(char c)
{
    if (c >= 'A' && c <= 'Z') {
        return c + 32;
    }
    return c;
}

int contains_ignore_case(char *text, char *pattern)
{
    int i = 0;
    int j = 0;

    if (pattern[0] == '\0') {
        return 1;
    }
    while (text[i] != '\0') {
        j = 0;
        while (text[i + j] != '\0' && pattern[j] != '\0' && lower_char(text[i + j]) == lower_char(pattern[j])) {
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
    printf("%d\n", contains_ignore_case("Hello RLX", "rlx"));
    printf("%d\n", contains_ignore_case("Piscine TEK1", "tek"));
    printf("%d\n", contains_ignore_case("Langage C", "python"));
    return 0;
}
