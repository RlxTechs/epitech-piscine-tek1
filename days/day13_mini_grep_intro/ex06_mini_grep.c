#include <stdio.h>

typedef struct options_s {
    int show_line_numbers;
    int ignore_case;
    char *pattern;
    char *file;
} options_t;

int my_strcmp(char *a, char *b)
{
    int i = 0;

    while (a[i] != '\0' && b[i] != '\0' && a[i] == b[i]) {
        i = i + 1;
    }
    return a[i] - b[i];
}

char lower_char(char c)
{
    if (c >= 'A' && c <= 'Z') {
        return c + 32;
    }
    return c;
}

int contains_mode(char *text, char *pattern, int ignore_case)
{
    int i = 0;
    int j = 0;
    char a = 0;
    char b = 0;

    if (pattern[0] == '\0') {
        return 1;
    }
    while (text[i] != '\0') {
        j = 0;
        while (text[i + j] != '\0' && pattern[j] != '\0') {
            a = text[i + j];
            b = pattern[j];
            if (ignore_case == 1) {
                a = lower_char(a);
                b = lower_char(b);
            }
            if (a != b) {
                break;
            }
            j = j + 1;
        }
        if (pattern[j] == '\0') {
            return 1;
        }
        i = i + 1;
    }
    return 0;
}

int parse_options(int argc, char **argv, options_t *options)
{
    options->show_line_numbers = 0;
    options->ignore_case = 0;
    if (argc == 3) {
        options->pattern = argv[1];
        options->file = argv[2];
        return 1;
    }
    if (argc == 4) {
        if (my_strcmp(argv[1], "-n") == 0) {
            options->show_line_numbers = 1;
        } else if (my_strcmp(argv[1], "-i") == 0) {
            options->ignore_case = 1;
        } else if (my_strcmp(argv[1], "-in") == 0 || my_strcmp(argv[1], "-ni") == 0) {
            options->ignore_case = 1;
            options->show_line_numbers = 1;
        } else {
            return 0;
        }
        options->pattern = argv[2];
        options->file = argv[3];
        return 1;
    }
    return 0;
}

int mini_grep(options_t *options)
{
    FILE *file = fopen(options->file, "r");
    char line[2048];
    int line_number = 1;

    if (file == NULL) {
        printf("mini_grep: cannot open %s\n", options->file);
        return 1;
    }
    while (fgets(line, sizeof(line), file) != NULL) {
        if (contains_mode(line, options->pattern, options->ignore_case) == 1) {
            if (options->show_line_numbers == 1) {
                printf("%d:", line_number);
            }
            printf("%s", line);
        }
        line_number = line_number + 1;
    }
    fclose(file);
    return 0;
}

int main(int argc, char **argv)
{
    options_t options;

    if (parse_options(argc, argv, &options) == 0) {
        printf("Usage: %s [-n|-i|-in] pattern file\n", argv[0]);
        return 1;
    }
    return mini_grep(&options);
}
