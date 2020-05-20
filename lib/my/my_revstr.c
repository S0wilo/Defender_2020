/*
** EPITECH PROJECT, 2019
** MY_REVSTR
** File description:
** task03, day06
*/

#include "../../include/my.h"

char *my_revstr(char *str)
{
    int a = 0;
    int b = 0;
    int swap = 0;

    a = my_strlen(str) - 1;
    while (b < a) {
        swap = str[b];
        str[b] = str[a];
        str[a] = swap;
        a = a - 1;
        b = b + 1;
    }
    return (str);
}
