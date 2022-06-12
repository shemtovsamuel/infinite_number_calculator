/*
** EPITECH PROJECT, 2020
** my_putnbr_base.c
** File description:
** Convert and display a decimal number into a given base
*/

#include "my.h"

void my_convertnbr_base_rec(int nbr, char const *base, int base_len, char *str)
{
    if (nbr < 0)
        my_putchar('-');
    else
        nbr = -nbr;
    if (nbr <= -base_len)
        my_convertnbr_base_rec(-(nbr / base_len), base, base_len, str + 1);
    else
        str[1] = '\0';
    *str = base[-(nbr % base_len)];
}

void my_putnbr_base(int nbr, char const *base)
{
    int len = my_strlen(base);
    char str[33];

    my_convertnbr_base_rec(nbr, base, len, str);
    my_revstr(str);
    my_putstr(str);
}

