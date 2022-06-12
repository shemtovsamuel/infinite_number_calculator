/*
** EPITECH PROJECT, 2020
** my_getnbr
** File description:
** Returns a number sent to the function as a string
*/

#include "my.h"

int core_getnbr(char const *str, long int nb)
{
    int i = 0;
    int neg = 0;

    while (str[i] != '\0' && (str[i] < 48 || str[i] > 57)) {
        if (str[i] == '-')
            neg++;
        i++;
    }
    while (str[i] >= 48 && str[i] <= 57) {
        nb = nb + str[i] - '0';
        nb = nb * 10;
        i++;
    }
    nb = nb / 10;
    if (nb > 2147483647 || nb < -2147483647)
        return (0);
    if (neg % 2 != 0)
        nb = -1 * nb;
    return (nb);
}

int my_getnbr(char const *str)
{
    long int nb = 0;

    return (core_getnbr(str, nb));
}
