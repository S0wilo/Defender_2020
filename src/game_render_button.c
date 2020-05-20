/*
** EPITECH PROJECT, 2020
** game_render_button
** File description:
** game_render_button
*/

#include "my_defender.h"

int static game_render_button1(objects_t *obj)
{
    sfVector2i pos = sfMouse_getPositionRenderWindow(obj->window);

    if (obj->score < 100) {
        sfSprite_setTextureRect(obj->spr->sprite_bt1,
                                (sfIntRect){100, 0, 100, 100});
        sfRenderWindow_drawSprite(obj->window, obj->spr->sprite_bt1, NULL);
        return (0);
    }
    if (sfIntRect_contains(&obj->itf->button1, pos.x, pos.y) == 0) {
        sfSprite_setTextureRect(obj->spr->sprite_bt1,
                                (sfIntRect){0, 0, 100, 100});
        sfRenderWindow_drawSprite(obj->window, obj->spr->sprite_bt1, NULL);
    } else {
        sfSprite_setTextureRect(obj->spr->sprite_bt1,
                                (sfIntRect){200, 0, 100, 100});
        sfRenderWindow_drawSprite(obj->window, obj->spr->sprite_bt1, NULL);
    }
}

int static game_render_button2(objects_t *obj)
{
    sfVector2i pos = sfMouse_getPositionRenderWindow(obj->window);

    if (obj->score < 300) {
        sfSprite_setTextureRect(obj->spr->sprite_bt2,
                                (sfIntRect){100, 0, 100, 100});
        sfRenderWindow_drawSprite(obj->window, obj->spr->sprite_bt2, NULL);
        return (0);
    }
    if (sfIntRect_contains(&obj->itf->button2, pos.x, pos.y) == 0) {
        sfSprite_setTextureRect(obj->spr->sprite_bt2,
                                (sfIntRect){0, 0, 100, 100});
        sfRenderWindow_drawSprite(obj->window, obj->spr->sprite_bt2, NULL);
    } else {
        sfSprite_setTextureRect(obj->spr->sprite_bt2,
                                (sfIntRect){200, 0, 100, 100});
        sfRenderWindow_drawSprite(obj->window, obj->spr->sprite_bt2, NULL);
    }
}

int static game_render_button3(objects_t *obj)
{
    sfVector2i pos = sfMouse_getPositionRenderWindow(obj->window);

    if (obj->score < 200) {
        sfSprite_setTextureRect(obj->spr->sprite_bt3,
                                (sfIntRect){100, 0, 100, 100});
        sfRenderWindow_drawSprite(obj->window, obj->spr->sprite_bt3, NULL);
        return (0);
    }
    if (sfIntRect_contains(&obj->itf->button3, pos.x, pos.y) == 0) {
        sfSprite_setTextureRect(obj->spr->sprite_bt3,
                                (sfIntRect){0, 0, 100, 100});
        sfRenderWindow_drawSprite(obj->window, obj->spr->sprite_bt3, NULL);
    } else {
        sfSprite_setTextureRect(obj->spr->sprite_bt3,
                                (sfIntRect){200, 0, 100, 100});
        sfRenderWindow_drawSprite(obj->window, obj->spr->sprite_bt3, NULL);
    }
}

int static game_render_button4(objects_t *obj)
{
    sfVector2i pos = sfMouse_getPositionRenderWindow(obj->window);

    if (obj->score < 100) {
        sfSprite_setTextureRect(obj->spr->sprite_bt4,
                                (sfIntRect){100, 0, 100, 100});
        sfRenderWindow_drawSprite(obj->window, obj->spr->sprite_bt4, NULL);
        return (0);
    }
    if (sfIntRect_contains(&obj->itf->button4, pos.x, pos.y) == 0) {
        sfSprite_setTextureRect(obj->spr->sprite_bt4,
                                (sfIntRect){0, 0, 100, 100});
        sfRenderWindow_drawSprite(obj->window, obj->spr->sprite_bt4, NULL);
    } else {
        sfSprite_setTextureRect(obj->spr->sprite_bt4,
                                (sfIntRect){200, 0, 100, 100});
        sfRenderWindow_drawSprite(obj->window, obj->spr->sprite_bt4, NULL);
    }
}

void game_render_button(objects_t *obj)
{
    game_render_button1(obj);
    game_render_button2(obj);
    game_render_button3(obj);
    game_render_button4(obj);
}
