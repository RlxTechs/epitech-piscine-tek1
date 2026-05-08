#include <stdio.h>

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

int calculate(int a, char op, int b, int *ok)
{
    *ok = 1;
    if (op == '+') {
        return a + b;
    }
    if (op == '-') {
        return a - b;
    }
    if (op == 'x' || op == '*') {
        return a * b;
    }
    if (op == '/') {
        if (b == 0) {
            *ok = 0;
            return 0;
        }
        return a / b;
    }
    *ok = 0;
    return 0;
}

int main(int argc, char **argv)
{
    int a = 0;
    int b = 0;
    int result = 0;
    int ok = 0;

    if (argc != 4) {
        printf("Usage: %s number operator number\n", argv[0]);
        printf("Example: %s 10 + 5\n", argv[0]);
        return 1;
    }
    a = my_atoi(argv[1]);
    b = my_atoi(argv[3]);
    result = calculate(a, argv[2][0], b, &ok);
    if (ok == 0) {
        printf("Invalid operation\n");
        return 1;
    }
    printf("result = %d\n", result);
    return 0;
}
