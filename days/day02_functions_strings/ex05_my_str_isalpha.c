#include <stdio.h>

int is_alpha_char(char c)
{
    if (c >= 'a' && c <= 'z') {
        return 1;
    }
    if (c >= 'A' && c <= 'Z') {
        return 1;
    }
    return 0;
}

int my_str_isalpha(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (is_alpha_char(str[i]) == 0) {
            return 0;
        }
        i = i + 1;
    }
    return 1;
}

int main(void)
{
    printf("%d\n", my_str_isalpha("RlxTechs"));
    printf("%d\n", my_str_isalpha("Rlx2026"));
    printf("%d\n", my_str_isalpha(""));
    return 0;
}
