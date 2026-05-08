#include "game_runner.h"

int my_strcmp(const char *a, const char *b)
{
    int i = 0;

    if (a == 0 || b == 0) {
        return -1;
    }
    while (a[i] != '\0' && b[i] != '\0' && a[i] == b[i]) {
        i = i + 1;
    }
    return a[i] - b[i];
}
