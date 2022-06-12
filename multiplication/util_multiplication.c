/*
** EPITECH PROJECT, 2020
** util_multiplication.c
** File description:
** util_multiplication.c
*/

#include "../include/my.h"

int check_neg(char const *str)
{
    int i = 0;
    int neg = 0;

    while (str[i] != '\0') {
        if (str[i] == '-')
            neg++;
        i++;
    }
    if (neg % 2 != 0)
        return (1);
    return (0);
}
