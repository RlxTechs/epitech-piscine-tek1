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

int my_atoi(char *str)
{
    int i = 0;
    int sign = 1;
    int result = 0;

    if (str[i] == '-') {
        sign = -1;
        i = i + 1;
    } else if (str[i] == '+') {
        i = i + 1;
    }
    while (str[i] >= '0' && str[i] <= '9') {
        result = result * 10 + (str[i] - '0');
        i = i + 1;
    }
    return result * sign;
}

int main(int argc, char **argv)
{
    int i = 2;
    int max = 0;
    int current = 0;

    if (argc < 2) {
        printf("Usage: %s n1 n2 n3...\n", argv[0]);
        return 1;
    }
    if (is_number(argv[1]) == 0) {
        printf("Invalid number: %s\n", argv[1]);
        return 1;
    }
    max = my_atoi(argv[1]);
    while (i < argc) {
        if (is_number(argv[i]) == 0) {
            printf("Invalid number: %s\n", argv[i]);
            return 1;
        }
        current = my_atoi(argv[i]);
        if (current > max) {
            max = current;
        }
        i = i + 1;
    }
    printf("max = %d\n", max);
    return 0;
}
