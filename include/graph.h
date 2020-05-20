/*
** EPITECH PROJECT, 2019
** graph
** File description:
** graph
*/

#ifndef H_GRAPH
#define H_GRAPH

#include <stdlib.h>
#include <SFML/Graphics.h>
#include <SFML/Window.h>

void framebuffer_destroy(sfUint8 *);
void framebuffer_clean(sfUint8 *);
sfRenderWindow *create_my_window(unsigned int, unsigned int);
void framebuffer_delete(sfRenderWindow *,
                        sfUint8 *,
                        sfTexture *,
                        sfSprite *);
#endif
