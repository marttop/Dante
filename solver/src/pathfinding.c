/*
** EPITECH PROJECT, 2020
** CPE_dante_2019
** File description:
** pathfinding
*/

#include "solver.h"

void fill(ul_t *s_ul, int i, int j)
{
    int t = 1;
    for (; t != 0;) {
        t = 0;
        t += solve(i, j, t, s_ul);
        if (i == s_ul->len - 1 && j != 0) {
            t += up(s_ul, &i, &j);
            if (t == 1) continue;
            t += special_left2(s_ul, &i, &j);
            if (t == 1) continue;
            t += special_right2(s_ul, &i, &j);
        } if (i != 0 && i != s_ul->len - 1 && j == 0) {
            t += special_up(s_ul, &i, &j);
            if (t == 1) continue;
            t += special_down(s_ul, &i, &j);
            if (t == 1) continue;
            t += right(s_ul, &i, &j);
        } if (i == s_ul->len - 1 && j == 0)
            t += corner(s_ul, &i, &j);
    }
}

int special_up(ul_t *s_ul, int *i, int *j)
{
    if (s_ul->maze[*i - 1][*j] == '*' &&
    (s_ul->maze[*i - 1][*j + 1] != '*' || s_ul->maze[*i - 2][*j] != '*')) {
        s_ul->maze[*i - 1][*j] = 'F', *i -= 1;
        return (1);
    } return (0);
}

void print_path(ul_t *s_ul)
{
    solve_maze(s_ul);
    for (int i = 0; s_ul->maze[i] != NULL; i++) {
        for (int j = 0; s_ul->maze[i][j] != '\0'; j++) {
            if (s_ul->maze[i][j] == 'F')
                s_ul->maze[i][j] = '*';
        }
    }
    if (s_ul->no == 1) {
        printf("no solution found");
        free_double_array(s_ul->maze);
    } else {
        print_double_array(s_ul->maze);
        free_double_array(s_ul->maze);
    }
}

void fill_dead_ends(ul_t *s_ul)
{
    for (int i = 0; s_ul->maze[i] != NULL; i++) {
        for (int j = 0; s_ul->maze[i][j] != '\0'; j++) {
            if (s_ul->maze[i][j] == 'F') {
                fill(s_ul, i, j);
            }
        }
    } print_path(s_ul);
}