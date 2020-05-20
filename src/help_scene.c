/*
** EPITECH PROJECT, 2020
** my_defender
** File description:
** option scene
*/

#include "csfml_struct.h"
#include "menu.h"
#include "my.h"

int create_helper(csfml_t *csfml)
{
    const char *window_name = "How to play ?";
    int width = 1024, height = 538, bitsPerPixel = 32;

    csfml->wins.help_mode = (sfVideoMode){width, height, bitsPerPixel};
    csfml->events.help_event = malloc(sizeof(sfEvent));
    create_helper_background(csfml);
    csfml->wins.help_win = sfRenderWindow_create(csfml->wins.help_mode,
    window_name, sfResize | sfClose, NULL);
    if (!csfml->wins.help_win)
        return (EXIT_FAILURE);
    return (0);
}

int create_helper_background(csfml_t *csfml)
{
    const char *background = "assets/help.jpg";

    csfml->textures.help_texture = sfTexture_createFromFile(background, NULL);
    if (!csfml->textures.help_texture)
        return (EXIT_FAILURE);
    csfml->sprites.help_back = sfSprite_create();
    sfSprite_setTexture(csfml->sprites.help_back, csfml->textures.help_texture,
    sfTrue);
    return (0);
}

void create_volume_text(csfml_t *csfml)
{
    const char *volume = "Volume:";

    csfml->texts.volume_text = sfText_create();
    sfText_setString(csfml->texts.volume_text, volume);
    csfml->texts.volume_pos.x = 640;
    csfml->texts.volume_pos.y = 360;
    sfText_setPosition(csfml->texts.volume_text, csfml->texts.volume_pos);
}

void disp_help_scene(csfml_t *csfml)
{
    sfRenderWindow_drawSprite(csfml->wins.help_win, csfml->sprites.help_back,
    NULL);
    sfRenderWindow_display(csfml->wins.help_win);
}
