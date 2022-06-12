/*
** EPITECH PROJECT, 2020
** do-op.c
** File description:
** Computes an operation
*/

#include <unistd.h>
#include "../include/my.h"

char *check_infin_add(char *nb1, char *nb2);

char *check_infin_min(char *nb1, char *nb2);

char *mult(char *nb1, char *nb2);

char *division(char *nb1, char *nb2);

char *modulo(char *nb1, char *nb2);

int getnbrf(char const *str)
{
    int i = 0;
    int neg = 0;
    int long nb = 0;

    while (str[i] != '\0' && str[i] == '-') {
        neg++;
        i++;
    }
    while (str[i] >= 48 && str[i] <= 57) {
        nb = nb + str[i] - '0';
        nb = nb * 10;
        i++;
    }
    nb = nb / 10;
    if (nb > 2147483647)
        return (0);
    if (neg % 2 != 0)
        nb = -1 * nb;
    return (nb);
}

char found_operators_w_min(char c)
{
    char operators[4] = "+/%*";

    for (int j = 0; j < 4; j++)
        if (c == operators[j])
            return (c);
    return (' ');
}

char found_before_min(char c)
{
    char operators[6] = "-+/%*(";

    for (int j = 0; j < 6; j++)
        if (c == operators[j])
            return (c);
    return (' ');
}

char found_operator(char *str)
{
    char operators[5] = "+-/%*";

    for (int i = 0; str[i] != '\0'; i++)
        for (int j = 0; j < 5; j++)
            if (str[i] == operators[j])
                return (str[i]);
    return (' ');
}

char *calcul(char *nb1, char *nb2, char operator)
{
    if (operator == '+')
        return (check_infin_add(nb1, nb2));
    if (operator == '-')
        return (check_infin_min(nb1, nb2));
    if (operator == '*')
        return (mult(nb1, nb2));
    if (operator == '/')
        return (division(nb1, nb2));
    if (operator == '%')
        return (modulo(nb1, nb2));
    return (NULL);
}