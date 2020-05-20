/*
** EPITECH PROJECT, 2020
** my_defender
** File description:
** menu
*/

#include "menu.h"
#include "my.h"
#include "csfml_struct.h"
#include "my_defender.h"

int create_menu_background(csfml_t *csfml)
{
    const char *background = "assets/sc2_background.png";

    csfml->textures.back_text = sfTexture_createFromFile(background, NULL);
    if (!csfml->textures.back_text)
        return (EXIT_FAILURE);
    csfml->sprites.back = sfSprite_create();
    sfSprite_setTexture(csfml->sprites.back, csfml->textures.back_text, sfTrue);
    return (0);
}

void game_scene(csfml_t *csfml)
{
    objects_t obj = {NULL};

    sfMusic_pause(csfml->musics.music);
    obj.window = csfml->wins.win;
    initialize(&obj);
    game_loop(&obj);
    free_game(&obj);
    sfMusic_play(csfml->musics.music);
}

void disp_main_menu(csfml_t *csfml)
{
    sfRenderWindow_drawSprite(csfml->wins.win, csfml->sprites.back, NULL);
    display_menu_buttons(csfml);
    sfRenderWindow_display(csfml->wins.win);
}
