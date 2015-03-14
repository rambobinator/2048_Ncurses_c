/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_add_game.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleger <gleger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 18:40:42 by gleger            #+#    #+#             */
/*   Updated: 2015/03/01 20:26:59 by gleger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "norme.h"

static void		init_node(t_env *env, t_game *game)
{
	game->width = env->game_values.width;
	game->height = env->game_values.height;
	game->undo = env->game_values.undo;
	game->prev = NULL;
	game->id = env->game_nbr;
	env->game_nbr++;
	game->end = NORME_MAP;
	ft_bzero(&(game->term), sizeof(t_term));
	getmaxyx(stdscr, game->term.row, game->term.col);
}

int				list_add_game(t_env *env)
{
	t_game		*game;

	if ((game = (t_game*)malloc(sizeof(t_game))) == NULL)
		return (-1);
	ft_bzero(game, sizeof(t_game));
	init_node(env, game);
	list_add_map(game, 0);
	if (!env->games)
		env->games = game;
	else
	{
		game->prev = env->games;
		env->games = game;
	}
	return (1);
}
