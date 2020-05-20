/*                                                                                                
** EPITECH PROJECT, 2019                                                                          
** str_to_number                                                                                  
** File description:                                                                              
** str_to_number                                                                                  
*/

#include <stddef.h>
#include <stdlib.h>

char *int_to_str(int nb)
{
    int i = 1;
    int stock = nb;
    char *str = NULL;

    for (i; stock > 9; i++)
        stock = stock / 10;
    str = malloc(sizeof(char) * (i + 1));
    if (str == NULL)
        return (NULL);
    str[i] = '\0';
    for (i; i > 0; i--) {
        str[i - 1] = nb % 10 + '0';
        nb = nb / 10;
    }
    return (str);
}
