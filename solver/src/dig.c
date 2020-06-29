/*
** EPITECH PROJECT, 2020
** CPE_dante_2019
** File description:
** dig
*/

#include "solver.h"

int dig_up(ul_t *s_ul, int direction)
{
    if (s_ul->head->x == 0) {
        s_ul->up = 1;
        return (0);
    }
    if (s_ul->maze[s_ul->head->x - 1][s_ul->head->y] != '*') {
        s_ul->up = 1;
        return (0);
    }
    s_ul->maze[s_ul->head->x - 1][s_ul->head->y] = 'o';
    s_ul->head = foward(s_ul->head, s_ul->head->x - 1, s_ul->head->y,
    direction);
    s_ul->down = 0, s_ul->left = 0, s_ul->right = 0;
    return (1);
}

int dig_right(ul_t *s_ul, int direction)
{
    if (s_ul->maze[s_ul->head->x][s_ul->head->y + 1] != '*') {
        s_ul->right = 1;
        return (0);
    }
    s_ul->maze[s_ul->head->x][s_ul->head->y + 1] = 'o';
    s_ul->head = foward(s_ul->head, s_ul->head->x, s_ul->head->y + 1,
    direction);
    s_ul->down = 0, s_ul->left = 0, s_ul->up = 0;
    return (1);
}

int dig_down(ul_t *s_ul, int direction)
{
    if (s_ul->head->x == s_ul->len - 1) {
        s_ul->down = 1;
        return (0);
    }
    if (s_ul->maze[s_ul->head->x + 1][s_ul->head->y] != '*') {
        s_ul->down = 1;
        return (0);
    }
    s_ul->maze[s_ul->head->x + 1][s_ul->head->y] = 'o';
    s_ul->head = foward(s_ul->head, s_ul->head->x + 1, s_ul->head->y,
    direction);
    s_ul->down = 0, s_ul->left = 0, s_ul->right = 0;
    return (1);
}

int dig_left(ul_t *s_ul, int direction)
{
    if (s_ul->head->y == 0) {
        s_ul->left = 1;
        return (0);
    }
    if (s_ul->maze[s_ul->head->x][s_ul->head->y - 1] != '*') {
        s_ul->left = 1;
        return (0);
    }
    s_ul->maze[s_ul->head->x][s_ul->head->y - 1] = 'o';
    s_ul->head = foward(s_ul->head, s_ul->head->x, s_ul->head->y - 1,
    direction);
    s_ul->down = 0, s_ul->up = 0, s_ul->right = 0;
    return (1);
}