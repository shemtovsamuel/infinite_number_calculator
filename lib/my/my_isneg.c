/*
** EPITECH PROJECT, 2020
** my_isneg
** File description:
** test if number is positive or negative
*/

void my_putchar(char c);

int my_isneg(int n)
{
    if (n >= 0)
        my_putchar('P');
    else
        my_putchar('N');
    return (0);
}

