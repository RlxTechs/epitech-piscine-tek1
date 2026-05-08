CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRC = ex00_address.c ex01_set_value.c ex02_swap.c ex03_print_array.c ex04_array_sum.c ex05_min_max.c ex06_reverse_array.c ex07_sort_array.c
BIN = $(SRC:.c=.exe)

all: $(BIN)

%.exe: %.c
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f $(BIN)

fclean: clean

re: fclean all
