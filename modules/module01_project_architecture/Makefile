CC = gcc
CFLAGS = -Wall -Wextra -Werror -Iinclude
APP = app_architecture
TEST = unit_tests
COMMON_SRC = src/string_utils.c src/math_utils.c src/app.c
COMMON_OBJ = $(COMMON_SRC:.c=.o)
APP_OBJ = main.o
TEST_OBJ = tests/test_app.o

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
