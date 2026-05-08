#ifndef MINI_SHELL_H_
#define MINI_SHELL_H_

#define INPUT_SIZE 1024

int my_strlen(char *str);
int my_strcmp(char *s1, char *s2);
int my_strncmp(char *s1, char *s2, int n);
char *skip_spaces(char *str);
void trim_newline(char *str);
void print_prompt(void);
void print_help(void);
int command_echo(char *line);
int command_pwd(void);
int command_cd(char *line);
int execute_command(char *line);

#endif
