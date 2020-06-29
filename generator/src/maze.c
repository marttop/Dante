/*
** EPITECH PROJECT, 2020
** CPE_dante_2019
** File description:
** maze
*/

#include "generator.h"

pos_t *foward(pos_t *old, int x, int y, int direction)
{
    pos_t *new = malloc(sizeof(pos_t));
    new->x = x;
    new->y = y;
    new->direction = direction;
    new->next = old;
    return (new);
}

void backward(ul_t *s_ul)
{
    pos_t *temp = s_ul->head;
    s_ul->head = s_ul->head->next;
    if (temp->direction == 0) {
        s_ul->maze[temp->x][temp->y] = '*';
        s_ul->maze[temp->x + 1][temp->y] = '*';
        s_ul->maze[temp->x + 2][temp->y] = '*';
    } if (temp->direction == 1) {
        s_ul->maze[temp->x][temp->y] = '*';
        s_ul->maze[temp->x][temp->y - 1] = '*';
        s_ul->maze[temp->x][temp->y - 2] = '*';
    } if (temp->direction == 2) {
        s_ul->maze[temp->x][temp->y] = '*';
        s_ul->maze[temp->x - 1][temp->y] = '*';
        s_ul->maze[temp->x - 2][temp->y] = '*';
    } if (temp->direction == 3) {
        s_ul->maze[temp->x][temp->y] = '*';
        s_ul->maze[temp->x][temp->y + 1] = '*';
        s_ul->maze[temp->x][temp->y + 2] = '*';
    } free(temp);
    s_ul->left = 0, s_ul->right = 0, s_ul->down = 0, s_ul->up = 0;
}

int dig(ul_t *s_ul, int direction)
{
    int res = 0;
    if (direction == 0) {
        if (s_ul->up != 1) res = dig_up(s_ul, direction);
        else direction = 1;
    } if (direction == 1) {
        if (s_ul->right != 1) res = dig_right(s_ul, direction);
        else direction = 2;
    } if (direction == 2) {
        if (s_ul->down != 1) res = dig_down(s_ul, direction);
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

void get_end(ul_t *s_ul)
{
    s_ul->maze[s_ul->line - 1][s_ul->column - 1] = '*';
    if (s_ul->line % 2 == 0 && s_ul->column % 2 == 0)
        s_ul->maze[s_ul->line - 2][s_ul->column - 1] = '*';
}

void maze(ul_t *s_ul)
{
    int direction, res = 0;
    s_ul->head = NULL;
    s_ul->head = foward(s_ul->head, 0, 0, -1);
    s_ul->maze[0][0] = '*';
    while (s_ul->head != NULL) {
        while (res != -1) {
            direction = rand() % 4;
            res = dig(s_ul, direction);
        }
        backward(s_ul);
        res = 0;
    }
    get_end(s_ul);
}