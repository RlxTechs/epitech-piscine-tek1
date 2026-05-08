CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRC = ex00_factorial_iterative.c ex01_factorial_recursive.c ex02_fibonacci.c ex03_power.c ex04_is_prime.c ex05_gcd.c ex06_binary_search.c ex07_palindrome.c
BIN = $(SRC:.c=.exe)

all: $(BIN)

%.exe: %.c
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f $(BIN)

fclean: clean

re: fclean all
