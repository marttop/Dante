/*
** EPITECH PROJECT, 2020
** CPE_dante_2019
** File description:
** my
*/

#ifndef GENERATOR_H_
#define GENERATOR_H_
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

typedef struct pos {
    int x, y, direction;
    struct pos *next;
} pos_t;

typedef struct ul {
    int line, column;
    char **maze;
    int up, down, left, right;
    struct pos *head;
} ul_t;

int get_int(char *av);
char **generate_maze(ul_t *s_ul);
void maze(ul_t  *s_ul);
void print_double_array(char **str);
void free_double_array(char **str);
pos_t *foward(pos_t *old, int x, int y, int direction);
int dig_up(ul_t *s_ul, int direction);
int dig_right(ul_t *s_ul, int direction);
int dig_down(ul_t *s_ul, int direction);
int dig_left(ul_t *s_ul, int direction);

#endif /* !GEERATOR_H_ */
