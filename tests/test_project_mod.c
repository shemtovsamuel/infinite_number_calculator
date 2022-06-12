/*
** EPITECH PROJECT, 2020
** unit_test
** File description:
** unit_test
*/

#include <criterion/criterion.h>
#include "../include/my.h"

char *eval_expr(char const *base, char const *ops,
char const *expr, unsigned int size);

Test(eval_expr, mod_very_big_one)
{
    char const *base = "0123456789";
    char const *ops = "()+-*/%";
    char *expr = "254548648974689789%486547867486468586";

    cr_assert_str_eq(eval_expr(base, ops, expr, 0), "254548648974689789");
}

Test(eval_expr, mod_very_big_two)
{
    char const *base = "0123456789";
    char const *ops = "()+-*/%";
    char *expr = "254548648974689789%4865478674864685";

    cr_assert_str_eq(eval_expr(base, ops, expr, 0), "1543757881726169");
}

Test(eval_expr, mod_very_big_two_min)
{
    char const *base = "0123456789";
    char const *ops = "()+-*/%";
    char *expr = "-254548648974689789%4865478674864685";

    cr_assert_str_eq(eval_expr(base, ops, expr, 0), "-1543757881726169");
}

Test(eval_expr, mod_very_big_two_min_both)
{
    char const *base = "0123456789";
    char const *ops = "()+-*/%";
    char *expr = "-254548648974689789%-4865478674864685";

    cr_assert_str_eq(eval_expr(base, ops, expr, 0), "-1543757881726169");
}

Test(eval_expr, mod_max_int_size)
{
    char const *base = "0123456789";
    char const *ops = "()+-*/%";
    char *expr = "21474836473%2149483647";

    cr_assert_str_eq(eval_expr(base, ops, expr, 0), "2129483650");
}