/*
** EPITECH PROJECT, 2020
** my_find_prime_sup
** File description:
** Return smallest prime nb < > == nb give
*/

#include "my.h"

int my_find_prime_sup(int nb)
{
    if (nb <= 0 || nb == 1)
        return (2);
    while (!my_is_prime(nb))
        nb++;
    return (nb);
}

