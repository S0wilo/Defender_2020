/*
** EPITECH PROJECT, 2019
** MY_STRCPY
** File description:
** task01 , day06
*/

char *my_strcpy(char *dest, char const *src)
{
    int i = 0;

    while (dest[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    return (dest);
}
