#include <stdio.h>

int is_separator(int c)
{
    if (c == ' ' || c == '\t' || c == '\n' || c == '\r') {
        return 1;
    }
    return 0;
}

int analyze_file(char *path, int *lines, int *words, int *chars)
{
    FILE *file = fopen(path, "r");
    int c = 0;
    int in_word = 0;
    int has_content = 0;

    if (file == NULL) {
        return 0;
    }
    *lines = 0;
    *words = 0;
    *chars = 0;
    c = fgetc(file);
    while (c != EOF) {
        has_content = 1;
        *chars = *chars + 1;
        if (c == '\n') {
            *lines = *lines + 1;
        }
        if (is_separator(c) == 1) {
            in_word = 0;
        } else if (in_word == 0) {
            *words = *words + 1;
            in_word = 1;
        }
        c = fgetc(file);
    }
    if (has_content == 1 && *lines == 0) {
        *lines = 1;
    }
    fclose(file);
    return 1;
}

int main(int argc, char **argv)
{
    int lines = 0;
    int words = 0;
    int chars = 0;

    if (argc != 2) {
        printf("Usage: %s file\n", argv[0]);
        return 1;
    }
    if (analyze_file(argv[1], &lines, &words, &chars) == 0) {
        printf("Cannot open file\n");
        return 1;
    }
    printf("lines=%d words=%d chars=%d\n", lines, words, chars);
    return 0;
}
