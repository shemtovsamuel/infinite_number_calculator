/*
** EPITECH PROJECT, 2020
** my_strlen
** File description:
** Counts and returns the nb of char of str
*/

int my_strlen(char const *str)
{
    int i;

    i = 0;
    while (str[i] != '\0') {
        i++;
    }
    return (i);
}

