CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRC = ex00_malloc_int.c ex01_malloc_array.c ex02_my_strdup.c ex03_join_strings.c ex04_split_words.c ex05_struct_student.c ex06_linked_list.c ex07_memory_rules.c
BIN = $(SRC:.c=.exe)

all: $(BIN)

%.exe: %.c
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f $(BIN)

fclean: clean

re: fclean all
