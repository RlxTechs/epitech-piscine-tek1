CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRC = ex00_contains.c ex01_count_occurrences.c ex02_print_matching_lines.c ex03_count_matching_lines.c ex04_line_numbers.c ex05_case_insensitive.c ex06_mini_grep.c ex07_multi_file_grep.c
BIN = $(SRC:.c=.exe)

all: $(BIN)

%.exe: %.c
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f $(BIN)

fclean: clean

re: fclean all
