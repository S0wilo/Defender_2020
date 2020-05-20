/*
** EPITECH PROJECT, 2020
** initialize
** File description:
** initialize
*/

#include "my_defender.h"

void static init_map(objects_t *obj)
{
    obj->tex->texture_map=sfTexture_createFromFile("assets/map1.jpg",NULL);
    obj->spr->sprite_map=sfSprite_create();
    sfSprite_setTexture(obj->spr->sprite_map,obj->tex->texture_map,sfFalse);
    obj->tex->texture_hp=sfTexture_createFromFile("assets/hp.png",NULL);
    obj->spr->sprite_hp = sfSprite_create();
    sfSprite_setTexture(obj->spr->sprite_hp,obj->tex->texture_hp,sfFalse);
    sfSprite_scale(obj->spr->sprite_hp, (sfVector2f){2, 2});
}

void static init_int(objects_t *obj)
{
    obj->tex->texture_int=sfTexture_createFromFile("assets/int.png",NULL);
    obj->spr->sprite_int = sfSprite_create();
    sfSprite_setTexture(obj->spr->sprite_int,obj->tex->texture_int,sfFalse);
    sfSprite_setPosition(obj->spr->sprite_int, (sfVector2f){0, -51});
    obj->tex->texture_por=sfTexture_createFromFile("assets/por.jpg",NULL);
    obj->spr->sprite_por = sfSprite_create();
    sfSprite_setTexture(obj->spr->sprite_por,obj->tex->texture_por,sfFalse);
    sfSprite_setPosition(obj->spr->sprite_por, (sfVector2f){1360, 825});
    init_button(obj);
    obj->tex->texture_mnu=sfTexture_createFromFile("assets/menu.png",NULL);
    obj->spr->sprite_mnu = sfSprite_create();
    sfSprite_setTexture(obj->spr->sprite_mnu,obj->tex->texture_mnu,sfFalse);
}

void static init_bui(objects_t *obj)
{
    obj->tex->texture_bui=sfTexture_createFromFile("assets/build.png",NULL);
    obj->spr->sprite_bui = sfSprite_create();
    sfSprite_setTexture(obj->spr->sprite_bui,obj->tex->texture_bui,sfFalse);
    obj->build->type = 5;
    obj->build->pos.x = 1550;
    obj->build->pos.y = 650;
    obj->build->next = NULL;
    obj->build->prev = NULL;
    obj->build->is_placed = 1;
    obj->build->rect.top = 600;
    obj->build->rect.left = 1550;
    obj->build->rect.width = 120;
    obj->build->rect.height = 120;
    obj->build->hp = 1000;
    obj->build->clock = sfClock_create();
    obj->build->dead = 0;
    init_place_build(obj);
}

void initialize(objects_t *obj)
{
    sfRenderWindow_setFramerateLimit(obj->window, 60);
    obj->tex = malloc(sizeof(texture_t));
    obj->spr = malloc(sizeof(sprite_t));
    init_map(obj);
    obj->mob = malloc(sizeof(enemy_t));
    init_mob(obj);
    obj->itf = malloc(sizeof(interface_t));
    init_int(obj);
    obj->build = malloc(sizeof(building_t));
    init_bui(obj);
    obj->mouse_is_used = 0;
    init_move_mob(obj);
    obj->score = 200;
    obj->score_font = sfFont_createFromFile("assets/Walkway.ttf");
    obj->score_text = sfText_create();
    sfText_setColor(obj->score_text, sfRed);
    sfText_setFont(obj->score_text, obj->score_font);
    sfText_setPosition(obj->score_text, (sfVector2f){380, 850});
    obj->clock = sfClock_create();
    init_sound(obj);
}
