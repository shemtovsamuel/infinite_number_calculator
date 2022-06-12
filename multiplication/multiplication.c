/*
** EPITECH PROJECT, 2020
** multiplication.c
** File description:
** multiplication
*/

#include <stdlib.h>
#include "my.h"

int check_neg(char *str);

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

static char *number(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '0') {
            str = delete_element(str, i);
            i = -1;
        } else if (str[i] != '0')
            break;
    }
    if (str[0] < 40 || str[0] >= 57)
        str[0] = '0';
    return (str);
}

static void core_mul(char *result, char const *nb1, char const *nb2)
{
    int ret = 0;
    int res = 0;
    int shift_nb1 = 0;
    int shift_nb2 = 0;

    for (int i = my_strlen(nb1) - 1; i >= 0; i--) {
        ret = 0;
        shift_nb2 = 0;
        for (int j = my_strlen(nb2) - 1; j >= 0; j--) {
            res = CTOI(nb1[i]) * CTOI(nb2[j])
                + CTOI(result[shift_nb1 + shift_nb2]) + ret;
            ret = res / 10;
            result[shift_nb1 + shift_nb2] = ITOC(res % 10);
            shift_nb2++;
        }
        if (ret > 0)
            result[shift_nb1 + shift_nb2] += ret;
        shift_nb1++;
    }
}

static char *mul(char const *nb1, char const *nb2)
{
    char *result = malloc(sizeof(char) * (my_strlen(nb1) + my_strlen(nb2)) + 2);

    if (my_strlen(nb1) == 0 || my_strlen(nb2) == 0)
        return (0);
    for (int i = 0; i < my_strlen(nb1) + my_strlen(nb2); i++)
        result[i] = '0';
    core_mul(result, nb1, nb2);
    my_revstr(result);
    number(result);
    result[my_strlen(nb1) + my_strlen(nb2) + 1] = '\0';
    return (result);
}

char *mult(char *nb1, char *nb2)
{
    char *res = malloc(sizeof(char) * (my_strlen(nb1) + my_strlen(nb2)) + 2);
    if (check_neg(nb1) != check_neg(nb2))
        my_strcat(res, "-");
    for (int i = 0; nb1[i] != '\0'; i++)
        if (nb1[i] == '-') {
            nb1 = delete_element(nb1, i);
            i = -1;
        }
    for (int i = 0; nb2[i] != '\0'; i++)
        if (nb2[i] == '-') {
            nb2 = delete_element(nb2, i);
            i = -1;
        }
    my_strcat(res, mul(nb1, nb2));
    return (res);
}
