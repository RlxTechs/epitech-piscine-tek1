#include <stdio.h>

int my_strlen(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i = i + 1;
    }
    return i;
}

int is_palindrome(char *str)
{
    int left = 0;
    int right = my_strlen(str) - 1;

    while (left < right) {
        if (str[left] != str[right]) {
            return 0;
        }
        left = left + 1;
        right = right - 1;
    }
    return 1;
}

int main(void)
{
    printf("radar = %d\n", is_palindrome("radar"));
    printf("level = %d\n", is_palindrome("level"));
    printf("rlx = %d\n", is_palindrome("rlx"));
    return 0;
}
