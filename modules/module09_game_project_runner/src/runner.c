#include <stdio.h>
#include <stdlib.h>
#include "game_runner.h"

int runner_run_index(int index)
{
    game_module_t module;
    int result = 0;

    if (index < 0 || index >= runner_count_modules()) {
        printf("Invalid module index.\\n");
        return 1;
    }
    module = runner_get_module(index);
    printf("\\n=== Launching %s ===\\n", module.name);
    printf("Command: %s\\n\\n", module.command);
    result = system(module.command);
    printf("\\n=== Module finished: %s ===\\n", module.name);
    return result;
}

int runner_run_all(void)
{
    int i = 0;
    int result = 0;

    while (i < runner_count_modules()) {
        result = runner_run_index(i);
        if (result != 0) {
            printf("Warning: module %d returned code %d\\n", i + 1, result);
        }
        i = i + 1;
    }
    return 0;
}

int runner_run_choice(const char *choice)
{
    int index = 0;

    if (runner_is_all_choice(choice) == 1) {
        return runner_run_all();
    }
    index = runner_choice_to_index(choice);
    if (index < 0) {
        printf("Invalid choice.\\n");
        return 1;
    }
    return runner_run_index(index);
}

int runner_interactive(void)
{
    char input[INPUT_SIZE];

    while (1) {
        runner_print_menu();
        if (fgets(input, sizeof(input), stdin) == 0) {
            printf("\\n");
            return 0;
        }
        if (input[0] == 'q') {
            printf("Bye.\\n");
            return 0;
        }
        runner_run_choice(input);
        printf("\\nPress Enter to continue...");
        fgets(input, sizeof(input), stdin);
    }
}
