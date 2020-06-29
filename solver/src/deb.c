/*
** EPITECH PROJECT, 2020
** CPE_dante_2019
** File description:
** deb
*/

#include "solver.h"

int solve(int i, int j, int t, ul_t *s_ul)
{
    if (i == 0 && j != 0 && t != 1) {
        t += down(s_ul, &i, &j);
        if (t == 1) return (1);
        t += special_left1(s_ul, &i, &j);
        if (t == 1) return (1);
        t += special_right1(s_ul, &i, &j);
    }
    if (i != 0 && j != 0 && i != s_ul->len - 1) {
        t += up(s_ul, &i, &j);
        if (t == 1) return (1);
        t += down(s_ul, &i, &j);
        if (t == 1) return (1);
        t += left(s_ul, &i, &j);
        if (t == 1) return (1);
        t += right(s_ul, &i, &j);
    }
    return (t);
}