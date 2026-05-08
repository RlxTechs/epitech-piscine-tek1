CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRC = ex00_my_putchar.c ex01_my_putstr.c ex02_my_strlen.c ex03_my_strcpy.c ex04_my_strcmp.c ex05_my_str_isalpha.c ex06_my_strupcase.c ex07_my_put_nbr.c
BIN = $(SRC:.c=.exe)

all: $(BIN)

%.exe: %.c
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f $(BIN)

fclean: clean

re: fclean all
