#include <stdio.h>

void print_numbers(int limit)
{
    int i = 0;

    while (i <= limit) {
        printf("%d\n", i);
        i = i + 1;
    }
}

int main(void)
{
    print_numbers(5);
    return 0;
}
