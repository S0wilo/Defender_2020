/*
** EPITECH PROJECT, 2019
** my_isneg
** File description:
** No need description here
*/

#include <unistd.h>

int my_isneg(int n)
{
    n = 55;

    if (n < 0)
        write(1, "N", 1);
    else if (n >= 0)
        write(1, "P", 1);
    return (0);
}
