/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_random.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleger <gleger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 18:40:42 by gleger            #+#    #+#             */
/*   Updated: 2015/03/01 20:26:53 by gleger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "norme.h"

static int	ipow(int base, int exp)
{
	int result;

	result = 1;
	while (exp)
	{
		if (exp & 1)
			result *= base;
		exp >>= 1;
		base *= base;
	}
	return (result);
}

static void	insert_random_map(t_game *game, t_pt *pts, int size, int nb)
{
	int	rand_it;
	int	rand_value;

	srand(clock());
	rand_it = rand() % size;
	rand_value = rand() % nb + 1;
	rand_value = ipow(2, rand_value);
	game->maps->map[pts[rand_it].y][pts[rand_it].x] = rand_value;
}

static int	attrib_pts(t_game *game, t_pt *pts)
{
	int	h;
	int	w;
	int	i;

	i = 0;
	h = -1;
	while (++h < game->height)
	{
		w = -1;
		while (++w < game->width)
		{
			if (!game->maps->map[h][w])
			{
				pts[i].x = w;
				pts[i].y = h;
				i++;
			}
		}
	}
	return (i);
}

int			call_random_map(t_game *game, int nb)
{
	t_pt	pts[game->width * game->height];
	int		slots;

	if (!(slots = attrib_pts(game, pts)))
		return (slots);
	insert_random_map(game, pts, slots, nb);
	return (slots);
}
