##
## EPITECH PROJECT, 2020
## CPE_dante_2019
## File description:
## Makefile
##

SRC_TEST	=	tests/test_generator.c \
				generator/src/create_board.c \
				generator/src/maze.c \
				generator/src/dig.c \
				generator/utils/get_int.c \
				generator/utils/print.c \

CFLAGS	+=	-I./generator/include -g3
FFLAGS = -L/usr/local/lib -lcriterion --coverage
FFLAGS += -fprofile-arcs -ftest-coverage

all	:
		cd generator/ && make
		cd solver/ && make
tests_run :
	gcc -o test_run -O0 $(CFLAGS) $(FFLAGS) $(SRC_TEST)
	./test_run
coverage :
	/home/mszuts/.local/bin/gcovr --branch --exclude tests/
clean	:
		cd generator/ && make clean
		cd solver/ && make clean
fclean	:
		cd generator/ && make fclean
		cd solver/ && make fclean
		rm -f *gcda *gcno test_run
re	:	fclean all