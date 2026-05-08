CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRC = ex00_show_args.c ex01_my_atoi.c ex02_is_number.c ex03_sum_args.c ex04_max_arg.c ex05_count_words.c ex06_split_preview.c ex07_calculator_args.c
BIN = $(SRC:.c=.exe)

all: $(BIN)

%.exe: %.c
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f $(BIN)

fclean: clean

re: fclean all
