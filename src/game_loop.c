/*
** EPITECH PROJECT, 2020
** game_loop
** File description:
** game_loop
*/

#include "my_defender.h"

int game_loop(objects_t *obj)
{
    sfEvent event = {0};

    sfMusic_play(obj->sd->song);
    obj->pause = 0;
    obj->quit = 0;
    while (sfRenderWindow_isOpen(obj->window)) {
        if (obj->pause == 0) {
            game_event(obj, event);
            game_render(obj);
            mob_handling(obj);
        } else {
            game_event_pause(obj, event);
            game_render_pause(obj);
        }
        if (obj->quit == 1)
            return (obj->score);
    }
}
