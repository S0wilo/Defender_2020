##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

SRC	=	src/main.c	\
		src/menu_scene.c	\
		src/display_menu_buttons.c	\
		src/destroy_and_free.c	\
		src/manage_music.c	\
		src/button_play.c	\
		src/button_exit.c	\
		src/button_help.c	\
		src/button_return.c	\
		src/help_scene.c	\
		src/initialize.c	\
		src/initialize_move_mob.c	\
		src/initialize_place_build.c	\
		src/initialize_button.c	\
		src/initialize_sound.c	\
		src/initialize_mob.c	\
		src/game_loop.c	\
		src/game_render.c	\
		src/game_render_pause.c	\
		src/game_render_button.c	\
		src/game_render_mob.c	\
		src/game_event.c	\
		src/game_event_pause.c	\
		src/mob_handling.c	\
		src/create_mob.c	\
		src/build_handling.c	\
		src/damage_to_build.c	\
		src/damage_to_mob.c	\
		src/check_delete_dead.c	\
		src/free_game.c

OBJ	=	$(SRC:.c=.o)

NAME	=	my_defender

CFLAGS += -I ./include/

CFLAGS += -l csfml-graphics -l csfml-system -l csfml-audio -L ./lib -lgraph -L ./ -lmy

all:   $(NAME)

$(NAME):    $(OBJ)
	make -C ./lib/my
	make -C ./lib/graph
	gcc $(OBJ) -o $(NAME) $(CFLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
