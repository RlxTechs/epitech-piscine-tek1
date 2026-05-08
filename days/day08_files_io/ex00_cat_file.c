#include <stdio.h>

int main(int argc, char **argv)
{
    FILE *file = NULL;
    int c = 0;

    if (argc != 2) {
        printf("Usage: %s file\n", argv[0]);
        return 1;
    }
    file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Cannot open file: %s\n", argv[1]);
        return 1;
    }
    c = fgetc(file);
    while (c != EOF) {
        putchar(c);
        c = fgetc(file);
    }
    fclose(file);
    return 0;
}
