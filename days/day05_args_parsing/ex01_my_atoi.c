#include <stdio.h>

int is_space(char c)
{
    if (c == ' ' || c == '\t' || c == '\n') {
        return 1;
    }
    return 0;
}

int my_atoi(char *str)
{
    int i = 0;
    int sign = 1;
    int result = 0;

    while (is_space(str[i]) == 1) {
        i = i + 1;
    }
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
    if (argc != 2) {
        printf("Usage: %s number\n", argv[0]);
        return 1;
    }
    printf("%d\n", my_atoi(argv[1]));
    return 0;
}
