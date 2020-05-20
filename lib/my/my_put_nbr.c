/*
** EPITECH PROJECT, 2019
** First C Programming
** File description:
** my_put_nbr
*/

#include "../../include/my.h"

int puissance(int x, int y)
{
    int r = 1;

    while (y >= 1) {
        r *= x;
        y--;
    }
    return (r);
}

int my_put_nbr(int nb)
{
    int c = 1;

    for (int i = 1; i < nb; i = i * 10)
        c++;
    while (c > 1) {
        int m = nb % (puissance(10, c - 1)) / puissance(10, c - 2);

        c--;
        my_putchar(m + 48);
    }
    return (0);
}
