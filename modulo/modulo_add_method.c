/*
** EPITECH PROJECT, 2020
** modulo_add_method.c
** File description:
** modulo_add_method.c
*/

#include <stdlib.h>
#include "my.h"

char *min(char const *nb1, char const *nb2, int neg);

char *add(char const *nb1, char const *nb2, int neg);

int check_nb(char *n, char *d);

char *exec_modulo_add(char *nb, char *d)
{
    char *str = malloc(sizeof(char) * (my_strlen(nb) + my_strlen(d) + 1));
    char *d_cpy = my_strdup(d);

    while (check_nb(nb, d) == 1) {
        str = add(my_revstr(str), "1", 0);
        nb = min(nb, d, 1);
        d = my_strcpy(d, d_cpy);
    }
    if (check_nb(nb, d) == 2)
        str = add(my_revstr(str), "1", 0);
    return (nb);
}
