#ifndef GAME_RUNNER_H_
#define GAME_RUNNER_H_

#define MODULE_COUNT 5
#define INPUT_SIZE 128

typedef struct game_module_s {
    int id;
    const char *name;
    const char *description;
    const char *command;
} game_module_t;

int my_strcmp(const char *a, const char *b);
int runner_count_modules(void);
int runner_choice_to_index(const char *choice);
int runner_is_all_choice(const char *choice);
int runner_is_valid_choice(const char *choice);
game_module_t runner_get_module(int index);
void runner_print_header(void);
void runner_print_list(void);
void runner_print_menu(void);
int runner_run_index(int index);
int runner_run_choice(const char *choice);
int runner_run_all(void);
int runner_interactive(void);

#endif
