/*
** EPITECH PROJECT, 2020
** game_event_pause
** File description:
** game_event_pause
*/

#include "my_defender.h"

void static check_key_pressed(objects_t *obj)
{
    if (obj->pause == 0)
        obj->pause = 1;
    else
        obj->pause = 0;
}

int static check_mouse_pressed(objects_t *obj)
{
    sfVector2i pos = sfMouse_getPositionRenderWindow(obj->window);

    if (sfIntRect_contains(&obj->itf->buttonm, pos.x, pos.y) == 1)
        check_key_pressed(obj);
    if (sfIntRect_contains(&obj->itf->buttonpq, pos.x, pos.y) == 1)
        sfRenderWindow_close(obj->window);
    if (sfIntRect_contains(&obj->itf->buttonpl, pos.x, pos.y) == 1)
        obj->quit = 1;
    if (sfIntRect_contains(&obj->itf->buttonpr, pos.x, pos.y) == 1)
        check_key_pressed(obj);
}

void game_event_pause(objects_t *obj, sfEvent event)
{
    while (sfRenderWindow_pollEvent(obj->window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(obj->window);
        if (event.type == sfEvtMouseButtonPressed)
            check_mouse_pressed(obj);
        if (event.type == sfEvtKeyPressed && event.key.code == 36)
            check_key_pressed(obj);
    }
}
