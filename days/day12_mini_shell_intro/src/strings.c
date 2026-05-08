#include "mini_shell.h"

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

int my_strcmp(char *s1, char *s2)
{
    int i = 0;

    while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i]) {
        i = i + 1;
    }
    return s1[i] - s2[i];
}

int my_strncmp(char *s1, char *s2, int n)
{
    int i = 0;

    while (i < n && s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i]) {
        i = i + 1;
    }
    if (i == n) {
        return 0;
    }
    return s1[i] - s2[i];
}

char *skip_spaces(char *str)
{
    int i = 0;

    while (str[i] == ' ' || str[i] == '\t') {
        i = i + 1;
    }
    return str + i;
}

void trim_newline(char *str)
{
    int len = my_strlen(str);

    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
        len = len - 1;
    }
    if (len > 0 && str[len - 1] == '\r') {
        str[len - 1] = '\0';
    }
}
