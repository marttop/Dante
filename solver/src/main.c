/*
** EPITECH PROJECT, 2020
** CPE_dante_2019
** File description:
** main
*/

#include "solver.h"

int main(int ac, char **av)
{
    ul_t s_ul = {0};
    srand(time(NULL));
    if (ac == 2) {
        s_ul.maze = load_map(av[1]);
        s_ul.maze = clean_array(s_ul.maze);
        find_dead_ends(s_ul.maze, &s_ul);
        fill_dead_ends(&s_ul);
    } else
        return (84);
    return (0);
}