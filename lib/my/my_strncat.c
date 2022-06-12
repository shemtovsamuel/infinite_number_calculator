/*
** EPITECH PROJECT, 2020
** my_strncat
** File description:
** Concat n char of the src str to the end of dest str
*/

#include <stddef.h>
#include "my.h"

char *my_strncat(char *dest, char const *src, int nb)
{
    int i = 0;
    int j = my_strlen(dest);

    if (src == NULL || *src == '\0')
        return dest;
    for (i = 0; src[i] != '\0' && i < nb; i++)
        dest[j + i] = src[i];
    dest[i + j] = '\0';
    return (dest);
}
