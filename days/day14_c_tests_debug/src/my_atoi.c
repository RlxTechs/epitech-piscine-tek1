#include "project.h"

int my_atoi(char *str)
{
    int i = 0;
    int sign = 1;
    int result = 0;

    while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n') {
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
