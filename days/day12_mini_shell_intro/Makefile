CC = gcc
CFLAGS = -Wall -Wextra -Werror -Iinclude
NAME = mini_shell
MAIN_SRC = main.c src/strings.c src/builtins.c src/executor.c
MAIN_OBJ = $(MAIN_SRC:.c=.o)
EX_SRC = ex00_read_line.c ex01_trim_newline.c ex02_parse_echo.c
EX_BIN = $(EX_SRC:.c=.exe)

all: $(NAME) $(EX_BIN)

$(NAME): $(MAIN_OBJ)
	$(CC) $(CFLAGS) $(MAIN_OBJ) -o $(NAME)

%.exe: %.c
	$(CC) $(CFLAGS) $< -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(MAIN_OBJ)
	rm -f $(EX_BIN)

fclean: clean
	rm -f $(NAME).exe
	rm -f $(NAME)

re: fclean all
