/*
** EPITECH PROJECT, 2020
** game_render
** File description:
** game_render
*/

#include "my_defender.h"
#include "my.h"

void static tower_pos_placed(objects_t *obj, building_t *pointer)
{
    sfVector2f pos = pointer->pos;

    pos.x -= 50;
    pos.y -= 50;
    sfSprite_setPosition(obj->spr->sprite_bui, pos);
}

void static tower_pos_mouse(objects_t *obj, sfVector2f mouse_pos)
{
    mouse_pos.x -= 50;
    mouse_pos.y -= 50;
    sfSprite_setPosition(obj->spr->sprite_bui, mouse_pos);
}

void static display_tower(objects_t *obj)
{
    building_t *pointer = obj->build;
    sfVector2i mouse_pos_i = sfMouse_getPositionRenderWindow(obj->window);
    sfVector2f mouse_pos = {mouse_pos_i.x, mouse_pos_i.y};
    int type = 0;
    sfTime time = {0};
    int sec = 0;

    while (pointer != NULL) {
        if (pointer->is_placed == 1)
            tower_pos_placed(obj, pointer);
        else
            tower_pos_mouse(obj, mouse_pos);
        time = sfClock_getElapsedTime(pointer->clock);
        sec = time.microseconds / 150000 % 5 * 120;
        type = (pointer->type - 1) * 120;
        sfSprite_setTextureRect(obj->spr->sprite_bui,
                                (sfIntRect){type, sec, 120, 120});
        sfRenderWindow_drawSprite(obj->window, obj->spr->sprite_bui, NULL);
        pointer = pointer->next;
    }
}

void static display_int(objects_t *obj)
{
    sfTime time = sfClock_getElapsedTime(obj->clock);
    int sec = time.microseconds / 130000 % 75 * 186;

    sfSprite_setTextureRect(obj->spr->sprite_por,
                            (sfIntRect){sec, 0, 185, 200});
    sfRenderWindow_drawSprite(obj->window, obj->spr->sprite_por, NULL);
    sfRenderWindow_drawSprite(obj->window, obj->spr->sprite_int, NULL);
    game_render_button(obj);
}

void game_render(objects_t *obj)
{
    sfRenderWindow_drawSprite(obj->window, obj->spr->sprite_map, NULL);
    display_int(obj);
    display_tower(obj);
    display_mob(obj);
    sfText_setString(obj->score_text,
                     my_strcat("Score: ", int_to_str(obj->score)));
    sfRenderWindow_drawText(obj->window, obj->score_text, NULL);
    sfRenderWindow_display(obj->window);
}
