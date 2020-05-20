/*
** EPITECH PROJECT, 2019
** my_hunter
** File description:
** header for my_hunter
*/

#ifndef MY_HUNTER_H
#define MY_HUNTER_H
#include "csfml_struct.h"

void init_button_play(csfml_t *csfml);
void init_button_help(csfml_t *csfml);
void init_button_exit(csfml_t *csfml);
void init_button_back(csfml_t *csfml);
int button_play_is_clicked(csfml_t *csfml);
int button_help_is_clicked(csfml_t *csfml);
int button_exit_is_clicked(csfml_t *csfml);
int button_back_is_clicked(csfml_t *csfml);
int create_helper(csfml_t *csfml);
int create_menu_background(csfml_t *csfml);
int create_helper_background(csfml_t *csfml);
void create_music(csfml_t *csfml);
void disp_main_menu(csfml_t *csfml);
void disp_help_scene(csfml_t *csfml);
void game_scene(csfml_t *csfml);
void destroy_all(csfml_t *csfml);
void destroy_main_menu(csfml_t *csfml);
void display_menu_buttons(csfml_t *);
#endif
