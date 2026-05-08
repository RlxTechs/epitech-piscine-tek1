#include "project.h"

int my_strlen(char *str)
{
    int i = 0;

    if (str == 0) {
        return 0;
    }
    while (str[i] != '\0') {
        i = i + 1;
    }
    return i;
}
