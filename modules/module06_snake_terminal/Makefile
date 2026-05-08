CC = gcc
CFLAGS = -Wall -Wextra -Werror -Iinclude -g
APP = snake_game
TEST = unit_tests
COMMON_SRC = src/random_tools.c src/snake_core.c src/snake_update.c src/render.c src/runner.c
COMMON_OBJ = $(COMMON_SRC:.c=.o)
APP_OBJ = main.o
TEST_OBJ = tests/test_snake.o

all: $(APP) $(TEST)

$(APP): $(COMMON_OBJ) $(APP_OBJ)
	$(CC) $(CFLAGS) $(COMMON_OBJ) $(APP_OBJ) -o $(APP)

$(TEST): $(COMMON_OBJ) $(TEST_OBJ)
	$(CC) $(CFLAGS) $(COMMON_OBJ) $(TEST_OBJ) -o $(TEST)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(COMMON_OBJ)
	rm -f $(APP_OBJ)
	rm -f $(TEST_OBJ)

fclean: clean
	rm -f $(APP).exe
	rm -f $(APP)
	rm -f $(TEST).exe
	rm -f $(TEST)

re: fclean all
