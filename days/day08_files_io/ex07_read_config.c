#include <stdio.h>

int is_equal_line(char *line, char *key)
{
    int i = 0;

    while (key[i] != '\0') {
        if (line[i] != key[i]) {
            return 0;
        }
        i = i + 1;
    }
    if (line[i] == '=') {
        return 1;
    }
    return 0;
}

void print_value(char *line)
{
    int i = 0;

    while (line[i] != '\0' && line[i] != '=') {
        i = i + 1;
    }
    if (line[i] == '=') {
        i = i + 1;
    }
    while (line[i] != '\0' && line[i] != '\n' && line[i] != '\r') {
        putchar(line[i]);
        i = i + 1;
    }
    putchar('\n');
}

int read_config_value(char *path, char *key)
{
    FILE *file = fopen(path, "r");
    char line[256];

    if (file == NULL) {
        return 0;
    }
    while (fgets(line, sizeof(line), file) != NULL) {
        if (is_equal_line(line, key) == 1) {
            print_value(line);
            fclose(file);
            return 1;
        }
    }
    fclose(file);
    return 0;
}

int main(int argc, char **argv)
{
    if (argc != 3) {
        printf("Usage: %s config_file key\n", argv[0]);
        return 1;
    }
    if (read_config_value(argv[1], argv[2]) == 0) {
        printf("Key not found\n");
        return 1;
    }
    return 0;
}
