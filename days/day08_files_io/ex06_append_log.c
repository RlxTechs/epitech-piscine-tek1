#include <stdio.h>

int append_log(char *path, char *message)
{
    FILE *file = fopen(path, "a");

    if (file == NULL) {
        return 0;
    }
    fputs(message, file);
    fputc('\n', file);
    fclose(file);
    return 1;
}

int main(int argc, char **argv)
{
    if (argc != 3) {
        printf("Usage: %s log_file message\n", argv[0]);
        return 1;
    }
    if (append_log(argv[1], argv[2]) == 0) {
        printf("Cannot write log\n");
        return 1;
    }
    printf("Log added\n");
    return 0;
}
