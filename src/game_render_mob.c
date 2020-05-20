/*
** EPITECH PROJECT, 2020
** game_render_mob
** File description:
** game_render_mob
*/

#include "my_defender.h"

void static display_scr(objects_t *obj, enemy_t *pointer)
{
    sfTime time = {0};
    sfVector2f pos = pointer->pos;

    pos.x-= 14;
    pos.y -= 14;
    time = sfClock_getElapsedTime(pointer->clock);
    pointer->rect.top = time.microseconds / 10000 % 50 / 10 * 30;
    pointer->rect.left = pointer->direction * 34;
    sfSprite_setTextureRect(obj->spr->sprite_mob, pointer->rect);
    sfSprite_setPosition(obj->spr->sprite_mob, pos);
    sfRenderWindow_drawSprite(obj->window, obj->spr->sprite_mob, NULL);
    if (pointer->hp != 0 && pointer->hp != 100) {
        sfSprite_setTextureRect(obj->spr->sprite_hp,
                                (sfIntRect){pointer->hp/10 * 12, 0, 12, 4});
        sfSprite_setPosition(obj->spr->sprite_hp,
                             (sfVector2f){pointer->pos.x+15,pointer->pos.y-4});
        sfRenderWindow_drawSprite(obj->window, obj->spr->sprite_hp, NULL);
    }
}

void static display_mtl(objects_t *obj, enemy_t *pointer)
{
    sfTime time = {0};
    sfVector2f pos = pointer->pos;

    pos.x -= 30;
    pos.y -= 30;
    time = sfClock_getElapsedTime(pointer->clock);
    pointer->rect.top = time.microseconds / 10000 % 50 / 10 * 75;
    pointer->rect.left = pointer->direction * 68;
    sfSprite_setTextureRect(obj->spr->sprite_mobm, pointer->rect);
    sfSprite_setPosition(obj->spr->sprite_mobm, pos);
    sfRenderWindow_drawSprite(obj->window, obj->spr->sprite_mobm, NULL);
    if (pointer->hp != 0 && pointer->hp != 300) {
        sfSprite_setTextureRect(obj->spr->sprite_hp,
                                (sfIntRect){pointer->hp/30 * 12, 0, 12, 4});
        sfSprite_setPosition(obj->spr->sprite_hp,
                             (sfVector2f){pointer->pos.x+15,pointer->pos.y-4});
        sfRenderWindow_drawSprite(obj->window, obj->spr->sprite_hp, NULL);
    }
}

void display_mob(objects_t *obj)
{
    enemy_t *pointer = obj->mob->next;

    while (pointer != NULL) {
        if (pointer->type == 1)
            display_scr(obj, pointer);
        else
            display_mtl(obj, pointer);
        pointer = pointer->next;
    }
}
