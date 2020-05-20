/*
** EPITECH PROJECT, 2020
** initialize_move_mob
** File description:
** initialize_move_mob
*/

#include "my_defender.h"

void static create_box(move_mob_t *move, sfIntRect rect,
                       sfVector2i vector, int dir)
{
    move->rect.top = rect.top;
    move->rect.left = rect.left;
    move->rect.width = rect.width;
    move->rect.height = rect.height;
    move->move_vector.x = vector.x;
    move->move_vector.y = vector.y;
    move->direction = dir;
}

void static init_move_mob_next(move_mob_t *pointer)
{
    pointer->next = malloc(sizeof(move_mob_t));
    pointer = pointer->next;
    create_box(pointer, (sfIntRect){250, 380, 280, 200},
               (sfVector2i){1, 1}, 8);
    pointer->next = malloc(sizeof(move_mob_t));
    pointer = pointer->next;
    create_box(pointer, (sfIntRect){280, 490, 360, 150},
               (sfVector2i){2, 1}, 6);
    pointer->next = malloc(sizeof(move_mob_t));
    pointer = pointer->next;
    create_box(pointer, (sfIntRect){420, 560, 1300, 330},
               (sfVector2i){1, 0}, 4);
    pointer->next = NULL;
}

void init_move_mob(objects_t *obj)
{
    move_mob_t *pointer = NULL;

    obj->move = malloc(sizeof(move_mob_t));
    pointer = obj->move;
    create_box(pointer, (sfIntRect){394, 0, 1000, 320},
               (sfVector2i){-1, 1}, 9);
    pointer->next = malloc(sizeof(move_mob_t));
    pointer = pointer->next;
    create_box(pointer, (sfIntRect){390, 0, 10, 320},
               (sfVector2i){0, 1}, 8);
    pointer->next = malloc(sizeof(move_mob_t));
    pointer = pointer->next;
    create_box(pointer, (sfIntRect){300, 300, 300, 300},
               (sfVector2i){-1, 1}, 9);
    init_move_mob_next(pointer);
}
