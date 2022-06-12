/*
** EPITECH PROJECT, 2020
** util.c
** File description:
** util
*/

#include <stdlib.h>
#include "../include/my.h"

void to_string(char str[], int num)
{
    int len = 0;
    int n = 0;
    int is_neg = 0;

    if (num < 0) {
        num *= -1;
        is_neg = 1;
        str[0] = '-';
    }
    n = num;
    while (n != 0) {
        len++;
        n /= 10;
    }
    for (int i = 0; i < len; i++) {
        str[len - (i + 1 - is_neg)] = (num % 10) + '0';
        num = num / 10;
    }
    str[len + is_neg] = '\0';
}

char **delete_element(char **arr, int index)
{
    if (arr[index + 1] != NULL) {
        for (int i = index; arr[i + 1] != NULL; i++) {
            arr[i] = arr[i + 1];
            arr[i + 1] = '\0';
        }
    } else if (arr[index] != NULL)
        arr[index] = '\0';
    return (arr);
}

int isnum(char const c)
{
    if (c >= '0' && c <= '9')
        return (1);
    else
        return (0);
}