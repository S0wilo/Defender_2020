/*
** EPITECH PROJECT, 2020
** my_defender
** File description:
** file that destroys evrything
*/

#include "menu.h"
#include "my.h"
#include "csfml_struct.h"

void destroy_main_menu(csfml_t *csfml)
{
    sfSprite_destroy(csfml->sprites.back);
    sfTexture_destroy(csfml->textures.back_text);
    sfTexture_destroy(csfml->textures.button_play);
    sfTexture_destroy(csfml->textures.button_help);
    sfTexture_destroy(csfml->textures.button_exit);
    sfRectangleShape_destroy(csfml->buttons.play_shape);
    sfRectangleShape_destroy(csfml->buttons.help_shape);
    sfRectangleShape_destroy(csfml->buttons.exit_shape);
}

void destroy_cloks_and_musics(csfml_t *csfml)
{
    sfMusic_destroy(csfml->musics.music);
}

void destroy_windows_and_free_events(csfml_t *csfml)
{
    sfRenderWindow_destroy(csfml->wins.win);
    free(csfml->events.event);
}

void destroy_all(csfml_t *csfml)
{
    destroy_main_menu(csfml);
    destroy_cloks_and_musics(csfml);
    destroy_windows_and_free_events(csfml);
}
