#include "memory_lab.h"

int my_strlen_safe(const char *str)
{
    int i = 0;

    if (str == NULL) {
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

    if (a == NULL || b == NULL) {
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

char *safe_strdup(const char *src)
{
    int len = my_strlen_safe(src);
    char *copy = NULL;
    int i = 0;

    if (src == NULL) {
        return NULL;
    }
    copy = safe_malloc(sizeof(char) * (len + 1));
    if (copy == NULL) {
        return NULL;
    }
    while (src[i] != '\0') {
        copy[i] = src[i];
        i = i + 1;
    }
    copy[i] = '\0';
    return copy;
}

char *safe_join(const char *a, const char *b)
{
    int len_a = my_strlen_safe(a);
    int len_b = my_strlen_safe(b);
    char *result = NULL;
    int i = 0;
    int j = 0;

    if (a == NULL || b == NULL) {
        return NULL;
    }
    result = safe_malloc(sizeof(char) * (len_a + len_b + 1));
    if (result == NULL) {
        return NULL;
    }
    while (a[i] != '\0') {
        result[i] = a[i];
        i = i + 1;
    }
    while (b[j] != '\0') {
        result[i + j] = b[j];
        j = j + 1;
    }
    result[i + j] = '\0';
    return result;
}
