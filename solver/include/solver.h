/*
** EPITECH PROJECT, 2020
** CPE_dante_2019
** File description:
** solver
*/

#ifndef SOLVER_H_
#define SOLVER_H_
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <time.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>

typedef struct pos {
    int x, y, direction;
    struct pos *next;
} pos_t;

typedef struct ul {
    int no;
    char **maze;
    int len, left, right, up, down;
    int column;
    struct pos *head;
} ul_t;

char **load_map(char *filepath);
char *my_strdup(char *str);
void print_double_array(char **str);
void fill_dead_ends(ul_t *s_ul);
void find_dead_end_sub3(char **map, int i, int j, ul_t *s_ul);
void first_line_case(char **map, pos_t *s_pos, int x, int y);
void free_double_array(char **str);
char **clean_array(char **map);
void find_dead_ends(char **map, ul_t *s_ul);
void solver(char **map, ul_t *s_ul);
pos_t *foward(pos_t *old, int x, int y, int direction);
int my_ptr_len(char **str);
int down(ul_t *s_ul, int *i, int *j);
int up(ul_t *s_ul, int *i, int *j);
int left(ul_t *s_ul, int *i, int *j);
int right(ul_t *s_ul, int *i, int *j);
int special_right1(ul_t *s_ul, int *i, int *j);
int special_left1(ul_t *s_ul, int *i, int *j);
int special_right2(ul_t *s_ul, int *i, int *j);
int special_left2(ul_t *s_ul, int *i, int *j);
int solve(int i, int j, int t, ul_t *s_ul);
int corner(ul_t *s_ul, int *i, int *j);
int special_up(ul_t *s_ul, int *i, int *j);
int special_down(ul_t *s_ul, int *i, int *j);
int dig_left(ul_t *s_ul, int direction);
int dig_right(ul_t *s_ul, int direction);
int dig_up(ul_t *s_ul, int direction);
int dig_down(ul_t *s_ul, int direction);
void solve_maze(ul_t *s_ul);



#endif /* !SOLVER_H_ */
