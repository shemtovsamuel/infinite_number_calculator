/*
** EPITECH PROJECT, 2020
** my.h
** File description:
** Contains all of my proto of libmy.a
*/

#ifndef MY_H
#define MY_H

#define MAX(x, y) ((x) > (y)) ? (x) : (y)
#define CTOI(x) (x - '0')
#define ITOC(x) (x + '0')

int my_compute_power_rec(int, int);
int my_compute_square_root(int);
int my_find_prime_sup(int);
int my_getnbr(char const *);
int core_getnbr(char const *, long int);
int my_is_prime(int);
int my_is_prime2(int);
int my_isneg(int);
int my_put_nbr(int);
void my_putnbr_base(int nbr, char const *base);
void my_putchar(char);
int my_putstr(char const *);
char *my_revstr(char *);
int my_showmem(char const *, int);
int my_showstr(char const *);
void my_sort_int_array(int *, int);
int my_str_isalpha(char const *);
int my_str_islower(char const *);
int my_str_isnum(char const *);
int my_str_isprintable(char const *);
int my_str_isupper(char const *);
char *my_strcapitalize(char *);
char my_capchar(char, int);
char *my_strcat(char *, char const *);
int my_strcmp(char const *, char const *);
char *my_strcpy(char *, char const *);
int my_strlen(char const *);
int my_strlen2(char const *);
char *my_strlowcase(char *);
char *my_strncat(char *, char const *, int);
int my_strncmp(char const *, char const *, int);
char *my_strncpy(char *dest, char const *, int);
char *my_strstr(char *, char const *);
char *my_strupcase(char *);
void my_swap(int *, int *);
int my_show_word_array(char * const *);
char **my_str_to_word_array(char const *);
int is_a_n(char);
int nb_words(char const *);
int len_word(char const *, int);
char *my_strdup(char const *);

#endif
