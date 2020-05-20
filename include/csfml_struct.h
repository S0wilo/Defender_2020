/*
** EPITECH PROJECT, 2019
** my_runner
** File description:
** second .h file
*/

#ifndef ALL_STRUCT_H
#define ALL_STRUCT_H
#include <SFML/Graphics.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Color.h>
#include <SFML/Window/Export.h>
#include <SFML/Config.h>
#include <SFML/System/Export.h>
#include <SFML/System/Time.h>
#include <SFML/System/Types.h>
#include <SFML/Audio.h>
#include <SFML/Audio/Music.h>
#include <SFML/Audio/Export.h>
#include <SFML/Audio/SoundStatus.h>
#include <SFML/Audio/Types.h>
#include <SFML/System/InputStream.h>
#include <SFML/System/Vector3.h>

typedef struct sprites {
    sfSprite *back;
    sfSprite *help_back;
}sprites_t;

typedef struct textures {
    sfTexture *back_text;
    sfTexture *help_texture;
    sfTexture *button_play;
    sfTexture *button_exit;
    sfTexture *button_help;
    sfTexture *button_back;
}textures_t;

typedef struct wins {
    sfVideoMode mode;
    sfVideoMode help_mode;
    sfRenderWindow *win;
    sfRenderWindow *help_win;
}wins_t;

typedef struct events {
    int x;
    int y;
    sfEvent *event;
    sfEvent *help_event;
}events_t;

typedef struct musics {
    sfMusic *music;
}musics_t;

typedef struct texts {
    sfText *volume_text;
    sfVector2f volume_pos;
}texts_t;

typedef struct buttons {
    sfRectangleShape *play_shape;
    sfVector2f play_size;
    sfVector2f play_position;
    sfVector2f play_click_pos;
    sfRectangleShape *exit_shape;
    sfVector2f exit_size;
    sfVector2f exit_position;
    sfVector2f exit_click_pos;
    sfRectangleShape *help_shape;
    sfVector2f help_size;
    sfVector2f help_position;
    sfVector2f help_click_pos;
    sfRectangleShape *back_shape;
    sfVector2f back_size;
    sfVector2f back_position;
    sfVector2f back_click_pos;
}buttons_t;

typedef struct csfml {
    sprites_t sprites;
    textures_t textures;
    wins_t wins;
    events_t events;
    musics_t musics;
    buttons_t buttons;
    texts_t texts;
}csfml_t;
#endif
