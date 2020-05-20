/*
** EPITECH PROJECT, 2020
** my_defender
** File description:
** file that handles help button
*/

#include "csfml_struct.h"

void init_button_help(csfml_t *csfml)
{
    const char *help_path = "assets/help.png";

    csfml->textures.button_help =
    sfTexture_createFromFile(help_path, NULL);
    csfml->buttons.help_shape = sfRectangleShape_create();
    csfml->buttons.help_position.x = 800;
    csfml->buttons.help_position.y = 487;
    sfRectangleShape_setPosition(csfml->buttons.help_shape,
    csfml->buttons.help_position);
    csfml->buttons.help_size.x = 359;
    csfml->buttons.help_size.y = 52;
    sfRectangleShape_setSize(csfml->buttons.help_shape,
    csfml->buttons.help_size);
    sfRectangleShape_setTexture(csfml->buttons.help_shape,
    csfml->textures.button_help, sfTrue);
    sfRectangleShape_setTextureRect(csfml->buttons.help_shape,
                                    (sfIntRect){0, 0, 359, 52});
}

int button_help_is_clicked(csfml_t *csfml)
{
    if (csfml->events.event->type == sfEvtMouseButtonPressed &&
    csfml->buttons.help_shape != NULL) {
        csfml->buttons.help_click_pos.x = csfml->events.event->mouseButton.x;
        csfml->buttons.help_click_pos.y = csfml->events.event->mouseButton.y;
        if (csfml->buttons.help_click_pos.x >= 800 &&
        csfml->buttons.help_click_pos.x <= 1159 &&
        csfml->buttons.help_click_pos.y >= 487 &&
        csfml->buttons.help_click_pos.y <= 539)
            return (1);
    }
    return (0);
}
