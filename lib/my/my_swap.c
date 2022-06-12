/*
** EPITECH PROJECT, 2020
** my_swap
** File description:
** Swap the content of two integers
*/

void my_putchar(char c);

void my_swap(int *a, int *b)
{
    int temp;

    temp = *a;
    *a = *b;
    *b = temp;
}

