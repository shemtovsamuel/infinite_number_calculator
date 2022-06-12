/*
** EPITECH PROJECT, 2020
** my_sort_array.c
** File description:
** Sort integer array in ascending order
*/

void my_sort_int_array(int *array, int size)
{
    int i;
    int temp;

    i = 0;
    temp = 0;
    while (i != size) {
        if (i > 0 && array[i] < array[i - 1]) {
            temp = array[i];
            array[i] = array[i - 1];
            array[i - 1] = temp;
            i = i - 2;
        }
        i++;
    }
}

