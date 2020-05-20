/*
** EPITECH PROJECT, 2020
** initialize_sound
** File description:
** initialize_sound
*/

#include "my_defender.h"

void static init_sound_dmg(objects_t *obj)
{
    obj->sd->bs_dmg = sfMusic_createFromFile("assets/sound/bs_dmg.ogg");
    obj->sd->zn_dmg = sfMusic_createFromFile("assets/sound/zn_dmg.ogg");
    obj->sd->sp_dmg = sfMusic_createFromFile("assets/sound/sp_dmg.ogg");
}

void init_sound(objects_t *obj)
{
    obj->sd = malloc(sizeof(sound_t));
    obj->sd->song = sfMusic_createFromFile("assets/sound/song.ogg");
    sfMusic_setLoop(obj->sd->song, sfTrue);
    init_sound_dmg(obj);
    obj->sd->explo = sfMusic_createFromFile("assets/sound/explo.ogg");
    obj->sd->mob_sound=sfMusic_createFromFile("assets/sound/mob_sound.ogg");
    obj->sd->mob_death=sfMusic_createFromFile("assets/sound/mob_death.ogg");
    obj->sd->error = sfMusic_createFromFile("assets/sound/error.ogg");
}
