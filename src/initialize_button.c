/*
** EPITECH PROJECT, 2020
** initialize_button
** File description:
** initialize_button
*/

#include "my_defender.h"

void static init_button1(objects_t *obj)
{
    obj->tex->texture_bt1 = sfTexture_createFromFile("assets/bt1.png", NULL);
    obj->spr->sprite_bt1 = sfSprite_create();
    sfSprite_setTexture(obj->spr->sprite_bt1, obj->tex->texture_bt1, sfFalse);
    obj->itf->button1.top = 875;
    obj->itf->button1.left = 600;
    obj->itf->button1.width = 80;
    obj->itf->button1.height = 80;
    sfSprite_scale(obj->spr->sprite_bt1, (sfVector2f){0.8, 0.8});
    sfSprite_setPosition(obj->spr->sprite_bt1, (sfVector2f){600, 875});
}

void static init_button2(objects_t *obj)
{
    obj->tex->texture_bt2 = sfTexture_createFromFile("assets/bt2.png", NULL);
    obj->spr->sprite_bt2 = sfSprite_create();
    sfSprite_setTexture(obj->spr->sprite_bt2, obj->tex->texture_bt2, sfFalse);
    obj->itf->button2.top = 875;
    obj->itf->button2.left = 705;
    obj->itf->button2.width = 80;
    obj->itf->button2.height = 80;
    sfSprite_scale(obj->spr->sprite_bt2, (sfVector2f){0.8, 0.8});
    sfSprite_setPosition(obj->spr->sprite_bt2, (sfVector2f){705, 875});
}

void static init_button3(objects_t *obj)
{
    obj->tex->texture_bt3 = sfTexture_createFromFile("assets/bt3.png", NULL);
    obj->spr->sprite_bt3 = sfSprite_create();
    sfSprite_setTexture(obj->spr->sprite_bt3, obj->tex->texture_bt3, sfFalse);
    obj->itf->button3.top = 875;
    obj->itf->button3.left = 810;
    obj->itf->button3.width = 80;
    obj->itf->button3.height = 80;
    sfSprite_scale(obj->spr->sprite_bt3, (sfVector2f){0.8, 0.8});
    sfSprite_setPosition(obj->spr->sprite_bt3, (sfVector2f){810, 875});
}

void static init_button4(objects_t *obj)
{
    obj->tex->texture_bt4 = sfTexture_createFromFile("assets/bt4.png", NULL);
    obj->spr->sprite_bt4 = sfSprite_create();
    sfSprite_setTexture(obj->spr->sprite_bt4, obj->tex->texture_bt4, sfFalse);
    obj->itf->button4.top = 875;
    obj->itf->button4.left = 915;
    obj->itf->button4.width = 80;
    obj->itf->button4.height = 80;
    sfSprite_scale(obj->spr->sprite_bt4, (sfVector2f){0.8, 0.8});
    sfSprite_setPosition(obj->spr->sprite_bt4, (sfVector2f){915, 875});
}

void init_button(objects_t *obj)
{
    init_button1(obj);
    init_button2(obj);
    init_button3(obj);
    init_button4(obj);
    obj->itf->buttonm.top = 750;
    obj->itf->buttonm.left = 1850;
    obj->itf->buttonm.width = 75;
    obj->itf->buttonm.height = 30;
    obj->itf->buttonpq.top = 340;
    obj->itf->buttonpq.left = 780;
    obj->itf->buttonpq.width = 370;
    obj->itf->buttonpq.height = 50;
    obj->itf->buttonpl.top = 410;
    obj->itf->buttonpl.left = 780;
    obj->itf->buttonpl.width = 370;
    obj->itf->buttonpl.height = 50;
    obj->itf->buttonpr.top = 500;
    obj->itf->buttonpr.left = 780;
    obj->itf->buttonpr.width = 370;
    obj->itf->buttonpr.height = 50;
}
