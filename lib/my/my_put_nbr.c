/*
** EPITECH PROJECT, 2020
** my_put_nbr
** File description:
** Display number given as a parameter
*/

void my_putchar(char c);

int my_put_nbr(int nb)
{
    long int nb_long;

    nb_long = nb;
    if (nb_long < 0) {
        my_putchar('-');
        nb_long = -nb_long;
    }
    if (nb_long / 10)
        my_put_nbr(nb_long / 10);
    my_putchar(nb_long % 10 + '0');
    return (0);
}

