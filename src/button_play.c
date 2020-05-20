/*
** EPITECH PROJECT, 2020
** my_defender
** File description:
** button_play
*/

#include "menu.h"
#include "my.h"
#include "csfml_struct.h"

void init_button_play(csfml_t *csfml)
{
    const char *play_path = "assets/play.png";

    csfml->textures.button_play = sfTexture_createFromFile(play_path, NULL);
    csfml->buttons.play_shape = sfRectangleShape_create();
    csfml->buttons.play_position.x = 800;
    csfml->buttons.play_position.y = 308;
    sfRectangleShape_setPosition(csfml->buttons.play_shape,
    csfml->buttons.play_position);
    csfml->buttons.play_size.x = 359;
    csfml->buttons.play_size.y = 81;
    sfRectangleShape_setSize(csfml->buttons.play_shape, 
    csfml->buttons.play_size);
    sfRectangleShape_setTexture(csfml->buttons.play_shape,
    csfml->textures.button_play, sfTrue);
    sfRectangleShape_setTextureRect(csfml->buttons.play_shape,
                                    (sfIntRect){0, 0, 359, 81});
}

int button_play_is_clicked(csfml_t *csfml)
{
    if (csfml->events.event->type == sfEvtMouseButtonPressed &&
    csfml->buttons.play_shape != NULL) {
        csfml->buttons.play_click_pos.x = csfml->events.event->mouseButton.x;
        csfml->buttons.play_click_pos.y = csfml->events.event->mouseButton.y;
        if (csfml->buttons.play_click_pos.x >= 800 &&
        csfml->buttons.play_click_pos.x <= 1159 &&
        csfml->buttons.play_click_pos.y >= 308 &&
        csfml->buttons.play_click_pos.y <= 389)
            return (1);
    }
    return (0);
}
