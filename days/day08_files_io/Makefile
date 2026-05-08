CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRC = ex00_cat_file.c ex01_file_size.c ex02_count_lines.c ex03_count_words.c ex04_wc_simple.c ex05_copy_file.c ex06_append_log.c ex07_read_config.c
BIN = $(SRC:.c=.exe)

all: $(BIN)

%.exe: %.c
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f $(BIN)
	rm -f inputs/copy_sample.txt
	rm -f inputs/log.txt

fclean: clean

re: fclean all
