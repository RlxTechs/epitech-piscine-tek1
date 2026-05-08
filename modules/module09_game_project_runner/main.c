#include <stdio.h>
#include "game_runner.h"

int main(int argc, char **argv)
{
    if (argc == 2 && my_strcmp(argv[1], "--list") == 0) {
        runner_print_list();
        return 0;
    }
    if (argc == 2 && my_strcmp(argv[1], "--demo") == 0) {
        return runner_run_all();
    }
    if (argc == 3 && my_strcmp(argv[1], "--run") == 0) {
        return runner_run_choice(argv[2]);
    }
    if (argc > 1) {
        printf("Usage:\\n");
        printf("  %s --list\\n", argv[0]);
        printf("  %s --run 1\\n", argv[0]);
        printf("  %s --run all\\n", argv[0]);
        printf("  %s --demo\\n", argv[0]);
        return 1;
    }
    return runner_interactive();
}
