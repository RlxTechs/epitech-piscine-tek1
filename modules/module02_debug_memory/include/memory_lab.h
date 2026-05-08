#ifndef MEMORY_LAB_H_
#define MEMORY_LAB_H_

#include <stddef.h>
#include <stdlib.h>

#define SAFE_FREE(ptr) do { if ((ptr) != 0) { free(ptr); (ptr) = 0; } } while (0)

void *safe_malloc(size_t size);
int is_null(void *ptr);
int my_strlen_safe(const char *str);
int my_str_equals(const char *a, const char *b);
char *safe_strdup(const char *src);
char *safe_join(const char *a, const char *b);
int *create_int_array(int size, int initial_value);
void fill_sequence(int *array, int size);
int array_sum(int *array, int size);
void debug_print_ptr(const char *label, void *ptr);

#endif
