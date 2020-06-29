##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## makefile
##

NAME	=	solver

SRC	=	src/main.c \
		src/load.c \
		src/print.c \
		src/my_strdup.c \
		src/dead_end.c \
		src/dead_end2.c \
		src/case.c \
		src/special.c \
		src/pathfinding.c \
		src/dig.c \
		src/unique_path.c \
		src/deb.c \

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
