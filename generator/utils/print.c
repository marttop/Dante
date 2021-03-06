/*
** EPITECH PROJECT, 2020
** CPE_dante_2019
** File description:
** print
*/

#include "generator.h"

void print_double_array(char **str)
{
    for (int i = 0; str[i] != NULL; i++) {
        printf("%s", str[i]);
        if (str[i + 1] != NULL)
            printf("%c", '\n');
    }
}

void free_double_array(char **str)
{
    for (int i = 0; str[i] != NULL; i++) {
        free(str[i]);
    }
    free(str);
}