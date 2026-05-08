#include <stdio.h>
#include "mini_shell.h"

int main(void)
{
    char input[INPUT_SIZE];
    int result = 0;

    printf("RLX Mini Shell Intro\\n");
    printf("Type help for commands. Type exit to quit.\\n");
    while (1) {
        print_prompt();
        if (fgets(input, sizeof(input), stdin) == 0) {
            printf("\\n");
            break;
        }
        trim_newline(input);
        result = execute_command(input);
        if (result == -1) {
            break;
        }
    }
    printf("Bye.\\n");
    return 0;
}
