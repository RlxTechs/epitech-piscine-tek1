#include <stdio.h>

int copy_file(char *src_path, char *dest_path)
{
    FILE *src = fopen(src_path, "r");
    FILE *dest = NULL;
    int c = 0;

    if (src == NULL) {
        return 0;
    }
    dest = fopen(dest_path, "w");
    if (dest == NULL) {
        fclose(src);
        return 0;
    }
    c = fgetc(src);
    while (c != EOF) {
        fputc(c, dest);
        c = fgetc(src);
    }
    fclose(src);
    fclose(dest);
    return 1;
}

int main(int argc, char **argv)
{
    if (argc != 3) {
        printf("Usage: %s source destination\n", argv[0]);
        return 1;
    }
    if (copy_file(argv[1], argv[2]) == 0) {
        printf("Copy failed\n");
        return 1;
    }
    printf("Copy success\n");
    return 0;
}
