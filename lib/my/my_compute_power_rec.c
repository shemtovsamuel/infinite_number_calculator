/*
** EPITECH PROJECT, 2020
** my_compute_power_rec
** File description:
** Return power of nb ^ p rec
*/

int my_compute_power_rec(int nb, int p)
{
    int x;

    x = nb;
    if (p < 0)
        return (0);
    if (p == 0)
        return (1);
    x = x * my_compute_power_rec(x, p - 1);
    return (x);
}

