/*
** EPITECH PROJECT, 2020
** check_delete_dead
** File description:
** check_delete_dead
*/

#include "my_defender.h"

void static check_dead_build(objects_t *obj)
{
    building_t *pointer_build = obj->build;
    sfTime time = sfClock_getElapsedTime(obj->build->clock);

    if (obj->build->dead == 1 && time.microseconds > 500000)
        obj->quit = 1;
    while (pointer_build != NULL) {
        if (pointer_build->hp <= 0 && pointer_build->dead == 0) {
            pointer_build->dead = 1;
            sfClock_restart(pointer_build->clock);
            pointer_build->type = 6;
            sfMusic_play(obj->sd->explo);
        }
        pointer_build = pointer_build->next;
    }
}

void check_dead(objects_t *obj)
{
    enemy_t *pointer_mob = obj->mob->next;
    building_t *pointer_build = obj->build;

    while (pointer_mob != NULL) {
        if (pointer_mob->hp <= 0 && pointer_mob->dead == 0) {
            pointer_mob->dead = 1;
            sfClock_restart(pointer_mob->clock);
            pointer_mob->direction = 14;
            obj->score += 30;
            sfMusic_play(obj->sd->mob_death);
        }
        pointer_mob = pointer_mob->next;
    }
    check_dead_build(obj);
}

void static delete_mob(enemy_t *mob)
{
    enemy_t *stock = mob->next;

    if (mob->next != NULL)
        mob->next->prev = mob->prev;
    if (mob->prev != NULL)
        mob->prev->next = stock;
    free(mob);
}

void static delete_build(building_t *build)
{
    building_t *stock = build->next;

    if (build->next != NULL)
        build->next->prev = build->prev;
    if (build->prev != NULL)
        build->prev->next = stock;
    free(build);
}

void delete_dead(objects_t *obj)
{
    enemy_t *pointer_mob = obj->mob->next;
    building_t *pointer_build = obj->build->next;
    sfTime time = {0};

    while (pointer_mob != NULL) {
        time = sfClock_getElapsedTime(pointer_mob->clock);
        if (pointer_mob->dead == 1 && time.microseconds > 500000)
            delete_mob(pointer_mob);
        pointer_mob = pointer_mob->next;
    }
    while (pointer_build != NULL) {
        time = sfClock_getElapsedTime(pointer_build->clock);
        if (pointer_build->dead == 1 && time.microseconds > 500000)
            delete_build(pointer_build);
        pointer_build = pointer_build->next;
    }
}
