/*
** EPITECH PROJECT, 2020
** CPE_dante_2019
** File description:
** main
*/

#include "generator.h"

void imperfect(ul_t *s_ul)
{
    int j = s_ul->column / 2;
    for (int i = 0; s_ul->maze[i] != NULL; i++) {
        if (i != 0 && i != s_ul->column - 1)
            s_ul->maze[i][j] = '*';
    }
}

int main(int ac, char **av)
{
    srand(time(NULL));
    ul_t s_ul = {0};
    if (ac == 4 && strcmp(av[3], "perfect") == 0) {
        s_ul.column = atoi(av[1]), s_ul.line = atoi(av[2]);
        if (s_ul.line <= 0 || s_ul.column <= 0)
            return (84);
        s_ul.maze = generate_maze(&s_ul);
        maze(&s_ul);
        print_double_array(s_ul.maze), free_double_array(s_ul.maze);
    } if (ac == 3) {
        s_ul.column = atoi(av[1]), s_ul.line = atoi(av[2]);
        if (s_ul.line <= 0 || s_ul.column <= 0)
            return (84);
        s_ul.maze = generate_maze(&s_ul);
        maze(&s_ul);
        imperfect(&s_ul);
        print_double_array(s_ul.maze), free_double_array(s_ul.maze);
    } return (0);
}