#include <stdio.h>

int is_digit(char c)
{
    return c >= '0' && c <= '9';
}

int is_number(char *str)
{
    int i = 0;

    if (str[0] == '\0') {
        return 0;
    }
    if (str[i] == '-' || str[i] == '+') {
        i = i + 1;
    }
    if (str[i] == '\0') {
        return 0;
    }
    while (str[i] != '\0') {
        if (is_digit(str[i]) == 0) {
            return 0;
        }
        i = i + 1;
    }
    return 1;
}

int main(int argc, char **argv)
{
    if (argc != 2) {
        printf("Usage: %s value\n", argv[0]);
        return 1;
    }
    printf("%d\n", is_number(argv[1]));
    return 0;
}
