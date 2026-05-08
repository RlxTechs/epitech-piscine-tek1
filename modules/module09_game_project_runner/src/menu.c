#include <stdio.h>
#include "game_runner.h"

int runner_choice_to_index(const char *choice)
{
    if (choice == 0 || choice[0] == '\0') {
        return -1;
    }
    if (choice[0] < '1' || choice[0] > '5') {
        return -1;
    }
    if (choice[1] != '\0' && choice[1] != '\n' && choice[1] != '\r') {
        return -1;
    }
    return choice[0] - '1';
}

int runner_is_all_choice(const char *choice)
{
    if (my_strcmp(choice, "all") == 0) {
        return 1;
    }
    if (my_strcmp(choice, "all\n") == 0) {
        return 1;
    }
    return 0;
}

int runner_is_valid_choice(const char *choice)
{
    if (runner_choice_to_index(choice) >= 0) {
        return 1;
    }
    if (runner_is_all_choice(choice) == 1) {
        return 1;
    }
    return 0;
}

void runner_print_header(void)
{
    printf("========================================\\n");
    printf("      RLX TEK1 GAME PROJECT RUNNER       \\n");
    printf("========================================\\n");
}

void runner_print_list(void)
{
    int i = 0;
    game_module_t module;

    runner_print_header();
    printf("\\nAvailable modules:\\n\\n");
    while (i < runner_count_modules()) {
        module = runner_get_module(i);
        printf("%d. %s\\n", module.id, module.name);
        printf("   %s\\n", module.description);
        i = i + 1;
    }
    printf("\\n");
}

void runner_print_menu(void)
{
    runner_print_list();
    printf("Type a number to launch a module.\\n");
    printf("Type all to launch all demos.\\n");
    printf("Type q to quit.\\n");
    printf("\\nChoice> ");
}
