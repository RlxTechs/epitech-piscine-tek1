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

int count_matching_lines(char *path, char *pattern)
{
    FILE *file = fopen(path, "r");
    char line[2048];
    int count = 0;

    if (file == NULL) {
        return -1;
    }
    while (fgets(line, sizeof(line), file) != NULL) {
        if (contains(line, pattern) == 1) {
            count = count + 1;
        }
    }
    fclose(file);
    return count;
}

int main(int argc, char **argv)
{
    int count = 0;

    if (argc != 3) {
        printf("Usage: %s pattern file\n", argv[0]);
        return 1;
    }
    count = count_matching_lines(argv[2], argv[1]);
    if (count < 0) {
        printf("Cannot open file\n");
        return 1;
    }
    printf("matching lines = %d\n", count);
    return 0;
}
