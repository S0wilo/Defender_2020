/*
** EPITECH PROJECT, 2020
** build_handling
** File description:
** build_handling
*/

#include "my_defender.h"

void create_new_build(objects_t *obj, int type)
{
    building_t *new_build = malloc(sizeof(building_t));
    building_t *pointer = obj->build;

    new_build->pos.x = 0;
    new_build->pos.y = 0;
    new_build->type = type;
    new_build->next = NULL;
    new_build->is_placed = 0;
    new_build->rect.top = 0;
    new_build->rect.left = 0;
    new_build->rect.width = 120;
    new_build->rect.height = 120;
    new_build->hp = 100;
    new_build->clock = sfClock_create();
    new_build->dead = 0;
    while (pointer->next != NULL)
        pointer = pointer->next;
    pointer->next = new_build;
    new_build->prev = pointer;
    obj->mouse_is_used = 1;
}

int static check_build(objects_t *obj, sfIntRect *rect, sfVector2i pos)
{
    if (sfIntRect_contains(rect, pos.x, pos.y) == 1) {
        sfMusic_play(obj->sd->error);
        return (1);
    }
    if (sfIntRect_contains(rect, pos.x + 120, pos.y) == 1) {
        sfMusic_play(obj->sd->error);
        return (1);
    }
    if (sfIntRect_contains(rect, pos.x, pos.y + 120) == 1) {
        sfMusic_play(obj->sd->error);
        return (1);
    }
    if (sfIntRect_contains(rect, pos.x + 120, pos.y + 120) == 1) {
        sfMusic_play(obj->sd->error);
        return (1);
    }
}

int static check_placement(objects_t *obj, sfVector2i pos)
{
    place_build_t *pointer = obj->pbuild;

    while (pointer != NULL) {
        if (sfIntRect_contains(&pointer->rect, pos.x, pos.y) == 1)
            return (0);
        pointer = pointer->next;
    }
    sfMusic_play(obj->sd->error);
    return (1);
}

int place_new_build(objects_t *obj)
{
    building_t *pointer = obj->build;
    sfVector2i pos_mouse = sfMouse_getPositionRenderWindow(obj->window);

    while (pointer->next != NULL) {
        if (check_build(obj, &pointer->rect, pos_mouse) == 1)
            return (0);
        pointer = pointer->next;
    }
    if (pointer->is_placed == 0 && check_placement(obj, pos_mouse) == 1)
        return (0);
    if (pointer->is_placed == 0) {
        pointer->pos.x = pos_mouse.x;
        pointer->pos.y = pos_mouse.y;
        pointer->rect.top = pos_mouse.y - 50;
        pointer->rect.left = pos_mouse.x - 50;
        pointer->is_placed = 1;
        obj->mouse_is_used = 0;
    }
}
