#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rmasse <rmasse@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/12/13 19:03:33 by rmasse            #+#    #+#              #
#    Updated: 2015/03/01 20:47:39 by gleger           ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = game_2048

CC = gcc

FLAG = -Wall -Wextra -Werror -g

RM = rm -f

SRC =	main.c \
		error_manager.c \
		game_init.c \
		game_play.c \
		game_end.c \
		display.c \
		display_game.c \
		display_ascii.c \
		handle_game_event.c \
		handle_menu_event.c \
		list_add_game.c\
		list_add_map.c\
		map.c\
		scores.c\
		treat_cmd.c\
		reset_pt.c\
		call_rec.c\
		poweroftwo.c\
		gnl.c\
		hall_of_fame.c\
		insert_random.c\
		list_map_undo.c\
		ncurses_manager.c\
		menu_values_picker.c\
		color_change.c\
		
OBJ = $(SRC:.c=.o)

LIBFT = libft/libft.a

all : $(NAME)

$(LIBFT) :
	@make -C libft

%.o : srcs/%.c
	@$(CC) -c $(FLAG) $< -I includes/

$(NAME) : $(OBJ) $(LIBFT) includes/norme.h
	@$(CC) -o $(NAME) $(OBJ) -L libft/ -lft -lncurses
	@echo "\033[32m[build] --- $(NAME) created\033[0m"

clean :
	@$(RM) $(OBJ)
	@make -C libft clean
	@echo "\033[31m[build] --- $(NAME) *.o deleted\033[0m"

fclean : clean
	@$(RM) $(NAME)
	@make -C libft fclean
	@echo "\033[31m[build] --- $(NAME) bin deleted\033[0m"

re : fclean all

