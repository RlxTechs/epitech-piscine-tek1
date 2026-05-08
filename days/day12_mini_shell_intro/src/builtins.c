#include <stdio.h>
#include <stdlib.h>

#ifdef _WIN32
#include <direct.h>
#define getcwd _getcwd
#define chdir _chdir
#else
#include <unistd.h>
#endif

#include "mini_shell.h"

void print_prompt(void)
{
    printf("rlx-shell> ");
    fflush(stdout);
}

void print_help(void)
{
    printf("Mini shell commands:\\n");
    printf("  help        show this help\\n");
    printf("  echo TEXT   print TEXT\\n");
    printf("  pwd         print current directory\\n");
    printf("  cd PATH     change directory\\n");
    printf("  clear       clear screen\\n");
    printf("  exit        quit shell\\n");
    printf("  other       executed with system()\\n");
}

int command_echo(char *line)
{
    char *text = line + 4;

    text = skip_spaces(text);
    printf("%s\\n", text);
    return 0;
}

int command_pwd(void)
{
    char buffer[INPUT_SIZE];

    if (getcwd(buffer, sizeof(buffer)) == 0) {
        printf("pwd: cannot get current directory\\n");
        return 1;
    }
    printf("%s\\n", buffer);
    return 0;
}

int command_cd(char *line)
{
    char *path = line + 2;

    path = skip_spaces(path);
    if (path[0] == '\0') {
        printf("cd: missing path\\n");
        return 1;
    }
    if (chdir(path) != 0) {
        printf("cd: cannot access %s\\n", path);
        return 1;
    }
    return 0;
}
