/*
** EPITECH PROJECT, 2020
** initialize_place_build
** File description:
** initialize_place_build
*/

#include "my_defender.h"

void init_place_build(objects_t *obj)
{
    obj->pbuild = malloc(sizeof(place_build_t));
    obj->pbuild->rect.top = 8;
    obj->pbuild->rect.left = 490;
    obj->pbuild->rect.width = 1070;
    obj->pbuild->rect.height = 240;
    obj->pbuild->next = malloc(sizeof(place_build_t));
    obj->pbuild->next->rect.top = 470;
    obj->pbuild->next->rect.left = 510;
    obj->pbuild->next->rect.width = 960;
    obj->pbuild->next->rect.height = 220;
    obj->pbuild->next->next = NULL;
}
