/*
** EPITECH PROJECT, 2020
** game_event
** File description:
** game_event
*/

#include "my_defender.h"

void static check_key_pressed(objects_t *obj)
{
    if (obj->pause == 0)
        obj->pause = 1;
    else
        obj->pause = 0;
}

int static check_mouse_pressed_next(objects_t *obj, sfVector2i pos)
{
    if (obj->mouse_is_used == 0 && obj->score >= 200 && obj->pause == 0
        && sfIntRect_contains(&obj->itf->button3, pos.x, pos.y) == 1) {
        create_new_build(obj, 3);
        obj->score -= 200;
        return (1);
    }
    if (obj->mouse_is_used == 0 && obj->score >= 100 && obj->pause == 0
        && sfIntRect_contains(&obj->itf->button4, pos.x, pos.y) == 1) {
        create_new_build(obj, 4);
        obj->score -= 100;
        return (1);
    }
    if (sfIntRect_contains(&obj->itf->buttonm, pos.x, pos.y) == 1) {
        check_key_pressed(obj);
        return (1);
    }
    return (0);
}

int static check_mouse_pressed(objects_t *obj)
{
    sfVector2i pos = sfMouse_getPositionRenderWindow(obj->window);

    if (obj->mouse_is_used == 0 && obj->score >= 100 && obj->pause == 0
        && sfIntRect_contains(&obj->itf->button1, pos.x, pos.y) == 1) {
        create_new_build(obj, 1);
        obj->score -= 100;
        return (0);
    }
    if (obj->mouse_is_used == 0 && obj->score >= 300
        && sfIntRect_contains(&obj->itf->button2, pos.x, pos.y) == 1) {
        create_new_build(obj, 2);
        obj->score -= 300;
        return (0);
    }
    if (check_mouse_pressed_next(obj, pos) == 1)
        return (0);
    place_new_build(obj);
}

void game_event(objects_t *obj, sfEvent event)
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
