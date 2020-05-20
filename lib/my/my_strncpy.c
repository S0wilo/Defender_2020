/*
** EPITECH PROJECT, 2019
** MY_STRNCPY
** File description:
** Task 02, day06
*/

char *my_strncpy(char *dest, char const *src, int n)
{
    int m = 0;

    while (src[m] != src[n]) {
        dest[m] = src[m];
        m++;
    }
    return (dest);
}
