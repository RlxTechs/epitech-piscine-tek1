#include "grid_game.h"

int my_strcmp(char *a, char *b)
{
    int i = 0;

    while (a[i] != '\0' && b[i] != '\0' && a[i] == b[i]) {
        i = i + 1;
    }
    return a[i] - b[i];
}

int main(int argc, char **argv)
{
    if (argc == 2 && my_strcmp(argv[1], "--demo") == 0) {
        return grid_run_demo("dddssddssaassddwwddss");
    }
    return grid_run_interactive();
}
