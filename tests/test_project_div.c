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

Test(eval_expr, div_very_big)
{
    char const *base = "0123456789";
    char const *ops = "()+-*/%";
    char *expr1 = "254548648974689789/486547867486468586";
    char *expr2 = "254548648974689789/4865478674864685";

    cr_assert_str_eq(eval_expr(base, ops, expr1, 0), "0");
    cr_assert_str_eq(eval_expr(base, ops, expr2, 0), "52");
}

Test(eval_expr, div_very_big_two_min)
{
    char const *base = "0123456789";
    char const *ops = "()+-*/%";
    char *expr1 = "-254548648974689789/4865478674864685";
    char *expr2 = "-254548648974689789/-4865478674864685";

    cr_assert_str_eq(eval_expr(base, ops, expr1, 0), "-52");
    cr_assert_str_eq(eval_expr(base, ops, expr2, 0), "52");
}

Test(eval_expr, div_max_int_size)
{
    char const *base = "0123456789";
    char const *ops = "()+-*/%";
    char *expr1 = "21474836473/2149483647";
    char *expr2 = "2147483647/2147483647";
    char *expr3 = "2147483649/2147483647";
    char *expr4 = "214748364946/2147483647";

    cr_assert_str_eq(eval_expr(base, ops, expr1, 0), "9");
    cr_assert_str_eq(eval_expr(base, ops, expr2, 0), "1");
    cr_assert_str_eq(eval_expr(base, ops, expr3, 0), "1");
    cr_assert_str_eq(eval_expr(base, ops, expr4, 0), "100");
}

Test(eval_expr, div_small_medium)
{
    char const *base = "0123456789";
    char const *ops = "()+-*/%";
    char *expr1 = "0/1";
    char *expr2 = "1/1";
    char *expr3 = "55/7";
    char *expr4 = "473/53";
    char *expr5 = "47900/192";

    cr_assert_str_eq(eval_expr(base, ops, expr1, 0), "0");
    cr_assert_str_eq(eval_expr(base, ops, expr2, 0), "1");
    cr_assert_str_eq(eval_expr(base, ops, expr3, 0), "7");
    cr_assert_str_eq(eval_expr(base, ops, expr4, 0), "8");
    cr_assert_str_eq(eval_expr(base, ops, expr5, 0), "249");
}

Test(eval_expr, div_very_small_medium_min)
{
    char const *base = "0123456789";
    char const *ops = "()+-*/%";
    char *expr1 = "-1/1";
    char *expr2 = "-55/-7";
    char *expr3 = "-473/53";
    char *expr4 = "47900/-192";

    cr_assert_str_eq(eval_expr(base, ops, expr1, 0), "-1");
    cr_assert_str_eq(eval_expr(base, ops, expr2, 0), "7");
    cr_assert_str_eq(eval_expr(base, ops, expr3, 0), "-8");
    cr_assert_str_eq(eval_expr(base, ops, expr4, 0), "-249");
}