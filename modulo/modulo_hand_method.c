/*
** EPITECH PROJECT, 2020
** modulo_hand_method.c
** File description:
** modulo_hand_method.c
*/

#include <stdlib.h>
#include "my.h"

void to_string(char str[], int num);

static int get_n(char *nb, char *d, int len_d)
{
    int i = 0;
    char *n = malloc(sizeof(char) * 2 + 1);
    int check = my_strncmp(nb, d, len_d);

    if (check == 0 || check > 0) {
        while (i < len_d) {
            n[i] = nb[i];
            i++;
        }
    }
    else {
        while (i < len_d + 1) {
            n[i] = nb[i];
            i++;
        }
    }
    return (my_getnbr(n));
}

static char *mod(char const *nb, int n, int const d, int const len_d)
{
    int len_nb = my_strlen(nb);
    int len_n = 0;
    int n_temp = n;
    char *mod = malloc(sizeof(char) * (len_d + len_nb) + 1);
    int R = 0;
    int next_nb = CTOI(nb[len_d + 1]);

    while (n_temp != 0) {
        len_n++;
        n_temp = n_temp / 10;
    }
    R = n % d;
    for (int i = 1; i != (len_nb - (len_n - 1)); i++) {
        n = R;
        next_nb = CTOI(nb[len_d + i]);
        R = n * 10 + next_nb;
        R = R % d;
    }
    to_string(mod, R);
    return (mod);
}

char *exec_modulo_hand(char const *nb, char const *d)
{
    int len_d = my_strlen(d);
    int n = get_n(nb, d, len_d);
    int di = my_getnbr(d);

    return (mod(nb, n, di, len_d));
}
