/*
** EPITECH PROJECT, 2020
** initialize_mob
** File description:
** initialize_mob
*/

#include "my_defender.h"

void static init_mob_scr(objects_t *obj)
{
    obj->tex->texture_mob=sfTexture_createFromFile("assets/z_scr.png",NULL);
    obj->spr->sprite_mob = sfSprite_create();
    sfSprite_setTexture(obj->spr->sprite_mob,obj->tex->texture_mob,sfFalse);
    sfSprite_scale(obj->spr->sprite_mob, (sfVector2f){2, 2});
}

void static init_mob_mtl(objects_t *obj)
{
    obj->tex->texture_mobm=sfTexture_createFromFile("assets/z_mtl.png",NULL);
    obj->spr->sprite_mobm = sfSprite_create();
    sfSprite_setTexture(obj->spr->sprite_mobm,obj->tex->texture_mobm,sfFalse);
    sfSprite_scale(obj->spr->sprite_mobm, (sfVector2f){2, 2});
}

void init_mob(objects_t *obj)
{
    obj->spawn_mob.x = 395;
    obj->spawn_mob.y = 8;
    obj->mob->dead = 0;
    obj->mob->next = NULL;
    obj->mob->prev = NULL;
    obj->mob->pos.x = 0;
    obj->mob->pos.y = 0;
    obj->mob->rect.top = 0;
    obj->mob->rect.left = 0;
    obj->mob->rect.width = 28;
    obj->mob->rect.height = 28;
    obj->mob->type = 1;
    obj->mob->clock = sfClock_create();
    obj->mob->direction = 0;
    obj->mob->hp = 100;
    init_mob_scr(obj);
    init_mob_mtl(obj);
}
