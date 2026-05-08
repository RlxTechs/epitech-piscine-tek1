CC = gcc
AR = ar
CFLAGS = -Wall -Wextra -Werror -Iinclude
LIB = libmy.a
NAME = test_libmy
SRC = src/my_putchar.c src/my_putstr.c src/my_strlen.c src/my_strcpy.c src/my_strcmp.c src/my_put_nbr.c
OBJ = $(SRC:.c=.o)
MAIN = main.c

all: $(LIB) $(NAME)

$(LIB): $(OBJ)
	$(AR) rc $(LIB) $(OBJ)

$(NAME): $(LIB) $(MAIN)
	$(CC) $(CFLAGS) $(MAIN) -L. -lmy -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(LIB)
	rm -f $(NAME).exe
	rm -f $(NAME)

re: fclean all
