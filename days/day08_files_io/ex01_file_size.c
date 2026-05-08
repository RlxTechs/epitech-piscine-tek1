#include <stdio.h>

int count_chars(char *path)
{
    FILE *file = fopen(path, "r");
    int c = 0;
    int count = 0;

    if (file == NULL) {
        return -1;
    }
    c = fgetc(file);
    while (c != EOF) {
        count = count + 1;
        c = fgetc(file);
    }
    fclose(file);
    return count;
}

int main(int argc, char **argv)
{
    int size = 0;

    if (argc != 2) {
        printf("Usage: %s file\n", argv[0]);
        return 1;
    }
    size = count_chars(argv[1]);
    if (size < 0) {
        printf("Cannot open file\n");
        return 1;
    }
    printf("chars = %d\n", size);
    return 0;
}
