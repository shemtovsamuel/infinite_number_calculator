/*
** EPITECH PROJECT, 2020
** my_strcat
** File description:
** str cat
*/

#include <stddef.h>

int my_strlen(char const *str);

char *my_strcat(char *dest, char const *src)
{
    int i = 0;
    int j = my_strlen(dest);

    if (src == NULL || *src == '\0')
        return dest;
    for (i = 0; src[i] != '\0'; i++)
        dest[j + i] = src[i];
    dest[i + j] = '\0';
    return (dest);
}

