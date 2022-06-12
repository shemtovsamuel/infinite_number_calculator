/*
** EPITECH PROJECT, 2020
** infin_add.c
** File description:
** Infin add
*/

#include <stdlib.h>
#include "../include/my.h"

char *add(char const *nb1, char const *nb2, int neg);

char *min(char const *nb1, char const *nb2, int neg);

static int is_neg(char const *str)
{
    int i = 0;
    int neg = 0;
    int is_neg = 0;

    while (str[i] != '\0' && str[i] == '-') {
        neg++;
        i++;
    }
    if (neg % 2 != 0)
        is_neg = 1;
    return (is_neg);
}

char *check_infin_add(char *nb1, char *nb2)
{
    if (!is_neg(nb1) && !is_neg(nb2))
        return (add(my_revstr(nb1), my_revstr(nb2), 0));
    if (is_neg(nb1) && !is_neg(nb2)) {
        nb1++;
        return (min(nb1, nb2, 0));
    }
    if (!is_neg(nb1) && is_neg(nb2)) {
        nb2++;
        return (min(nb1, nb2, 1));
    }
    if (is_neg(nb1) && is_neg(nb2)) {
        nb1++;
        nb2++;
        return (add(my_revstr(nb1), my_revstr(nb2), 1));
    }
    return (NULL);
}

char *check_infin_min(char *nb1, char *nb2)
{
    if (!is_neg(nb1) && !is_neg(nb2))
        return (min(nb1, nb2, 1));
    if (is_neg(nb1) && !is_neg(nb2)) {
        nb1++;
        return (add(my_revstr(nb1), my_revstr(nb2), 1));
    }
    if (!is_neg(nb1) && is_neg(nb2)) {
        nb2++;
        return (add(my_revstr(nb1), my_revstr(nb2), 0));
    }
    if (is_neg(nb1) && is_neg(nb2)) {
        nb1++;
        nb2++;
        return (min(nb1, nb2, 1));
    }
    return (NULL);
}
