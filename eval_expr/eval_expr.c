/*
** EPITECH PROJECT, 2020
** eval_expr.c
** File description:
** eval_expr
*/

#include <stdlib.h>
#include "../include/bistromatic.h"
#include "../include/my.h"

char found_operator(char *str);

void handle_minus(char **str_out);

char *my_strtol(char *str, char **endptr);

void eval_expr_calcul(char **str);

static int handle_error_syntax(char **str_out)
{
    for (int i = 0; str_out[i] != NULL; i++) {
        if (my_str_isnum(str_out[i])) {
            if ((str_out[i + 1] != NULL && str_out[i + 1][0] == '(')
                || (i != 0 && str_out[i - 1][0] == ')'))
                return (1);
        }
    }
    return (0);
}

char *eval_expr(char const *base, char const *ops, char *expr,
                unsigned int size)
{
    char **str_ope = malloc(sizeof(char *) * my_strlen(expr) + 1);
    char **str_out = malloc(sizeof(char *) * my_strlen(expr) + 1);
    char *ptr;
    int j = 0;
    int nb_ope = 0;

    for (int i = 0; *expr != '\0'; i++) {
        str_out[i] = malloc(sizeof(char) * my_strlen(expr));
        str_out[i] = my_strtol(expr, &ptr);
        if (found_operator(str_out[i]) != ' ')
            str_ope[j++] = str_out[i];
        expr = my_strdup(ptr);
    }
    if (handle_error_syntax(str_out) == 1)
        return (SYNTAX_ERROR_MSG);
    handle_minus(str_out);
    for (; str_ope[nb_ope] != NULL; nb_ope++);
    for (int i = 0; i < nb_ope; i++)
        eval_expr_calcul(str_out);
    return (str_out[0]);
}
