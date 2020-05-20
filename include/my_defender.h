/*
** EPITECH PROJECT, 2019
** my_defender
** File description:
** my_defender
*/

#ifndef H_GLOBAL
#define H_GLOBAL

#include <unistd.h>
#include <SFML/Audio.h>
#include <SFML/System/Time.h>
#include <SFML/System/InputStream.h>
#include <SFML/System/Vector3.h>
#include "graph.h"

#define ERROR 84

typedef struct texture
{
    sfTexture *texture_map;
    sfTexture *texture_mob;
    sfTexture *texture_mobm;
    sfTexture *texture_int;
    sfTexture *texture_por;
    sfTexture *texture_bui;
    sfTexture *texture_bt1;
    sfTexture *texture_bt2;
    sfTexture *texture_bt3;
    sfTexture *texture_bt4;
    sfTexture *texture_hp;
    sfTexture *texture_mnu;
}texture_t;

typedef struct sprite
{
    sfSprite *sprite_map;
    sfSprite *sprite_mob;
    sfSprite *sprite_mobm;
    sfSprite *sprite_int;
    sfSprite *sprite_por;
    sfSprite *sprite_bui;
    sfSprite *sprite_bt1;
    sfSprite *sprite_bt2;
    sfSprite *sprite_bt3;
    sfSprite *sprite_bt4;
    sfSprite *sprite_hp;
    sfSprite *sprite_mnu;
}sprite_t;

typedef struct enemy
{
    sfVector2f pos;
    sfIntRect rect;
    struct enemy *prev;
    struct enemy *next;
    sfClock *clock;
    int type;
    int direction;
    int hp;
    int dead;
}enemy_t;

typedef struct building
{
    sfVector2f pos;
    sfIntRect rect;
    int type;
    int is_placed;
    int hp;
    int dead;
    sfClock *clock;
    struct building *prev;
    struct building *next;
}building_t;

typedef struct interface
{
    sfIntRect button1;
    sfIntRect button2;
    sfIntRect button3;
    sfIntRect button4;
    sfIntRect buttonm;
    sfIntRect buttonpq;
    sfIntRect buttonpl;
    sfIntRect buttonpr;
}interface_t;

typedef struct move_mob
{
    sfIntRect rect;
    sfVector2f move_vector;
    int direction;
    struct move_mob *next;
}move_mob_t;

typedef struct place_build
{
    sfIntRect rect;
    struct place_build *next;
}place_build_t;

typedef struct sound
{
    sfMusic *song;
    sfMusic *bs_dmg;
    sfMusic *zn_dmg;
    sfMusic *sp_dmg;
    sfMusic *explo;
    sfMusic *mob_sound;
    sfMusic *mob_death;
    sfMusic *error;
}sound_t;

typedef struct
{
    sfClock *clock;
    sfRenderWindow *window;
    struct texture *tex;
    struct sprite *spr;
    struct enemy *mob;
    struct building *build;
    struct place_build *pbuild;
    struct interface *itf;
    struct move_mob *move;
    struct sound *sd;
    int mouse_is_used;
    sfVector2f spawn_mob;
    int score;
    sfText *score_text;
    sfFont *score_font;
    int pause;
    int quit;
}objects_t;

void initialize(objects_t *);
void init_move_mob(objects_t *);
void init_place_build(objects_t *);
void init_button(objects_t *);
void init_sound(objects_t *);
void init_mob(objects_t *);
int game_loop(objects_t *);
void game_render(objects_t *);
void game_render_pause(objects_t *);
void game_render_button(objects_t *);
void display_mob(objects_t *);
void game_event(objects_t *, sfEvent);
void game_event_pause(objects_t *, sfEvent);
void mob_handling(objects_t *);
void create_mob(objects_t *, enemy_t *);
void create_new_build(objects_t *, int);
int place_new_build(objects_t *);
void mob_damage(objects_t *);
void tower_damage(objects_t *);
void check_dead(objects_t *);
void delete_dead(objects_t *);
void free_game(objects_t *);

#endif
