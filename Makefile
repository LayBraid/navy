##
## EPITECH PROJECT, 2021
## MY_LS
## File description:
## No file there , just an epitech header example
##

SRC = src/main.c \
	  src/navy.c \
	  src/map/map.c \
	  src/map/parser.c \
	  src/map/reader.c \
	  src/map/utils.c \
	  src/events/attack_sender.c \
	  src/events/attack_receiver.c \
	  src/events/victory_sender.c \
	  src/events/victory_receiver.c \
	  src/network/signals.c \
	  src/network/binary_parser.c \
	  src/network/packet_handler.c

SRC_TST = src/my_test.c

TESTS = tests/test_my_test.c

OBJ = $(SRC:.c=.o)

MYLIB = -Iinclude -Llib/my -lmy
CRITERION = -g3 --coverage -lcriterion
NAME = navy
CFLAGS += -Werror -Wextra -Iinclude

$(NAME): $(OBJ)
	cd lib/my && make
	gcc $(OBJ) -Llib/my -lmy -o./$(NAME)

all: $(NAME)

fclean:
	cd lib/my && make fclean
	make clean
	rm -f $(NAME)
	rm -f u

clean:
	rm -f profile.txt
	rm -f gmon.out
	find . -type f -name '*.o' -delete
	find . -type f -name '*.gcda' -delete
	find . -type f -name '*.gcno' -delete
	find . -type f -name '*.gcov' -delete

re:
	make fclean
	make

tests_run:
	gcc $(SRC_TST) $(TESTS) $(CFLAGS) -lcriterion -o./u --coverage
	./u

coverage:
	make tests_run
	gcovr -e tests/

gdb:
	gcc $(SRC) $(MYLIB) -o./$(NAME) -g
	gdb --quiet ./$(NAME)

debug:
	gcc $(SRC) $(MYLIB) -o./$(NAME) -g

profile:
	gcc $(SRC) $(MYLIB) -o./$(NAME) -g -p
	gprof $(NAME) gmon.out > profile.txt

valgrind:
	gcc $(SRC) $(MYLIB) -o./$(NAME) -g3
	valgrind ./$(NAME)

leak:
	gcc $(SRC) $(MYLIB) -o./$(NAME) -g3
	valgrind --leak-check=full ./$(NAME)

origins:
	gcc $(SRC) $(MYLIB) -o./$(NAME) -g3
	valgrind --track-origins=yes ./$(NAME)
