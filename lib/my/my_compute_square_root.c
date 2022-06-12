/*
** EPITECH PROJECT, 2020
** my_compute_square_root
** File description:
** Return square root
*/

int my_compute_square_root(int nb)
{
    int x;

    x = 0;
    if (nb < 0)
        return (0);
    while ((x * x) != nb) {
        if ((x * x) > nb) {
            return (0);
        }
        x++;
    }
    return (x);
}

