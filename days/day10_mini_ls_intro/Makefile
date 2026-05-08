CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRC = ex00_list_current.c ex01_list_path.c ex02_count_entries.c ex03_show_hidden.c ex04_file_type.c ex05_join_path.c ex06_mini_ls.c ex07_recursive_preview.c
BIN = $(SRC:.c=.exe)

all: $(BIN)

%.exe: %.c
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f $(BIN)

fclean: clean

re: fclean all
