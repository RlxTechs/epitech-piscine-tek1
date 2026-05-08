CC = gcc
CFLAGS = -Wall -Wextra -Werror -Iinclude
NAME = unit_tests
SRC = main.c src/test_framework.c src/my_strlen.c src/my_strcmp.c src/my_atoi.c src/my_is_number.c src/array_sum.c tests/test_strings.c tests/test_numbers.c tests/test_arrays.c
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
