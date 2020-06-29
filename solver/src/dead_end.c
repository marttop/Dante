/*
** EPITECH PROJECT, 2020
** CPE_dante_2019
** File description:
** dead_end
*/

#include "solver.h"

void find_dead_end_sub1(char **map, int i, int j, ul_t *s_ul)
{
    if (i == 0 && j != 0) {
        if (map[i][j] == '*' && map[i][j + 1] == 'X' &&
        map[i + 1][j] == 'X') {
            map[i][j] = 'F';
        } if (map[i][j] == '*' && map[i][j - 1] == 'X' &&
        map[i + 1][j] == 'X') {
            map[i][j] = 'F';
        } if (map[i][j] == '*' && map[i][j - 1] == 'X' &&
        map[i][j + 1] == 'X') map[i][j] = 'F';
    } if ((i != 0 && i != s_ul->len - 1) && j == 0) {
        if (map[i][j] == '*' && map[i - 1][j] == 'X' &&
        map[i - 1][j + 1] == 'X' && map[i][j + 1] == 'X') {
            map[i][j] = 'F';
        } if (map[i][j] == '*' && map[i + 1][j] == 'X' &&
        map[i + 1][j + 1] == 'X' && map[i][j + 1] == 'X') {
            map[i][j] = 'F';
        } if (map[i][j] == '*' && map[i + 1][j] == 'X' &&
        map[i - 1][j] == 'X')
            map[i][j] = 'F';
    }
}

void find_dead_end_sub2(char **map, int i, int j, ul_t *s_ul)
{
    if (i != 0 && j != 0 && i != s_ul->len - 1) {
        if (map[i][j] == '*' && map[i][j + 1] == 'X' &&
        map[i + 1][j] == 'X' && map[i - 1][j] == 'X') {
            map[i][j] = 'F';
        } if (map[i][j] == '*' && map[i][j - 1] == 'X' &&
        map[i + 1][j] == 'X' && map[i - 1][j] == 'X') {
            map[i][j] = 'F';
        } if (map[i][j] == '*' && map[i + 1][j] == 'X' &&
        map[i + 1][j + 1] == 'X' && map[i + 1][j - 1] == 'X' &&
        map[i][j + 1] == 'X' && map[i][j - 1] == 'X') {
            map[i][j] = 'F';
        } if (map[i][j] == '*' && map[i - 1][j] == 'X' &&
        map[i][j + 1] == 'X' && map[i][j - 1] == 'X') {
            map[i][j] = 'F';
        }
    }
}

void find_dead_ends(char **map, ul_t *s_ul)
{
    s_ul->len = my_ptr_len(map);
    for (int i = 0; map[i] != NULL; i++) {
        for (int j = 0; map[i][j] != '\0'; j++) {
            find_dead_end_sub1(map, i, j, s_ul);
            find_dead_end_sub2(map, i, j, s_ul);
            find_dead_end_sub3(map, i, j, s_ul);
        }
    }
}