#include <stdio.h>

int is_separator(char c)
{
    if (c == ' ' || c == '\t' || c == '\n') {
        return 1;
    }
    return 0;
}

int count_words(char *str)
{
    int i = 0;
    int count = 0;
    int in_word = 0;

    while (str[i] != '\0') {
        if (is_separator(str[i]) == 1) {
            in_word = 0;
        } else if (in_word == 0) {
            count = count + 1;
            in_word = 1;
        }
        i = i + 1;
    }
    return count;
}

int main(int argc, char **argv)
{
    if (argc != 2) {
        printf("Usage: %s \"phrase ici\"\n", argv[0]);
        return 1;
    }
    printf("words = %d\n", count_words(argv[1]));
    return 0;
}
