/*
** EPITECH PROJECT, 2020
** my_revstr
** File description:
** Reverses a string
*/

int my_strlen2(char const *str)
{
    int i;

    i = 0;
    while (str[i] != '\0') {
        i++;
    }
    return (i);
}

char *my_revstr(char *str)
{
    char c;
    int i;
    int j;

    i = 0;
    j = my_strlen2(str) - 1;
    while (i < j) {
        c = str[i];
        str[i] = str[j];
        str[j] = c;
        i = i + 1;
        j = j - 1;
    }
    return (str);
}

