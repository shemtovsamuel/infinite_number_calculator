/*
** EPITECH PROJECT, 2020
** handle_minus.c
** File description:
** handle_minus
*/

#include <stdlib.h>
#include "../include/my.h"

char **delete_element(char **arr, int index);

char found_operators_w_min(char c);

char found_before_min(char c);

static char **move_char(char **str_out, int *neg, int *p, int *i)
{
    for (int j = 1; j < *neg; j++)
        delete_element(str_out, *p + 1);
    if (str_out[*p + 1][0] != '(') {
        if (*neg % 2 != 0) {
            my_strcat(str_out[*p], str_out[*p + 1]);
            delete_element(str_out, *p + 1);
        } else
            delete_element(str_out, *p);
    }
    *neg = 0;
    *i = *p;
    return (str_out);
}

static void assign_pos(int *p, int *i, int *neg)
{
    *p = *i;
    (*neg)++;
}

static int handle_error(char **str_out, int *neg, int *i)
{
    if (str_out[*i - 1][0] == '-' && str_out[*i - 1][1] == '\0'
        && found_operators_w_min(str_out[*i][0]) != ' ') {
        delete_element(str_out, *i);
        *neg = 0;
        *i = 0;
        return (1);
    }
    return (0);
}

static void handle_minus_core(char **str_out, int neg, int p)
{
    for (int i = 1; str_out[i] != NULL; i++) {
        if (handle_error(str_out, &neg, &i) == 1)
            continue;
        if (str_out[i][0] == '-' && str_out[i][1] == '\0' && neg != 0) {
            neg++;
            continue;
        }
        if (str_out[i][0] != '-' && neg != 0) {
            str_out = move_char(str_out, &neg, &p, &i);
            continue;
        }
        if (str_out[i][0] == '-' && str_out[i][1] == '\0' && neg == 0
            && str_out[i - 1][0] == '-' && str_out[i - 1][1] == '\0'
            && str_out[i + 1][0] == '-' && str_out[i + 1][1] == '\0')
            assign_pos(&p, &i, &neg);
        else if (str_out[i][0] == '-' && neg == 0
            && str_out[i][1] == '\0'
            && found_before_min(str_out[i - 1][0]) != ' '
            && str_out[i - 1][1] == '\0')
            assign_pos(&p, &i, &neg);
    }
}

void handle_minus(char **str_out)
{
    int neg = 0;
    int p = 0;

    if (str_out[0][0] == '-')
        neg++;
    handle_minus_core(str_out, neg, p);
}
