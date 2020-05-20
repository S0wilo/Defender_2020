/*
** EPITECH PROJECT, 2019
** my_put_nbr_base
** File description:
** to display a number in a choosen base
*/

#include "../../include/my.h"
#include <stdlib.h>

int my_put_nbr_base(int nb, int base)
{
    int t_base = 0, i = 0;
    char *res = malloc(sizeof(char) * 10);
    int whats_left = 0;
    int div = nb;

    t_base = my_strlen(base);
    if (nb < 0)
        my_putchar('-');
    while (div != 0)  {
        whats_left = div % base;
        div = div / base;
        if (whats_left > 9)
            res[i] = (whats_left - 10) + 65;
        else
            res[i] = whats_left + 48;
        i++;
    }
    my_revstr(res);
    my_putstr(res);
    free(res);
    return (0);
}