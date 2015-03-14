/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_add_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleger <gleger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 18:40:42 by gleger            #+#    #+#             */
/*   Updated: 2015/03/01 20:27:04 by gleger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "norme.h"

static int		check_end_game(t_game *game)
{
	int	h;
	int	w;
	int	nb;

	nb = 0;
	h = -1;
	while (++h < game->height)
	{
		w = -1;
		while (++w < game->width)
		{
			if (game->maps->map[h][w])
				nb++;
			if (game->maps->map[h][w] >= WIN_VALUE)
				game->win = WIN_MAP;
		}
	}
	if (game->height * game->width == nb)
		return (FULL_MAP);
	else
		return (NORME_MAP);
}

static void		copy_map(t_game *game)
{
	int	h;
	int	w;

	h = -1;
	while (++h < game->height)
	{
		w = -1;
		while (++w < game->width)
			game->maps->map[h][w] = game->maps->prev->map[h][w];
	}
}

static void		init_map(t_game *game, t_map *map)
{
	map->next = NULL;
	map->merges = 0;
	create_table(map, game->width, game->height);
	call_random_map(game, 2);
	call_random_map(game, 2);
	map->stroke = 0;
	map->score = 0;
}

static int		allocate_map(t_game *game)
{
	t_map		*map;

	if ((map = (t_map*)malloc(sizeof(t_map))) == NULL)
		return (-1);
	if (!game->maps)
	{
		game->maps = map;
		map->prev = NULL;
		init_map(game, map);
		return (NORME_MAP);
	}
	map->prev = game->maps;
	map->prev->next = map;
	game->maps = map;
	map->next = NULL;
	map->merges = 0;
	create_table(map, game->width, game->height);
	copy_map(game);
	map->stroke = map->prev->stroke + 1;
	game->maps->score = game->maps->prev->score;
	return (0);
}

int				list_add_map(t_game *game, int cmd)
{
	int	i;
	int	ret;

	if ((allocate_map(game)) == -1)
		return (-1);
	if (game->maps->prev == NULL)
		return (1);
	if (treat_cmd(game, cmd))
		call_random_map(game, 2);
	else
		list_undo_map(game, 0);
	if (check_end_game(game) == FULL_MAP)
	{
		i = -1;
		while (++i < 4)
		{
			allocate_map(game);
			ret = treat_cmd(game, i);
			list_undo_map(game, 0);
			if (ret)
				return (1);
		}
		game->end = LOOSE_MAP;
	}
	return (1);
}
