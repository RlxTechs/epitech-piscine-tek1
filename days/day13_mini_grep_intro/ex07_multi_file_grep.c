#include <stdio.h>

int contains(char *text, char *pattern)
{
    int i = 0;
    int j = 0;

    if (pattern[0] == '\0') {
        return 1;
    }
    while (text[i] != '\0') {
        j = 0;
        while (text[i + j] != '\0' && pattern[j] != '\0' && text[i + j] == pattern[j]) {
            j = j + 1;
        }
        if (pattern[j] == '\0') {
            return 1;
        }
        i = i + 1;
    }
    return 0;
}

int grep_file(char *pattern, char *path, int show_file_name)
{
    FILE *file = fopen(path, "r");
    char line[2048];

    if (file == NULL) {
        printf("cannot open %s\n", path);
        return 1;
    }
    while (fgets(line, sizeof(line), file) != NULL) {
        if (contains(line, pattern) == 1) {
            if (show_file_name == 1) {
                printf("%s:", path);
            }
            printf("%s", line);
        }
    }
    fclose(file);
    return 0;
}

int main(int argc, char **argv)
{
    int i = 2;
    int show_file_name = 0;

    if (argc < 3) {
        printf("Usage: %s pattern file1 file2 ...\n", argv[0]);
        return 1;
    }
    if (argc > 3) {
        show_file_name = 1;
    }
    while (i < argc) {
        grep_file(argv[1], argv[i], show_file_name);
        i = i + 1;
    }
    return 0;
}
