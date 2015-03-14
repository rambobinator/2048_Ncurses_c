/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleger <gleger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 18:40:42 by gleger            #+#    #+#             */
/*   Updated: 2015/03/01 20:26:16 by gleger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "norme.h"

static void	reset_game_values(t_env *env)
{
	env->game_values.undo = DEFAULT_UNDO;
	env->game_values.height = DEFAULT_Y;
	env->game_values.width = DEFAULT_X;
}

int			init_game(t_env *env)
{
	t_menu			game_menu[3];

	game_menu[0].select = 0;
	game_menu[0].str = "Start Game";
	game_menu[0].menu_cmd = NULL;
	game_menu[0].ret = CONTINUE_APP;
	game_menu[1].select = 0;
	game_menu[1].str = "Options";
	game_menu[1].menu_cmd = game_value_picker;
	game_menu[1].ret = CONTINUE_APP;
	game_menu[2].select = 0;
	game_menu[2].str = "Quit";
	game_menu[2].menu_cmd = NULL;
	game_menu[2].ret = END_APP;
	reset_game_values(env);
	if (!(handle_keyboard_menu_event(env, game_menu, 3)))
		return (END_GAME);
	list_add_game(env);
	return (CONTINUE_GAME);
}
