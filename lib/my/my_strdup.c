/*
** EPITECH PROJECT, 2019
** MY_STRDUP
** File description:
** Task01, Day08
*/

#include <stdlib.h>
#include "../../include/my.h"

char *my_strdup(char const *src)
{
    int i = 0;
    char *res;

    res = malloc(sizeof(char) * my_strlen(src));
    while (src[i] != '\0') {
        res[i] = src[i];
        i++;
    }
    return (res);
    free(res);
}
