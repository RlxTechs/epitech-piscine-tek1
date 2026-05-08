CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = hello
SRC = hello.c

all: $(NAME)

$(NAME): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(NAME)

clean:
	rm -f $(NAME).exe
	rm -f $(NAME)

fclean: clean

re: fclean all
