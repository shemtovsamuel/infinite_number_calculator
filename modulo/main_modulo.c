/*
** EPITECH PROJECT, 2020
** main_modulo.c
** File description:
** main_modulo.c
*/

#include <unistd.h>
#include <stdlib.h>
#include "my.h"

char *exec_modulo_hand(char *nb, char *d);

char *exec_modulo_add(char *nb, char *d);

static char *delete_element(char *arr, int index)
{
    if (arr[index + 1] != '\0') {
        for (int i = index; arr[i + 1] != '\0'; i++) {
            arr[i] = arr[i + 1];
            arr[i + 1] = '\0';
        }
    } else if (arr[index] != '\0')
        arr[index] = '\0';
    return (arr);
}

static int check_neg(char *str)
{
    int i = 0;
    int neg = 0;

    while (str[i] != '\0') {
        if (str[i] == '-')
            neg++;
        i++;
    }
    if (neg % 2 != 0)
        return (1);
    return (0);
}

static char *number(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] == '-') {
            str = delete_element(str, i);
            i = -1;
        }
    return (str);
}

static int check_method(char const *nb2)
{
    char max_nb[] = "214748376";

    if (my_strlen(nb2) > my_strlen(max_nb))
        return (2);
    if (my_strlen(nb2) == my_strlen(max_nb)) {
        if (my_strcmp(nb2, max_nb) >= 0)
            return (2);
    }
    return (1);
}

char *modulo(char *nb1, char *nb2)
{
    char *res = malloc(sizeof(char) * (my_strlen(nb1) + my_strlen(nb2)) + 2);

    if (check_neg(nb1) != 0)
        my_strcat(res, "-");
    nb1 = number(nb1);
    nb2 = number(nb2);
    if (check_method(nb2) == 1)
        return (my_strcat(res, exec_modulo_hand(nb1, nb2)));
    else if (check_method(nb2) == 2)
        return (my_strcat(res, exec_modulo_add(nb1, nb2)));
}
