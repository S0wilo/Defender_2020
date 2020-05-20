/*
** EPITECH PROJECT, 2020
** create_mob
** File description:
** create_mob
*/

#include "my_defender.h"

void static new_mob_scr(enemy_t *new_mob)
{
    new_mob->type = 1;
    new_mob->rect.top = 0;
    new_mob->rect.left = 0;
    new_mob->rect.width = 28;
    new_mob->rect.height = 28;
    new_mob->hp = 100;
}

void static new_mob_mtl(enemy_t *new_mob)
{
    new_mob->type = 2;
    new_mob->rect.top = 0;
    new_mob->rect.left = 0;
    new_mob->rect.width = 60;
    new_mob->rect.height = 60;
    new_mob->hp = 300;
}

void create_mob(objects_t *obj, enemy_t *mob)
{
    enemy_t *new_mob = malloc(sizeof(enemy_t));

    new_mob->pos.x = obj->spawn_mob.x + rand() % 500;
    new_mob->pos.y = obj->spawn_mob.y;
    if (rand() % 10 == 0)
        new_mob_mtl(new_mob);
    else
        new_mob_scr(new_mob);
    new_mob->next = NULL;
    new_mob->clock = sfClock_create();
    new_mob->direction = 0;
    new_mob->dead = 0;
    while (mob->next != NULL)
        mob = mob->next;
    mob->next = new_mob;
    new_mob->prev = mob;
    sfMusic_play(obj->sd->mob_sound);
}
