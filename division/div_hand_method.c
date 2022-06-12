/*
** EPITECH PROJECT, 2020
** div_hand_method.c
** File description:
** div_hand_method.c
*/

#include <stdlib.h>
#include "../include/my.h"

static int get_n(char const *nb, char const *d, int const len_d)
{
    int i = 0;
    char *n = malloc(sizeof(char) * 2 + 1);
    int check = my_strncmp(nb, d, len_d);

    if (check == 0 || check > 0) {
        while (i < len_d) {
            n[i] = nb[i];
            i++;
        }
    } else {
        while (i < len_d + 1) {
            n[i] = nb[i];
            i++;
        }
    }
    return (my_getnbr(n));
}

static int check_next_nb(int len_d, char const *nb, int i)
{
    int next_nb = 0;

    if (len_d == 1)
        next_nb = CTOI(nb[i]);
    else
        next_nb = CTOI(nb[len_d + i]);
    return (next_nb);
}

static char *divide(char const *nb, int n, int const d, int const len_d)
{
    int len_nb = my_strlen(nb);
    int len_n = 0;
    int n_temp = n;
    char *res = malloc(sizeof(char) * (len_d + len_nb) + 1);
    int R = 0;
    int next_nb = check_next_nb(len_d, nb, 1);

    while (n_temp != 0) {
        len_n++;
        n_temp = n_temp / 10;
    }
    res[0] = ITOC(n / d);
    R = n % d;
    for (int i = 1; i != (len_nb - (len_n - 1)); i++) {
        n = R;
        next_nb = check_next_nb(len_d, nb, i);
        R = n * 10 + next_nb;
        res[i] = ITOC(R / d);
        R = R % d;
    }
    return (res);
}

char *exec_div_hand(char const *nb, char const *d)
{
    int len_d = my_strlen(d);
    int n = get_n(nb, d, len_d);
    int di = my_getnbr(d);

    return (divide(nb, n, di, len_d));
}
