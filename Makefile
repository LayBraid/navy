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
	  src/events/attack_sender.c \
	  src/events/attack_receiver.c \
	  src/events/victory_sender.c \
	  src/events/victory_receiver.c \
	  src/utils.c \
	  src/network/signals.c \
	  src/network/binary_parser.c \
	  src/network/packet_handler.c \

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

debug:
	gcc $(OBJ) $(SRC_LIB) -o./$(NAME) -g -Iinclude

clean:
	rm -f src/*.o
	rm -f src/network/*.o
	rm -f src/map/*.o
	rm -f src/events/*.o
	rm -rf *.gcda
	rm -rf *.gcno
	rm -rf *.c.gcov

re:
	make fclean
	make

tests_run:
	gcc $(SRC) $(TESTS) $(SRC_LIB) $(CFLAGS) -lcriterion -o./u --coverage
	./u

valgrind:
	gcc $(SRC) $(SRC_LIB) -o./$(NAME) -g3
	valgrind ./$(NAME)

gdb:
	gcc $(SRC) $(SRC_LIB) -o./$(NAME) -g
	gdb ./$(NAME)
