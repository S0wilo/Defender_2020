/*
** EPITECH PROJECT, 2020
** game_render_pause
** File description:
** game_render_pause
*/

#include "my_defender.h"

void game_render_pause(objects_t *obj)
{
    sfRenderWindow_drawSprite(obj->window, obj->spr->sprite_mnu, NULL);
    sfRenderWindow_display(obj->window);
}
