/*
** EPITECH PROJECT, 2020
** damage_to_mob
** File description:
** damage_to_mob
*/

#include "my_defender.h"

int static basic_damage(objects_t *obj, building_t *build)
{
    enemy_t *pointer = obj->mob->next;
    int dist = 0;

    while (pointer != NULL) {
        dist = 0;
        if (build->pos.x - pointer->pos.x > 0)
            dist += build->pos.x - pointer->pos.x;
        else
            dist += (build->pos.x - pointer->pos.x) * -1;
        if (build->pos.y - pointer->pos.y > 0)
            dist += build->pos.y - pointer->pos.y;
        else
            dist += (build->pos.y - pointer->pos.y) * -1;
        if (pointer->dead == 0 && dist < 400) {
            pointer->hp -= 20;
            sfMusic_play(obj->sd->bs_dmg);
            return (0);
        }
        pointer = pointer->next;
    }
}

void static zone_damage(objects_t *obj, building_t *build)
{
    enemy_t *pointer = obj->mob->next;
    int dist = 0;

    while (pointer != NULL) {
        dist = 0;
        if (build->pos.x - pointer->pos.x > 0)
            dist += build->pos.x - pointer->pos.x;
        else
            dist += (build->pos.x - pointer->pos.x) * -1;
        if (build->pos.y - pointer->pos.y > 0)
            dist += build->pos.y - pointer->pos.y;
        else
            dist += (build->pos.y - pointer->pos.y) * -1;
        if (dist < 400) {
            pointer->hp -= 10;
            sfMusic_play(obj->sd->zn_dmg);
        }
        pointer = pointer->next;
    }
}

int static sniper_damage(objects_t *obj, building_t *build)
{
    enemy_t *pointer = obj->mob->next;
    int dist = 0;

    while (pointer != NULL) {
        dist = 0;
        if (build->pos.x - pointer->pos.x > 0)
            dist += build->pos.x - pointer->pos.x;
        else
            dist += (build->pos.x - pointer->pos.x) * -1;
        if (build->pos.y - pointer->pos.y > 0)
            dist += build->pos.y - pointer->pos.y;
        else
            dist += (build->pos.y - pointer->pos.y) * -1;
        if (pointer->dead == 0 && dist < 700) {
            pointer->hp -= 50;
            sfMusic_play(obj->sd->sp_dmg);
            return (0);
        }
        pointer = pointer->next;
    }
}

void tower_damage(objects_t *obj)
{
    building_t *pointer = obj->build->next;
    sfTime time = sfClock_getElapsedTime(obj->clock);

    while (pointer != NULL) {
        if (pointer->type == 1 && pointer->is_placed == 1)
            basic_damage(obj, pointer);
        if (pointer->type == 2 && pointer->is_placed == 1)
            zone_damage(obj, pointer);
        if (pointer->type == 3 && pointer->is_placed == 1
            && time.microseconds / 10000 % 5 == 0)
            sniper_damage(obj, pointer);
        pointer = pointer->next;
    }
}
