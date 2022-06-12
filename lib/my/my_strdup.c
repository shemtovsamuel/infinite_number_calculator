/*
** EPITECH PROJECT, 2020
** my_strdup
** File description:
** Allocates memory and copies the string in it
*/

#include <stdlib.h>
#include <stddef.h>

int my_strlen(char const *str);

char *my_strdup(char const *src)
{
    int i = my_strlen(src);
    char *str = malloc(sizeof(char) * (i + 1));
    i = 0;

    if (str == NULL)
        return (NULL);
    while (src[i] != '\0') {
        str[i] = src[i];
        i++;
    }
    str[i] = '\0';
    return (str);
}
