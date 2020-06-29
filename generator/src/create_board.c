/*
** EPITECH PROJECT, 2020
** CPE_dante_2019
** File description:
** maze
*/

#include "generator.h"

char *fill_line(ul_t *s_ul, char *maze)
{
    int i = 0;
    for (; i != s_ul->column; i++) {
        maze[i] = 'X';
    }
    maze[i] = '\0';
    return (maze);
}

char **generate_maze(ul_t *s_ul)
{
    char **maze = malloc(sizeof(char *) * (s_ul->line + 1));
    int i = 0;
    for (; i != s_ul->line; i++) {
        maze[i] = malloc(sizeof(char) * (s_ul->column + 1));
        maze[i] = fill_line(s_ul, maze[i]);
    }
    maze[i] = NULL;
    return (maze);
}