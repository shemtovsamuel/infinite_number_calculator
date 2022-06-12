/*
** EPITECH PROJECT, 2020
** my_capitalize
** File description:
** Capitalizes the first letter of each word
*/

char my_capchar(char c, int pos)
{
    if (pos > 1) {
        if (c >= 'A' && c <= 'Z')
            c += 'a' - 'A';
    } else {
        if (c >= 'a' && c <= 'z')
            c -= 'a' - 'A';
    }
    return (c);
}

char *my_strcapitalize(char *str)
{
    char *orig = str;
    int	word = 0;

    while (*str) {
        if ((*str >= 'a' && *str <= 'z') || (*str >= 'A' && *str <= 'Z')) {
            word++;
            *str = my_capchar(*str, word);
        } else if (*str >= '0' && *str <= '9') {
            word++;
            *str = my_capchar(*str, word);
        } else {
            word = 0;
        }
        str++;
    }
    return (orig);
}
