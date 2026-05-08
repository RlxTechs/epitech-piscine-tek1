#include <stdio.h>

int count_lines(char *path)
{
    FILE *file = fopen(path, "r");
    int c = 0;
    int lines = 0;
    int has_content = 0;

    if (file == NULL) {
        return -1;
    }
    c = fgetc(file);
    while (c != EOF) {
        has_content = 1;
        if (c == '\n') {
            lines = lines + 1;
        }
        c = fgetc(file);
    }
    if (has_content == 1 && lines == 0) {
        lines = 1;
    }
    fclose(file);
    return lines;
}

int main(int argc, char **argv)
{
    int lines = 0;

    if (argc != 2) {
        printf("Usage: %s file\n", argv[0]);
        return 1;
    }
    lines = count_lines(argv[1]);
    if (lines < 0) {
        printf("Cannot open file\n");
        return 1;
    }
    printf("lines = %d\n", lines);
    return 0;
}
