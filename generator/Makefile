##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## makefile
##

NAME	=	generator

SRC	=	src/main.c \
		src/create_board.c \
		src/maze.c \
		src/dig.c \
		utils/get_int.c \
		utils/print.c \

SRC_TEST	=	tests/test_all.c \

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-Wall -Wextra
CFLAGS	+=	-I./include -g3
FFLAGS = -L/usr/local/lib -lcriterion --coverage
FFLAGS += -fprofile-arcs -ftest-coverage

all	:	$(NAME)

tests_run :
	gcc -o test_run -O0 $(CFLAGS) $(FFLAGS) $(SRC_TEST)
	./test_run
coverage :
	/home/mszuts/.local/bin/gcovr --branch --exclude tests/
$(NAME)	:	$(OBJ)
		gcc -o $(NAME) $(OBJ)
clean	:
		rm -f $(OBJ)

fclean	:	clean
		rm -f $(NAME)
		rm -f *gcda *gcno test_run

re	:	fclean all
