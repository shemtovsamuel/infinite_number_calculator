/*
** EPITECH PROJECT, 2020
** add.c
** File description:
** Infin add
*/

#include <stdlib.h>
#include "../include/my.h"

static char *add_min_element(char *arr, int index, char c_to_add, int neg)
{
    int size = 0;
    if (neg == 1) {
        for (; arr[size] != '\0'; size++);
        for (int i = size; i >= index; i--)
            arr[i] = arr[i - 1];
        arr[index] = c_to_add;
    }
    return (arr);
}

static int calcul_ret(int result, int ret)
{
    if (result == 10)
        ret = 1;
    else if (result > 10)
        ret = result / 10;
    else
        ret = 0;
    return (ret);
}

char *add(char const *nb1, char const *nb2, int neg)
{
    int i = 0;
    int result = 0;
    int ret = 0;
    int max_size = MAX(my_strlen(nb1), my_strlen(nb2));
    char *str = malloc(sizeof(char) * (my_strlen(nb1) + my_strlen(nb2)) + 3);

    for (i = 0; i < max_size; i++) {
        if (my_strlen(nb1) - 1 < i &&  my_strlen(nb2) > i)
            result = ret + CTOI(nb2[i]);
        else if (my_strlen(nb1) > i && my_strlen(nb2) - 1 < i)
            result = ret + CTOI(nb1[i]);
        else
            result = ret + CTOI(nb1[i]) + CTOI(nb2[i]);
        ret = calcul_ret(result, ret);
        str[i] = ITOC(result % 10);
    }
    if (ret != 0)
        str[i] = ITOC(ret);
    my_revstr(str);
    add_min_element(str, 0, '-', neg);
    return (str);
}
