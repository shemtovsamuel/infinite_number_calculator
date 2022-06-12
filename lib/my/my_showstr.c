/*
** EPITECH PROJECT, 2020
** my_showstr
** File description:
** show str
*/

#include "my.h"

static int my_isprintable(char c)
{
    if (c >= 32 && c <= 127)
        return (1);
    else
        return (0);
}

int my_showstr(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (my_isprintable(str[i]))
            my_putchar(str[i]);
        else {
            my_putchar('\\');
            if (str[i] < 16)
                my_putchar('0');
            my_putnbr_base(str[i], "0123456789abcdef");
        }
    }
    return (0);
}
