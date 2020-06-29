/*
** EPITECH PROJECT, 2020
** CPE_dante_2019
** File description:
** test_generator
*/

#include "generator.h"
#include <criterion/criterion.h>

Test(general_test, test1)
{
    ul_t s_ul = {0};
    s_ul.column = 20, s_ul.line = 20;
    s_ul.maze = generate_maze(&s_ul);
    maze(&s_ul);
    free_double_array(s_ul.maze);
    cr_assert_eq(s_ul.head, NULL);
}

Test(get_int_test, test2)
{
    int pos = get_int("155");
    int neg = get_int("-541");
    cr_assert_eq(pos, 155);
    cr_assert_eq(neg, -541);
}