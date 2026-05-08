#include <stdio.h>

int is_separator(int c)
{
    if (c == ' ' || c == '\t' || c == '\n' || c == '\r') {
        return 1;
    }
    return 0;
}

int count_words(char *path)
{
    FILE *file = fopen(path, "r");
    int c = 0;
    int words = 0;
    int in_word = 0;

    if (file == NULL) {
        return -1;
    }
    c = fgetc(file);
    while (c != EOF) {
        if (is_separator(c) == 1) {
            in_word = 0;
        } else if (in_word == 0) {
            words = words + 1;
            in_word = 1;
        }
        c = fgetc(file);
    }
    fclose(file);
    return words;
}

int main(int argc, char **argv)
{
    int words = 0;

    if (argc != 2) {
        printf("Usage: %s file\n", argv[0]);
        return 1;
    }
    words = count_words(argv[1]);
    if (words < 0) {
        printf("Cannot open file\n");
        return 1;
    }
    printf("words = %d\n", words);
    return 0;
}
