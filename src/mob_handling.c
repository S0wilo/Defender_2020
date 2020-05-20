/*
** EPITECH PROJECT, 2020
** mob_handling
** File description:
** mob_handling
*/

#include "my_defender.h"

int static check_wall(objects_t *obj, enemy_t *mob)
{
    building_t *pointer = obj->build;

    while (pointer != NULL) {
        if (pointer->type == 4
            &&sfIntRect_contains(&pointer->rect,mob->pos.x,mob->pos.y)==1)
            return (1);
        if (pointer->type == 5
            &&sfIntRect_contains(&pointer->rect,mob->pos.x,mob->pos.y)==1)
            return (1);
        pointer = pointer->next;
    }
}

void static move_one_mob(objects_t *obj, move_mob_t *move, enemy_t *mob)
{
    while (mob != NULL) {
        if (mob->dead == 0
            &&sfIntRect_contains(&move->rect,mob->pos.x,mob->pos.y)==1
            && check_wall(obj, mob) == 0) {
            mob->pos.x += move->move_vector.x / mob->type;
            mob->pos.y += move->move_vector.y / mob->type;
            mob->direction = move->direction;
        }
        mob = mob->next;
    }
}

void static move_mobs(objects_t *obj)
{
    move_mob_t *pointer = obj->move;

    while (pointer != NULL) {
        move_one_mob(obj, pointer, obj->mob->next);
        pointer = pointer->next;
    }
}

void mob_handling(objects_t *obj)
{
    sfTime time = {0};

    time = sfClock_getElapsedTime(obj->clock);
    move_mobs(obj);
    if (time.microseconds / 10000 % 60 == 0) {
        create_mob(obj, obj->mob);
        mob_damage(obj);
        tower_damage(obj);
        check_dead(obj);
    }
    delete_dead(obj);
}
