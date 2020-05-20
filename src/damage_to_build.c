/*
** EPITECH PROJECT, 2020
** damage_to_build
** File description:
** damage_to_build
*/

#include "my_defender.h"

void static mob_damage_check(building_t *build, enemy_t *mob)
{
    float x = 0;
    float y = 0;

    while (build != NULL) {
        x = mob->pos.x;
        y = mob->pos.y;
        if (build->type == 4 && build->is_placed == 1
            && sfIntRect_contains(&build->rect, x, y) == 1)
            build->hp -= 10 * mob->type;
        if (build->type == 5
            && sfIntRect_contains(&build->rect, x, y) == 1) {
            build->hp -= 10 * mob->type;
        }
        build = build->next;
    }
}

void mob_damage(objects_t *obj)
{
    enemy_t *pointer = obj->mob;

    while (pointer != NULL) {
        mob_damage_check(obj->build, pointer);
        pointer = pointer->next;
    }
}
