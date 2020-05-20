/*
** EPITECH PROJECT, 2019
** MY_SWAP
** File description:
** task 01 day04
*/

void my_swap(int *a, int *b)
{
    int swap;

    swap = *b;
    *b = *a;
    *a = swap;
}
