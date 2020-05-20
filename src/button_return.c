/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** button_return
*/

#include "csfml_struct.h"

void init_button_back(csfml_t *csfml)
{
    const char *return_path = "assets/back.png";

    csfml->textures.button_back = sfTexture_createFromFile(return_path, NULL);
    csfml->buttons.back_shape = sfRectangleShape_create();
    csfml->buttons.back_position.x = 601;
    csfml->buttons.back_position.y = 667;
    sfRectangleShape_setPosition(csfml->buttons.back_shape,
    csfml->buttons.back_position);
    csfml->buttons.back_size.x = 136;
    csfml->buttons.back_size.y = 21;
    sfRectangleShape_setSize(csfml->buttons.back_shape, 
    csfml->buttons.back_size);
    sfRectangleShape_setTexture(csfml->buttons.back_shape,
    csfml->textures.button_back, sfTrue);
}

int button_back_is_clicked(csfml_t *csfml)
{
    if (csfml->events.event->type == sfEvtMouseButtonPressed) {
        csfml->buttons.back_click_pos.x = csfml->events.event->mouseButton.x;
        csfml->buttons.back_click_pos.y = csfml->events.event->mouseButton.y;
        if (csfml->buttons.back_click_pos.x >= 601 &&
        csfml->buttons.back_click_pos.x <= 737 &&
        csfml->buttons.back_click_pos.y >= 667 &&
        csfml->buttons.back_click_pos.y <= 688)
            return (1);
    }
    return (0);
}
