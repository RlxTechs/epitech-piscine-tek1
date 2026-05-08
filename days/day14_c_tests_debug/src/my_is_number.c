#include "project.h"

static int is_digit(char c)
{
    return c >= '0' && c <= '9';
}

int my_is_number(char *str)
{
    int i = 0;

    if (str == 0 || str[0] == '\0') {
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
