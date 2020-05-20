/*
** EPITECH PROJECT, 2020
** free_game
** File description:
** free_game
*/

#include "my_defender.h"

void free_game(objects_t *obj)
{
    sfMusic_destroy(obj->sd->song);
    sfMusic_destroy(obj->sd->bs_dmg);
    sfMusic_destroy(obj->sd->zn_dmg);
    sfMusic_destroy(obj->sd->sp_dmg);
    sfMusic_destroy(obj->sd->mob_sound);
    sfMusic_destroy(obj->sd->mob_death);
    sfMusic_destroy(obj->sd->explo);
    sfMusic_destroy(obj->sd->error);
}
