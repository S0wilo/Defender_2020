/*
** EPITECH PROJECT, 2019
** framebuffer
** File description:
** framebuffer
*/
#include "graph.h"

void framebuffer_destroy(sfUint8 *fb)
{
    free(fb);
}

void framebuffer_clean(sfUint8 *fb)
{
    for (int k = 0; fb[k]; k++) {
        fb[k] = 0;
    }
}

sfRenderWindow *create_my_window(unsigned int width, unsigned int height)
{
    sfRenderWindow *window = NULL;
    sfVideoMode vm = {0};

    vm.width = width;
    vm.height = height;
    vm.bitsPerPixel = 32;
    window = sfRenderWindow_create(vm, "My Window", sfDefaultStyle, NULL);
    return (window);
}

void framebuffer_delete(sfRenderWindow *window,
                        sfUint8 *fb,
                        sfTexture *texture,
                        sfSprite *sprite)
{
    sfRenderWindow_destroy(window);
    framebuffer_destroy(fb);
    sfTexture_destroy(texture);
    sfSprite_destroy(sprite);
}
