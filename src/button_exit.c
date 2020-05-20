/*
** EPITECH PROJECT, 2020
** my_defender
** File description:
** button exit to quit game
*/

#include "menu.h"
#include "my.h"
#include "csfml_struct.h"

void init_button_exit(csfml_t *csfml)
{
    const char *exit_path = "assets/quit.png";

    csfml->textures.button_exit = sfTexture_createFromFile(exit_path, NULL);
    csfml->buttons.exit_shape = sfRectangleShape_create();
    csfml->buttons.exit_position.x = 800;
    csfml->buttons.exit_position.y = 667;
    sfRectangleShape_setPosition(csfml->buttons.exit_shape,
    csfml->buttons.exit_position);
    csfml->buttons.exit_size.x = 359;
    csfml->buttons.exit_size.y = 53;
    sfRectangleShape_setSize(csfml->buttons.exit_shape,
    csfml->buttons.exit_size);
    sfRectangleShape_setTexture(csfml->buttons.exit_shape,
    csfml->textures.button_exit, sfTrue);
    sfRectangleShape_setTextureRect(csfml->buttons.exit_shape,
                                    (sfIntRect){0, 0, 359, 53});
}

int button_exit_is_clicked(csfml_t *csfml)
{
    if (csfml->events.event->type == sfEvtMouseButtonPressed &&
    csfml->buttons.exit_shape != NULL) {
        csfml->buttons.exit_click_pos.x = csfml->events.event->mouseButton.x;
        csfml->buttons.exit_click_pos.y = csfml->events.event->mouseButton.y;
        if (csfml->buttons.exit_click_pos.x >= 800 &&
        csfml->buttons.exit_click_pos.x <= 1159 &&
        csfml->buttons.exit_click_pos.y >= 667 &&
        csfml->buttons.exit_click_pos.y <= 720)
            return (1);
    }
    return (0);
}
