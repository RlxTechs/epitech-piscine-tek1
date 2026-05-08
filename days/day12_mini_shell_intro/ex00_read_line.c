#include <stdio.h>

int main(void)
{
    char input[1024];

    printf("Enter text: ");
    if (fgets(input, sizeof(input), stdin) == 0) {
        return 1;
    }
    printf("You typed: %s", input);
    return 0;
}
