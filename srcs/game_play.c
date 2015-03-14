/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_play.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleger <gleger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 18:40:42 by gleger            #+#    #+#             */
/*   Updated: 2015/03/01 20:26:23 by gleger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "norme.h"

static void		update_display_game(t_env *env)
{
	if (env->games && (env->games->term.row < env->games->height * 4
		|| env->games->term.col < env->games->width * 7))
	{
		clear();
		display("! Terninal too small to display the game !", 0, 0, STRING);
		return ;
	}
	display(env->games, 0, 0, GAME);
}

int				play_game(t_env *env)
{
	int		event;
	int		old_w;
	int		old_h;

	display("play_game\n", 1, 0, STRING);
	update_display_game(env);
	while (1)
	{
		old_h = env->games->term.row;
		old_w = env->games->term.col;
		getmaxyx(stdscr, env->games->term.row, env->games->term.col);
		event = handle_keyboard_game_event(env->games);
		if (env->games->end == LOOSE_MAP)
			return (CONTINUE_GAME);
		if (event == -1)
			return (END_GAME);
		else if (event > 0 || old_h != env->games->term.row
			|| old_w != env->games->term.col)
			update_display_game(env);
		else
			continue ;
	}
	return (CONTINUE_GAME);
}
