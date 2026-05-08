#include <stdio.h>

int my_strlen(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i = i + 1;
    }
    return i;
}

int starts_with(char *text, char *pattern)
{
    int i = 0;

    while (pattern[i] != '\0') {
        if (text[i] != pattern[i]) {
            return 0;
        }
        i = i + 1;
    }
    return 1;
}

int count_occurrences(char *text, char *pattern)
{
    int i = 0;
    int count = 0;
    int len = my_strlen(pattern);

    if (len == 0) {
        return 0;
    }
    while (text[i] != '\0') {
        if (starts_with(text + i, pattern) == 1) {
            count = count + 1;
            i = i + len;
        } else {
            i = i + 1;
        }
    }
    return count;
}

int main(void)
{
    printf("%d\n", count_occurrences("C C C piscine C", "C"));
    printf("%d\n", count_occurrences("banana", "na"));
    return 0;
}
