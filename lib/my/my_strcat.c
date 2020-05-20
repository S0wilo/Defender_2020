/*
** EPITECH PROJECT, 2019
** MY_STRCAT
** File description:
** No desc
*/

#include <stdlib.h>
#include <stddef.h>

int static new_strlen(char *str)
{
    int count = 0;

    while (str[count]) {
        count++;
    }
    return (count);
}

char *my_strcat(char *str1, char *str2)
{
    int len1 = new_strlen(str1);
    int len2 = new_strlen(str2);
    char *new_str = malloc(sizeof(char) * (len1 + len2));
    int i = 0;

    if (new_str == NULL)
        return (NULL);
    if (len1 != 0)
        for (i; i < len1; i++)
            new_str[i] = str1[i];
    for (int k = 0; k < len2; k++) {
        new_str[i + k] = str2[k];
        new_str[i + k + 1] = '\0';
    }
    return (new_str);
}
