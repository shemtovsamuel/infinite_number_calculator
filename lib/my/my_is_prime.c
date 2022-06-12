/*
** EPITECH PROJECT, 2020
** my_is_prime
** File description:
** Return 1 if nb prime and 0 if not
*/

int my_is_prime(int nb)
{
    int i;

    i = 2;
    if (nb < 0)
        return (0);
    if (nb == 0 || nb == 1)
        return (0);
    while (i < nb) {
        if (nb % i == 0)
            return (0);
        i++;
    }
    return (1);
}

