/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleger <gleger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 18:40:42 by gleger            #+#    #+#             */
/*   Updated: 2015/03/01 20:27:17 by gleger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "norme.h"

static int			init_app(t_env *env)
{
	t_menu			app_menu[3];

	app_menu[0].select = 0;
	app_menu[0].str = "New Game";
	app_menu[0].menu_cmd = NULL;
	app_menu[0].ret = CONTINUE_APP;
	app_menu[1].select = 0;
	app_menu[1].str = "Leaderboard";
	app_menu[1].menu_cmd = display_hall_of_fame;
	app_menu[1].ret = CONTINUE_APP;
	app_menu[2].select = 0;
	app_menu[2].str = "Quit program";
	app_menu[2].menu_cmd = NULL;
	app_menu[2].ret = END_APP;
	env->game_nbr = 0;
	set_ncurses(INIT_NCURSES);
	return (handle_keyboard_menu_event(env, app_menu, 3));
}

static int			do_app(t_env *env)
{
	int	ret;
	int	i;
	int (*game_step[GAME_STEPS])(t_env *env);

	game_step[0] = init_game;
	game_step[1] = play_game;
	game_step[2] = end_game;
	i = -1;
	while (++i < GAME_STEPS)
	{
		if ((ret = game_step[i](env)) != CONTINUE_GAME)
			return (handle_error(ret, env));
	}
	return (ret);
}

static int			end_app(t_env *env)
{
	(void)env;
	set_ncurses(END_NCURSES);
	return (0);
}

int					main(void)
{
	t_env	env;

	if (!poweroftwo(WIN_VALUE))
	{
		ft_putstr("WIN_VALUE is not a power of two.\n");
		return (0);
	}
	if (init_app(&env))
	{
		while (do_app(&env))
			;
	}
	end_app(&env);
	return (0);
}
