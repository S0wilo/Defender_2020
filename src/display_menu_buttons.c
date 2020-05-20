/*
** EPITECH PROJECT, 2020
** display_menu_buttons
** File description:
** display_menu_buttons
*/

#include "menu.h"
#include "my.h"
#include "csfml_struct.h"

void static display_menu_play(csfml_t *csfml)
{
    sfVector2i pos = sfMouse_getPositionRenderWindow(csfml->wins.win);

    if (pos.x >= 800 && pos.x <= 1159 && pos.y >= 308 && pos.y <= 389) {
        sfRectangleShape_setTextureRect(csfml->buttons.play_shape,
                                        (sfIntRect){359, 0, 359, 81});
        sfRenderWindow_drawRectangleShape(csfml->wins.win,
                                          csfml->buttons.play_shape, NULL);
    } else {
        sfRectangleShape_setTextureRect(csfml->buttons.play_shape,
                                        (sfIntRect){0, 0, 359, 81});
        sfRenderWindow_drawRectangleShape(csfml->wins.win,
                                          csfml->buttons.play_shape, NULL);
    }
}

void static display_menu_help(csfml_t *csfml)
{
    sfVector2i pos = sfMouse_getPositionRenderWindow(csfml->wins.win);

    if (pos.x >= 800 && pos.x <= 1159 && pos.y >= 487 && pos.y <= 539) {
        sfRectangleShape_setTextureRect(csfml->buttons.help_shape,
                                        (sfIntRect){359, 0, 359, 52});
        sfRenderWindow_drawRectangleShape(csfml->wins.win,
                                          csfml->buttons.help_shape, NULL);
    } else {
        sfRectangleShape_setTextureRect(csfml->buttons.help_shape,
                                        (sfIntRect){0, 0, 359, 52});
        sfRenderWindow_drawRectangleShape(csfml->wins.win,
                                          csfml->buttons.help_shape, NULL);
    }
}

void static display_menu_exit(csfml_t *csfml)
{
    sfVector2i pos = sfMouse_getPositionRenderWindow(csfml->wins.win);

    if (pos.x >= 800 && pos.x <= 1159 && pos.y >= 667 && pos.y <= 720) {
        sfRectangleShape_setTextureRect(csfml->buttons.exit_shape,
                                        (sfIntRect){359, 0, 359, 53});
        sfRenderWindow_drawRectangleShape(csfml->wins.win,
                                          csfml->buttons.exit_shape, NULL);
    } else {
        sfRectangleShape_setTextureRect(csfml->buttons.exit_shape,
                                        (sfIntRect){0, 0, 359, 53});
        sfRenderWindow_drawRectangleShape(csfml->wins.win,
                                          csfml->buttons.exit_shape, NULL);
    }
}

void display_menu_buttons(csfml_t *csfml)
{
    if (csfml->buttons.play_shape != NULL)
        display_menu_play(csfml);
    if (csfml->buttons.help_shape != NULL)
        display_menu_help(csfml);
    if (csfml->buttons.exit_shape != NULL)
        display_menu_exit(csfml);
}
