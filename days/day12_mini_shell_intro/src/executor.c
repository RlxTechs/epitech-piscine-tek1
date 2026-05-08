#include <stdio.h>
#include <stdlib.h>
#include "mini_shell.h"

int execute_command(char *line)
{
    char *cmd = skip_spaces(line);

    if (cmd[0] == '\0') {
        return 0;
    }
    if (my_strcmp(cmd, "exit") == 0) {
        return -1;
    }
    if (my_strcmp(cmd, "help") == 0) {
        print_help();
        return 0;
    }
    if (my_strcmp(cmd, "pwd") == 0) {
        return command_pwd();
    }
    if (my_strcmp(cmd, "clear") == 0) {
        system("cls");
        return 0;
    }
    if (my_strncmp(cmd, "echo", 4) == 0 && (cmd[4] == ' ' || cmd[4] == '\0' || cmd[4] == '\t')) {
        return command_echo(cmd);
    }
    if (my_strncmp(cmd, "cd", 2) == 0 && (cmd[2] == ' ' || cmd[2] == '\0' || cmd[2] == '\t')) {
        return command_cd(cmd);
    }
    return system(cmd);
}
