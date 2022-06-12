/*
** EPITECH PROJECT, 2020
** eval_expr_calcul.c
** File description:
** eval_expr_calcul
*/

#include <stdlib.h>
#include "../include/my.h"

char **delete_element(char **arr, int index);

static char *delete_min(char *arr)
{
    for (int i = 0; arr[i + 1] != '\0'; i++) {
        arr[i] = arr[i + 1];
        arr[i + 1] = '\0';
    }
    return (arr);
}

static char **move_char(char **str_out, int i)
{
    if (str_out[i + 1][0] == '-') {
        delete_min(str_out[i + 1]);
        delete_element(str_out, i);
    } else if (str_out[i + 1][0] != '-' && str_out[i + 1][0] != '(') {
        my_strcat(str_out[i], str_out[i + 1]);
        delete_element(str_out, i + 1);
    }
    return (str_out);
}

void fix_min(char **str_out)
{
    for (int i = 0; str_out[i] != NULL; i++) {
        if (str_out[i][0] == '-' && str_out[i][1] == '\0') {
            if (i == 0) {
                str_out = move_char(str_out, i);
            } else if (str_out[i - 1][0] == '(') {
                str_out = move_char(str_out, i);
            }
        }
    }
}
