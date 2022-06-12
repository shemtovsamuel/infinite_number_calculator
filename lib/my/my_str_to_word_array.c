/*
** EPITECH PROJECT, 2020
** my_str_to_word_array
** File description:
** Split a string into words
*/

#include <stdlib.h>

int is_a_n(char c)
{
    if (c >= '0' && c <= '9')
        return (1);
    else if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
        return (1);
    else
        return (0);
}

int nb_words(char const *str)
{
    int i = 0;
    int nb_words = 0;

    while (str[i] != '\0') {
        if (is_a_n(str[i]) == 1)
            nb_words++;
        while (str[i] != '\0' && is_a_n(str[i]) == 1)
            i++;
        if (str[i] != '\0')
            i++;
    }
    return (nb_words);
}

int len_word(char const *str, int k)
{
    int len = 0;

    while (is_a_n(str[k]) == 1) {
        k++;
        len++;
    }
    return (len);
}

char **my_str_to_word_array(char const *str)
{
    char **array = malloc(sizeof(char *) * (nb_words(str) + 1));
    int i = 0;
    int j = 0;
    int k = 0;

    while (i != nb_words(str)) {
        j = 0;
        while (is_a_n(str[k]) == 0)
            k++;
        array[i] = malloc(sizeof(char) * (len_word(str, k) + 1));
        while (is_a_n(str[k]) == 1) {
            array[i][j] = str[k];
            j++;
            k++;
        }
        array[i][j] = '\0';
        i++;
    }
    array[i] = NULL;
    return (array);
}

