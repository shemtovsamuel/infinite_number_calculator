/*
** EPITECH PROJECT, 2020
** eval_expr_calcul.c
** File description:
** eval_expr_calcul
*/

#include <stdlib.h>
#include "../include/my.h"

char **delete_element(char **arr, int index);

void to_string(char str[], int num);

void fix_min(char **str_out);

int getnbrf(char const *str);

char *calcul(char *nb1, char *nb2, char operator);

static void delete_parenthesis(char **str)
{
    for (int i = 0; str[i] != NULL && str[i + 2] != NULL; i++) {
        if (str[i][0] == '(' && str[i + 2][0] == ')') {
            delete_element(str, i + 2);
            delete_element(str, i);
            break;
        }
    }
}

static int depth(char **str)
{
    int p = 0;

    for (int i = 0; str[i + 1] != NULL; i++)
        if (str[i][0] == '(')
            p = i + 1;
    return (p);
}

static void calcul_high(char **str, char *res, int *p, int *stop)
{
    for (int i = 0; str[*p + i + 1] != NULL && str[*p + i][0] != ')'; i++) {
        if (str[*p + i][0] == '*' || str[*p + i][0] == '/'
        || str[*p + i][0] == '%') {
            res = calcul(str[*p + i - 1], str[*p + i + 1], str[*p + i][0]);
            str = delete_element(str, *p + i);
            str = delete_element(str, *p + i - 1);
            if (res == NULL)
                *str[*p + i - 1] = '0';
            else
                my_strcpy(str[*p + i - 1], res);
            i = 0;
            *stop = 1;
            break;
        }
    }
}

static void calcul_low(char **str, char *res, int *p, int *i)
{
    res = calcul(str[*p + *i - 1], str[*p + *i + 1], str[*p + *i][0]);
    str = delete_element(str, *p + *i);
    str = delete_element(str, *p + *i - 1);
    if (res == NULL)
        *str[*p + *i - 1] = '0';
    else
        my_strcpy(str[*p + *i - 1], res);
    *i = 0;
}

void eval_expr_calcul(char **str)
{
    int p = 0;
    char *res = NULL;
    int stop = 0;

    delete_parenthesis(str);
    fix_min(str);
    p = depth(str);
    for (int i = 0; str[p + i + 1] != NULL
                    && str[p + i][0] != ')' && !stop; i++) {
        calcul_high(str, res, &p, &stop);
        if (str[p + i][0] == '+' || (str[p + i][0] == '-'
            && str[p + i][1] == '\0')) {
            calcul_low(str, res, &p, &i);
            stop = 1;
            break;
        }
    }
    delete_parenthesis(str);
}