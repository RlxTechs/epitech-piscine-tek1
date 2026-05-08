#include <stdio.h>

int my_strcmp(char *s1, char *s2)
{
    int i = 0;

    while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i]) {
        i = i + 1;
    }
    return s1[i] - s2[i];
}

int main(void)
{
    printf("%d\n", my_strcmp("abc", "abc"));
    printf("%d\n", my_strcmp("abc", "abd"));
    printf("%d\n", my_strcmp("abd", "abc"));
    return 0;
}
