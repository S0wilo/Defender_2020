/*
** EPITECH PROJECT, 2020
** my_defender
** File description:
** main file
*/

#include "my.h"
#include "menu.h"
#include "csfml_struct.h"

int create_all(csfml_t *csfml)
{
    const char *window_name = "My_defender";
    int width = 1920;
    int height = 1080;
    int bitsPerPixel = 32;

    csfml->wins.mode = (sfVideoMode){width, height, bitsPerPixel};
    csfml->events.event = malloc(sizeof(sfEvent));
    create_music(csfml);
    create_menu_background(csfml);
    csfml->wins.win = sfRenderWindow_create(csfml->wins.mode,
    window_name, sfResize | sfClose, NULL);
    if (!csfml->wins.win)
        return (EXIT_FAILURE);
    return (0);
}

void poll_event(csfml_t *csfml)
{
    while (sfRenderWindow_pollEvent(csfml->wins.win,
    csfml->events.event)) {
        if (button_play_is_clicked(csfml))
            game_scene(csfml);
        if (button_help_is_clicked(csfml))
            create_helper(csfml);
        if (csfml->events.event->type == sfEvtClosed ||
        button_exit_is_clicked(csfml))
            sfRenderWindow_close(csfml->wins.win);
    }
    disp_main_menu(csfml);
}

void help_event(csfml_t *csfml)
{
    disp_help_scene(csfml);
    while (csfml->wins.help_win != NULL
    && sfRenderWindow_pollEvent(csfml->wins.help_win,
    csfml->events.help_event)) {
        if (csfml->events.help_event->type == sfEvtClosed) {
            sfRenderWindow_close(csfml->wins.help_win);
            csfml->wins.help_win = NULL;
        }
    }
}

int main(void)
{
    csfml_t csfml;
    int frame_rate = 60;

    create_all(&csfml);
    init_button_play(&csfml);
    init_button_help(&csfml);
    init_button_exit(&csfml);
    csfml.wins.help_win = NULL;
    sfRenderWindow_setFramerateLimit(csfml.wins.win, frame_rate);
    while (sfRenderWindow_isOpen(csfml.wins.win)) {
        if (!csfml.wins.help_win)
            poll_event(&csfml);
        else if (csfml.wins.help_win)
            help_event(&csfml);
    }
    destroy_all(&csfml);
    return (EXIT_SUCCESS);
}
