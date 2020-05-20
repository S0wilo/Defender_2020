/*
** EPITECH PROJECT, 2019
** My_defender
** File description:
** file that handles music
*/

#include "menu.h"
#include "csfml_struct.h"

void create_music(csfml_t *csfml)
{
    const char *music = "assets/sound/menu_song.ogg";

    csfml->musics.music = 0;
    csfml->musics.music = sfMusic_createFromFile(music);
    sfMusic_setLoop(csfml->musics.music, sfTrue);
    sfMusic_play(csfml->musics.music);
}
