/*
** EPITECH PROJECT, 2020
** util_infin_add.c
** File description:
** util_infin_add.c
*/

#include "../include/my.h"

int check_nb(char *n, char *d)
{
    if (my_strlen(n) > my_strlen(d))
        return (1);
    if (my_strlen(n) == my_strlen(d)) {
        if (my_strcmp(n, d) > 0)
            return (1);
        else if (my_strcmp(n, d) == 0)
            return (2);
    }
    return (0);
}

void min_ret_check(int ints[2])
{
    if (ints[0] < 0) {
        ints[0] = 9;
        ints[1] = 1;
    }
}
