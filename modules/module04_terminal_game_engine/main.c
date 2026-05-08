#include "game_engine.h"

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
    if (argc == 2 && my_strcmp(argv[1], "--script") == 0) {
        return game_run_scripted("ddddssaaawwddssdd");
    }
    return game_run_interactive();
}


