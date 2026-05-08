#include "app.h"

int my_strlen_safe(const char *str)
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

int my_str_equals(const char *a, const char *b)
{
    int i = 0;

    if (a == 0 || b == 0) {
        return 0;
    }
    while (a[i] != '\0' && b[i] != '\0') {
        if (a[i] != b[i]) {
            return 0;
        }
        i = i + 1;
    }
    return a[i] == '\0' && b[i] == '\0';
}
