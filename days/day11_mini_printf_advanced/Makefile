CC = gcc
CFLAGS = -Wall -Wextra -Werror -Iinclude
NAME = mini_printf_advanced
SRC = src/my_putchar.c src/my_putstr.c src/my_put_nbr.c src/my_put_unsigned_base.c src/my_printf.c main.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME).exe
	rm -f $(NAME)

re: fclean all
