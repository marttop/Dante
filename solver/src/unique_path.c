/*
** EPITECH PROJECT, 2020
** CPE_dante_2019
** File description:
** unique_path
*/

#include "solver.h"

pos_t *foward(pos_t *old, int x, int y, int direction)
{
    pos_t *new = malloc(sizeof(pos_t));
    new->x = x;
    new->y = y;
    new->direction = direction;
    new->next = old;
    return (new);
}

int dig(ul_t *s_ul, int direction)
{
    int res = 0;
    if (direction == 2) {
        if (s_ul->down != 1) res = dig_down(s_ul, direction);
        else direction = 1;
    } if (direction == 1) {
        if (s_ul->right != 1) res = dig_right(s_ul, direction);
        else direction = 0;
    } if (direction == 0) {
        if (s_ul->up != 1) res = dig_up(s_ul, direction);
        else direction = 3;
    } if (direction == 3) {
        if (s_ul->left != 1) res = dig_left(s_ul, direction);
        else direction = 4;
    } if (res == 0 && (s_ul->up == 1 && s_ul->right == 1 && s_ul->down == 1 &&
    s_ul->left == 1)) {
        s_ul->up = 0, s_ul->down = 0;
        s_ul->left = 0, s_ul->right = 0;
        return (-1);
    } return (res);
}

void backward(ul_t *s_ul)
{
    pos_t *temp = s_ul->head;
    s_ul->head = s_ul->head->next;
    if (temp->direction == 0) {
        s_ul->maze[temp->x][temp->y] = 'F';
    } if (temp->direction == 1) {
        s_ul->maze[temp->x][temp->y] = 'F';
    } if (temp->direction == 2) {
        s_ul->maze[temp->x][temp->y] = 'F';
    } if (temp->direction == 3) {
        s_ul->maze[temp->x][temp->y] = 'F';
    } free(temp);
    s_ul->left = 0, s_ul->right = 0, s_ul->down = 0, s_ul->up = 0;
}

void solve_maze(ul_t *s_ul)
{
    int direction = 0, res = 0, rnd = 0;
    s_ul->head = NULL;
    s_ul->column = strlen(s_ul->maze[0]);
    s_ul->head = foward(s_ul->head, 0, 0, -1);
    s_ul->maze[0][0] = 'o';
    while (1) {
        while (res != -1) {
            rnd = rand() % 1001;
            if (rnd < 500) direction = 1;
            if (rnd > 500 && rnd < 1000) direction = 2;
            res = dig(s_ul, direction);
        } if (s_ul->head->x == 0 && s_ul->head->y == 0) {
            s_ul->no = 1, s_ul->maze[0][0] = 's';
            break;
        } if (s_ul->head->x == s_ul->len - 1 &&
        s_ul->head->y == s_ul->column - 1) break;
        backward(s_ul), res = 0;
    }
}