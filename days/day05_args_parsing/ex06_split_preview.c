#include <stdio.h>

int is_separator(char c)
{
    if (c == ' ' || c == '\t' || c == '\n') {
        return 1;
    }
    return 0;
}

void print_words(char *str)
{
    int i = 0;
    int in_word = 0;

    while (str[i] != '\0') {
        if (is_separator(str[i]) == 1) {
            if (in_word == 1) {
                printf("\n");
            }
            in_word = 0;
        } else {
            printf("%c", str[i]);
            in_word = 1;
        }
        i = i + 1;
    }
    if (in_word == 1) {
        printf("\n");
    }
}

int main(int argc, char **argv)
{
    if (argc != 2) {
        printf("Usage: %s \"phrase ici\"\n", argv[0]);
        return 1;
    }
    print_words(argv[1]);
    return 0;
}
