/*
** EPITECH PROJECT, 2020
** my_strupcase
** File description:
** Puts every letter of every word in it in uppercase
*/

char *my_strupcase(char *str)
{
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] >= 'a' && str[i] <= 'z')
            str[i] = str[i] - 32;
        i++;
    }
    return (str);
}
