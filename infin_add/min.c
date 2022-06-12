/*
** EPITECH PROJECT, 2020
** min.c
** File description:
** Infin add
*/

#include <stdlib.h>
#include "../include/my.h"

int check_nb(char *n, char *d);

void min_ret_check(int ints[2]);

static void remove_zero(char *str)
{
    int i = my_strlen(str) - 1;
    int found = 0;

    if (str[i] == '-' && str[i - 1] == '0') {
        str[i - 1] = str[i];
        str[i] = '\0';
        i = i - 2;
    }
    if (str[i] != '0')
        return;
    while (i > 1 && found == 0) {
        if (str[i] == '0') {
            str[i] = str[i - 1];
            if (str[i - 1] != '0')
                found = 1;
            else
                i--;
        } else
            i--;
    }
    str[i] = '\0';
}

static char *end_str(char **strs, int i, int neg)
{
    if (check_nb(strs[2], strs[3]) == 1) {
        if (neg == 0) {
            strs[4][i] = '-';
            strs[4][i + 1] = '\0';
        } else if (neg == 1)
            strs[4][i] = '\0';
    } else if (check_nb(strs[2], strs[3]) == 0) {
        if (neg == 1) {
            strs[4][i] = '-';
            strs[4][i + 1] = '\0';
        } else if (neg == 0)
            strs[4][i] = '\0';
    } else
        strs[4][i] = '\0';
    return (strs[4]);
}

static int *calcul_into(char **strs, int *ints, int i)
{
    if (check_nb(strs[2], strs[3]) == 1) {
        if (CTOI(strs[0][i]) >= CTOI(strs[1][i])) {
            ints[0] = - ints[1] + CTOI(strs[0][i]) - CTOI(strs[1][i]);
            ints[1] = 0;
        } else if (CTOI(strs[0][i]) < CTOI(strs[1][i])) {
            ints[0] = - ints[1] + (10 + CTOI(strs[0][i])) - CTOI(strs[1][i]);
            ints[1] = 1;
        }
    } else if (check_nb(strs[2], strs[3]) == 0) {
        if (CTOI(strs[0][i]) <= CTOI(strs[1][i])) {
            ints[0] = - ints[1] - CTOI(strs[0][i]) + CTOI(strs[1][i]);
            ints[1] = 0;
        } else if (CTOI(strs[0][i]) > CTOI(strs[1][i])) {
            ints[0] = - ints[1] - CTOI(strs[0][i]) + (10 + CTOI(strs[1][i]));
            ints[1] = 1;
        }
    }
    return (ints);
}

static char *calcul_min(char **strs, int i, int max_size, int neg)
{
    int ints[2] = { 0 };
    int *int_temp;

    for (i = 0; i < max_size; i++) {
        if (my_strlen(strs[0]) - 1 < i &&  my_strlen(strs[1]) > i) {
            ints[0] = - ints[1] + CTOI(strs[1][i]);
            ints[1] = 0;
        } else if (my_strlen(strs[0]) > i && my_strlen(strs[1]) - 1 < i) {
            ints[0] = - ints[1] + CTOI(strs[0][i]);
            ints[1] = 0;
        } else {
            int_temp = calcul_into(strs, ints, i);
            ints[0] = int_temp[0];
            ints[1] = int_temp[1];
        }
        min_ret_check(&ints);
        strs[4][i] = ITOC(ints[0] % 10);
    }
    return (end_str(strs, i, neg));
}

char *min(char *nb1, char *nb2, int neg)
{
    char *nb1_cpy = my_strdup(nb1);
    char *nb2_cpy = my_strdup(nb2);
    int i = 0;
    int max_size = MAX(my_strlen(nb1), my_strlen(nb2));
    char *str = malloc(sizeof(char) * (my_strlen(nb1) + my_strlen(nb2)) + 3);
    char *strs[5] = { nb1, nb2, nb1_cpy, nb2_cpy, str};

    my_revstr(nb1);
    my_revstr(nb2);
    str = calcul_min(strs, i, max_size, neg);
    remove_zero(str);
    my_revstr(str);
    return (str);
}
