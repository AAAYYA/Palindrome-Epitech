##
## EPITECH PROJECT, 2023
## delivery
## File description:
## Makefile
##

CC = gcc
CFLAGS = -Wall -Wextra
TEST_FLAGS = --coverage -lcriterion
DEBUG_FLAGS = -g -g3

SRCS = requirement.c		\
	   $(SRC_PATH)errors.c		\
	   $(SRC_PATH)find_p.c		\
	   $(SRC_PATH)main.c		\
	   $(SRC_PATH)palindrome.c	\
	   $(SRC_PATH)main_loop.c

TEST_SRCS = requirement.c		\
		tests/test.c			\
	   $(SRC_PATH)errors.c		\
	   $(SRC_PATH)find_p.c		\
	   $(SRC_PATH)palindrome.c	\
	   $(SRC_PATH)main_loop.c

BONUS_SRCS = $(BONUS_PATH)errors.c		\
	   $(BONUS_PATH)find_p.c			\
	   $(BONUS_PATH)palindrome.c		\
	   $(BONUS_PATH)main_loop.c			\
	   $(BONUS_PATH)flag_l.c			\
	   $(BONUS_PATH)get_args.c			\
	   $(BONUS_PATH)main.c				\
	   $(BONUS_PATH)variables.c

BASH_PATH = bash/
SRC_PATH = src/
BONUS_PATH = bonus/src/

OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)
TEST_OBJS = $(TEST_SRCS:.c=.o)

EXEC = palindrome
BONUS_EXEC = palindrome_bonus
TEST_EXEC = unit_tests
FUNC_TEST = $(BASH_PATH)tester.sh
HELP = $(BASH_PATH)helper.sh

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(EXEC)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TEST_OBJS)

fclean: clean
	rm -f $(EXEC) $(TEST_EXEC)* $(BONUS_EXEC)
	rm -f $(BONUS_OBJS)

re: fclean all

help: $(HELPER)
	./$(HELP)

bonus: $(BONUS_EXEC)

$(BONUS_EXEC): $(BONUS_OBJS)
	$(CC) $(CFLAGS) $(BONUS_OBJS) -o $(EXEC)

tests_run: fclean $(TEST_EXEC)
	./$(TEST_EXEC)

debug: $(EXEC)
	$(CC) $(CFLAGS) $(OBJS) -o $(EXEC) $(DEBUG_FLAGS)

functionnal: $(EXEC)
	./$(FUNC_TEST)

$(TEST_EXEC):
	$(CC) -o $(TEST_EXEC) $(TEST_SRCS) $(TEST_FLAGS)

.PHONY: all clean fclean re test debug functionnal bonus
