/*
** EPITECH PROJECT, 2019
** MY_STRLEN
** File description:
** task 03 day 04
*/

int my_strlen(char const *str)
{
    char i = 0;

    while (str[i] != '\0')
        i = i + 1;
    return (i);
}
