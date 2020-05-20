##
## EPITECH PROJECT, 2019
## MAKEFILE
## File description:
## Makefile
##

SRC	=	my_putchar.c\
		my_isneg.c\
		my_put_nbr.c\
		my_swap.c\
		my_putstr.c\
		my_strlen.c\
		my_strcpy.c\
		my_strncpy.c\
		my_revstr.c\
		my_strstr.c\
		my_strcmp.c\
		my_strncmp.c\
		my_strupcase.c\
		my_strlowcase.c\
		my_strcapitalize.c\
		my_str_isalpha.c\
		my_str_isnum.c\
		my_str_islower.c\
		my_str_isupper.c\
		my_str_isprintable.c\
		my_showstr.c\
		my_showmem.c\
		my_strcat.c\
		my_strncat.c\
		my_show_word_array.c\
		my_strdup.c	\
		int_to_str.c

SRCO=	my_putchar.o\
		my_isneg.o\
		my_put_nbr.o\
		my_swap.o\
		my_putstr.o\
		my_strlen.o\
		my_strcpy.o\
		my_strncpy.o\
		my_revstr.o\
		my_strstr.o\
		my_strcmp.o\
		my_strncmp.o\
		my_strupcase.o\
		my_strlowcase.o\
		my_strcapitalize.o\
		my_str_isalpha.o\
		my_str_isnum.o\
		my_str_islower.o\
		my_str_isupper.o\
		my_str_isprintable.o\
		my_showstr.o\
		my_showmem.o\
		my_strcat.o\
		my_strncat.o\
		my_show_word_array.o\
		my_strdup.o	\
		int_to_str.o


LIB =	libmy.a

all:	compilib movelib clean

compilib: $(SRC) $(SRCO)
		gcc -c -Iinclude $(SRC); ar rc $(LIB) $(SRCO)

movelib: $(LIB)
		mv $(LIB) ../../

clean:
		rm -f $(SRCO)
