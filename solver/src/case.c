/*
** EPITECH PROJECT, 2020
** CPE_dante_2019
** File description:
** case
*/

#include "solver.h"

int up(ul_t *s_ul, int *i, int *j)
{
    if (*i == 1) {
        if (s_ul->maze[*i - 1][*j] == '*' &&
        (s_ul->maze[*i - 1][*j - 1] != '*' ||
        s_ul->maze[*i - 1][*j + 1] != '*')) {
            s_ul->maze[*i - 1][*j] = 'F', *i -= 1;
            return (1);
        } return (0);
    } if (s_ul->maze[*i - 1][*j] == '*' && s_ul->maze[*i - 1][*j + 1] != '*' &&
    s_ul->maze[*i - 1][*j - 1] != '*') {
        s_ul->maze[*i - 1][*j] = 'F', *i -= 1;
        return (1);
    }
    if (s_ul->maze[*i - 1][*j] == '*' && s_ul->maze[*i - 2][*j] != '*' &&
    (s_ul->maze[*i - 1][*j - 1] != '*' || s_ul->maze[*i - 1][*j + 1] != '*')) {
        s_ul->maze[*i - 1][*j] = 'F', *i -= 1;
        return (1);
    } return (0);
}

int down(ul_t *s_ul, int *i, int *j)
{
    if (*i == s_ul->len - 2) {
        if (s_ul->maze[*i + 1][*j] == '*' &&
        (s_ul->maze[*i + 1][*j + 1] != '*' ||
        s_ul->maze[*i + 1][*j - 1] != '*')) {
            s_ul->maze[*i + 1][*j] = 'F', *i += 1;
            return (1);
        } return (0);
    }
    if (s_ul->maze[*i + 1][*j] == '*' && s_ul->maze[*i + 1][*j + 1] != '*' &&
    s_ul->maze[*i + 1][*j - 1] != '*') {
        s_ul->maze[*i + 1][*j] = 'F', *i += 1;
        return (1);
    }
    if (s_ul->maze[*i + 1][*j] == '*' && s_ul->maze[*i + 2][*j] != '*' &&
    (s_ul->maze[*i + 1][*j + 1] != '*' || s_ul->maze[*i + 1][*j - 1] != '*')) {
        s_ul->maze[*i + 1][*j] = 'F', *i += 1;
        return (1);
    } return (0);
}

int left(ul_t *s_ul, int *i, int *j)
{
    if (*j == 1) {
        if (s_ul->maze[*i][*j - 1] == '*' &&
        (s_ul->maze[*i - 1][*j - 1] != '*' ||
        s_ul->maze[*i + 1][*j - 1] != '*')) {
            s_ul->maze[*i][*j - 1] = 'F', *j -= 1;
            return (1);
        } return (0);
    }
    if (s_ul->maze[*i][*j - 1] == '*' && s_ul->maze[*i + 1][*j - 1] != '*' &&
    s_ul->maze[*i - 1][*j - 1] != '*') {
        s_ul->maze[*i][*j - 1] = 'F', *j -= 1;
        return (1);
    }
    if (s_ul->maze[*i][*j - 1] == '*' && s_ul->maze[*i][*j - 2] != '*' &&
    (s_ul->maze[*i - 1][*j - 1] != '*' || s_ul->maze[*i + 1][*j - 1] != '*')) {
        s_ul->maze[*i][*j - 1] = 'F', *j -= 1;
        return (1);
    } return (0);
}

int right(ul_t *s_ul, int *i, int *j)
{
    if (s_ul->maze[*i][*j + 1] == '*' && s_ul->maze[*i + 1][*j + 1] == '*' &&
    s_ul->maze[*i - 1][*j + 1] != '*' && s_ul->maze[*i][*j + 2] != '*') {
        s_ul->maze[*i][*j + 1] = 'F', *j += 1;
        return (1);
    }
    if (s_ul->maze[*i][*j + 1] == '*' && s_ul->maze[*i + 1][*j + 1] != '*' &&
    s_ul->maze[*i - 1][*j + 1] == '*' && s_ul->maze[*i][*j + 2] != '*') {
        s_ul->maze[*i][*j + 1] = 'F', *j += 1;
        return (1);
    }
    if (s_ul->maze[*i][*j + 1] == '*' && s_ul->maze[*i + 1][*j + 1] != '*' &&
    s_ul->maze[*i - 1][*j + 1] != '*') {
        s_ul->maze[*i][*j + 1] = 'F', *j += 1;
        return (1);
    } return (0);
}

int special_down(ul_t *s_ul, int *i, int *j)
{
    if (*i == s_ul->len - 2) {
        if (s_ul->maze[*i + 1][*j] == '*' &&
        (s_ul->maze[*i + 1][*j + 1] == '*' && s_ul->maze[*i][*j + 1] != '*')) {
            s_ul->maze[*i + 1][*j] = 'F', *i += 1;
            return (1);
        } return (0);
    }
    else {
        if (s_ul->maze[*i + 1][*j] == '*' && s_ul->maze[*i][*j + 1] != '*' &&
        s_ul->maze[*i + 1][*j + 1] != '*') {
            s_ul->maze[*i + 1][*j] = 'F', *i += 1;
            return (1);
        }
        if (s_ul->maze[*i + 1][*j] == '*' && s_ul->maze[*i][*j + 1] != '*' &&
        s_ul->maze[*i + 1][*j + 1] == '*' && s_ul->maze[*i + 2][*j] != '*') {
            s_ul->maze[*i + 1][*j] = 'F', *i += 1;
            return (1);
        }
    } return (0);
}