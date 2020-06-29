/*
** EPITECH PROJECT, 2020
** CPE_dante_2019
** File description:
** special
*/

#include "solver.h"

int special_right1(ul_t *s_ul, int *i, int *j)
{
    if (s_ul->maze[*i][*j + 1] == '*' &&
    (s_ul->maze[*i + 1][*j + 1] != '*')) {
        s_ul->maze[*i][*j + 1] = 'F', *j += 1;
        return (1);
    }
    if (s_ul->maze[*i][*j + 1] == '*' && s_ul->maze[*i][*j + 2] != '*' &&
    s_ul->maze[*i + 1][*j + 1] == '*') {
        s_ul->maze[*i][*j + 1] = 'F', *j += 1;
        return (1);
    } return (0);
}

int special_left1(ul_t *s_ul, int *i, int *j)
{
    if (s_ul->maze[*i][*j - 1] == '*' &&
    (s_ul->maze[*i + 1][*j - 1] != '*')) {
        s_ul->maze[*i][*j - 1] = 'F', *j -= 1;
        return (1);
    }
    if (s_ul->maze[*i][*j - 1] == '*' && s_ul->maze[*i][*j - 2] != '*' &&
    s_ul->maze[*i + 1][*j - 1] == '*') {
        s_ul->maze[*i][*j - 1] = 'F', *j -= 1;
        return (1);
    } return (0);
}

int special_right2(ul_t *s_ul, int *i, int *j)
{
    if (s_ul->maze[*i][*j + 1] == '*' &&
    (s_ul->maze[*i - 1][*j + 1] != '*')) {
        s_ul->maze[*i][*j + 1] = 'F', *j += 1;
        return (1);
    }
    if (s_ul->maze[*i][*j + 1] == '*' && s_ul->maze[*i][*j + 2] != '*' &&
    s_ul->maze[*i - 1][*j + 1] == '*' && s_ul->maze[*i][*j + 2] != '\0') {
        s_ul->maze[*i][*j + 1] = 'F', *j += 1;
        return (1);
    } return (0);
}

int special_left2(ul_t *s_ul, int *i, int *j)
{
    if (s_ul->maze[*i][*j - 1] == '*' &&
    (s_ul->maze[*i - 1][*j - 1] != '*')) {
        s_ul->maze[*i][*j - 1] = 'F', *j -= 1;
        return (1);
    }
    if (*j != 1) {
        if (s_ul->maze[*i][*j - 1] == '*' && s_ul->maze[*i][*j - 2] != '*' &&
        s_ul->maze[*i - 1][*j - 1] == '*') {
            s_ul->maze[*i][*j - 1] = 'F', *j -= 1;
            return (1);
        }
    } else {
        if (s_ul->maze[*i][*j - 1] == '*' &&
        s_ul->maze[*i - 1][*j - 1] == '*' && s_ul->maze[*i - 1][*j] != '*') {
            s_ul->maze[*i][*j - 1] = 'F', *j -= 1;
            return (1);
        }
    } return (0);
}

int corner(ul_t *s_ul, int *i, int *j)
{
    if (special_right2(s_ul, i, j))
        return (1);
    if (s_ul->maze[*i - 1][*j] == '*' && s_ul->maze[*i - 1][*j + 1] != '*') {
        s_ul->maze[*i - 1][*j] = 'F';
        *i -= 1;
        return (1);
    }
    return (0);
}