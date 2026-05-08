CC = gcc
CFLAGS = -Wall -Wextra -Werror -Iinclude -g
APP = memory_lab
TEST = unit_tests
COMMON_SRC = src/memory_utils.c src/string_utils.c src/array_utils.c src/debug_utils.c
COMMON_OBJ = $(COMMON_SRC:.c=.o)
APP_OBJ = main.o
TEST_OBJ = tests/test_memory_lab.o

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
