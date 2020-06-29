/*
** EPITECH PROJECT, 2020
** CPE_dante_2019
** File description:
** dead_end2
*/

#include "solver.h"

void find_dead_end_sub3(char **map, int i, int j, ul_t *s_ul)
{
    if (i == s_ul->len - 1 && j == 0 && i != 0) {
        if (map[i][j] == '*' && map[i - 1][j] == 'X') {
            map[i][j] = 'F';
        } if (map[i][j] == '*' && map[i][j + 1] == 'X') {
            map[i][j] = 'F';
        }
    } if (i == s_ul->len - 1 && j != 0 && i != 0) {
        if ((map[i][j] == '*' && map[i - 1][j] == 'X') &&
        (map[i][j + 1] == 'X')) {
            map[i][j] = 'F';
        } if (map[i][j] == '*' && map[i - 1][j] == 'X' &&
        map[i][j - 1] == 'X') {
            map[i][j] = 'F';
        } if (map[i][j] == '*' && map[i][j - 1] == 'X' &&
        (map[i][j + 1] == 'X' && map[i][j + 1] != '\0')) {
            map[i][j] = 'F';
        }
    }
}
