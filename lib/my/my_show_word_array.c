/*
** EPITECH PROJECT, 2020
** my_show_word_array
** File description:
** Display the content of an array of words
*/

void my_putchar(char c);

int my_putstr(char const *str);

int my_show_word_array(char * const *tab)
{
    for (int i = 0; *tab[i] != '\0'; i++) {
        my_putstr(tab[i]);
        my_putchar('\n');
    }
    return (0);
}
