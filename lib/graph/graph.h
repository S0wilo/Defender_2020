/*
** EPITECH PROJECT, 2019
** graph
** File description:
** graph
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include <SFML/Window.h>

typedef struct param
{
    sfRenderWindow *window;
    sfUint8 *fb;
    sfTexture *texture;
    sfSprite *sprite;
} param;

void framebuffer_destroy(sfUint8 *);
void framebuffer_clean(sfUint8 *);
sfRenderWindow *create_my_window(unsigned int, unsigned int);
void framebuffer_delete(sfRenderWindow *,
                        sfUint8 *,
                        sfTexture *,
                        sfSprite *);
