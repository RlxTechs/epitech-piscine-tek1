#ifndef APP_H_
#define APP_H_

int my_strlen_safe(const char *str);
int my_str_equals(const char *a, const char *b);
int add_numbers(int a, int b);
int multiply_numbers(int a, int b);
void app_print_banner(void);
int app_run(int argc, char **argv);

#endif
