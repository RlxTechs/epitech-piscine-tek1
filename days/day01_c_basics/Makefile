CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRC = ex00_hello.c ex01_putchar.c ex02_print_alphabet.c ex03_print_digits.c ex04_is_negative.c ex05_print_numbers.c ex06_my_strlen.c ex07_swap.c
BIN = $(SRC:.c=.exe)

all: $(BIN)

%.exe: %.c
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f $(BIN)

fclean: clean

re: fclean all
