/*
** EPITECH PROJECT, 2020
** my_strtol.c
** File description:
** my_strtol
*/

#include <stdlib.h>
#include "../include/my.h"

int isnum(char const c);

static char **my_strtol_core(char **strs, int i)
{
    if (isnum(*strs[0])) {
        strs[1] = strs[0];
        while (isnum(*strs[0])) {
            strs[2][i] = *strs[0];
            strs[0]++;
            i++;
        }
    } else if (*strs[0] == '/' || *strs[0] == '*'
    || *strs[0] == '+' || *strs[0] == '-' || *strs[0] == '%') {
        *strs[2] = *strs[0];
        strs[0]++;
    } else
        *strs[2] = *strs[0];
    if (*strs[2] == '(')
        strs[0]++;
    else if (*strs[2] == ')')
        strs[0]++;
    return (strs);
}

char *my_strtol(char *str, char **endptr)
{
    char **strs = malloc(sizeof(char *) * 3 + 1);
    strs[0] = str;
    strs[1] = NULL;
    strs[2] = NULL;
    int i = 0;
    int neg = 0;

    for (; *strs[0] == ' '; strs[0]++);
    for (; strs[0][neg] == '-'; neg++);
    for (; isnum(strs[0][i]); i++);
    strs[2] = malloc(sizeof(char) * i + 1);
    i = 0;
    strs = my_strtol_core(strs, i);
    if (endptr != 0)
        *endptr = (char *)(strs[0]);
    return (strs[2]);
}
