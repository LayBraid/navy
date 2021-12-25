##
## EPITECH PROJECT, 2021
## MY_LS
## File description:
## No file there , just an epitech header example
##

MAIN = src/main.c

SRC = src/map/input.c \
	  src/map/map.c \
	  src/navy.c \
	  src/map/utils.c \
	  src/utils.c \

TESTS = tests/test_my_strlen.c

OBJ = $(MAIN:.c=.o) $(SRC:.c=.o)

NAME = navy
SRC_LIB = -Llib -lmy
CFLAGS += -Wextra -Iinclude -g3

$(NAME): $(OBJ)
	cd lib/my && make
	gcc $(OBJ) $(SRC_LIB) -o./$(NAME) -g3

all: $(NAME)

fclean:
	cd lib/my && make fclean
	make clean
	rm -f $(NAME)
	rm -f u

clean:
	rm -f src/*.o
	rm -rf *.gcda
	rm -rf *.gcno
	rm -rf *.c.gcov

re:
	make fclean
	make

tests_run:
	gcc $(SRC) $(TESTS) $(SRC_LIB) $(CFLAGS) -lcriterion -o./u --coverage
	./u

debug:
	gcc $(SRC) $(SRC_LIB) -o./$(NAME) -g

valgrind:
	gcc $(SRC) $(SRC_LIB) -o./$(NAME) -g3
	valgrind ./$(NAME)

gdb:
	gcc $(SRC) $(SRC_LIB) -o./$(NAME) -g
	gdb ./$(NAME)
