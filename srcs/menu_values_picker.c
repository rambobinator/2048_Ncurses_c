/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_values_picker.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleger <gleger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 18:40:42 by gleger            #+#    #+#             */
/*   Updated: 2015/03/01 20:27:31 by gleger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "norme.h"

static void			value_picker(char *str, int *value, int min)
{
	int				key;
	int				y;
	int				x;

	x = 0;
	y = 0;
	while (1)
	{
		display("# Use up/down arrows to change value,", y, x, STRING);
		display("# Press Return to validate !", y + 1, x, STRING);
		display(str, y + 3, x, STRING);
		display(value, y + 3, x + ft_strlen(str) + 1, INT);
		key = getch();
		if (key)
			clear();
		if (key == '\n')
			break ;
		else if (key == KEY_UP)
			*value = ((*value + 1 <= 99) ? *value + 1 : *value);
		else if (key == KEY_DOWN)
			*value = ((*value - 1 >= min) ? *value - 1 : *value);
	}
}

static int			display_undo_picker(t_env *env)
{
	value_picker("Undos :", &env->game_values.undo, 0);
	return (0);
}

static int			display_size_picker(t_env *env)
{
	value_picker("Size :", &env->game_values.height, 4);
	env->game_values.width = env->game_values.height;
	return (0);
}

int					game_value_picker(t_env *env)
{
	t_menu			game_values_menu[4];

	game_values_menu[0].select = 0;
	game_values_menu[0].str = "Start";
	game_values_menu[0].menu_cmd = NULL;
	game_values_menu[0].ret = 0;
	game_values_menu[1].select = 0;
	game_values_menu[1].str = "Change number of undo";
	game_values_menu[1].menu_cmd = display_undo_picker;
	game_values_menu[1].ret = 1;
	game_values_menu[2].select = 0;
	game_values_menu[2].str = "Change map size";
	game_values_menu[2].menu_cmd = display_size_picker;
	game_values_menu[2].ret = 1;
	game_values_menu[3].select = 0;
	game_values_menu[3].str = "Leaderboard";
	game_values_menu[3].menu_cmd = display_hall_of_fame;
	game_values_menu[3].ret = 1;
	while (handle_keyboard_menu_event(env, game_values_menu, 4))
		;
	return (0);
}
