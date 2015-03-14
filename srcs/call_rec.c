/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_rec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleger <gleger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 18:40:42 by gleger            #+#    #+#             */
/*   Updated: 2015/03/01 20:25:27 by gleger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "norme.h"

#define NOTHING 0
#define FUSION 1
#define DEC 2

static int		fusion(t_game *g, int x, int y, t_pt pt)
{
	g->maps->map[y][x] += g->maps->map[pt.y][pt.x];
	g->maps->map[pt.y][pt.x] = 0;
	g->maps->score += g->maps->map[y][x];
	g->maps->merges += 1;
	return (FUSION);
}

static int		resolve(t_game *g, t_pt vec, t_pt pt, t_pt *off_set)
{
	int	x;
	int	y;

	x = pt.x + vec.x;
	y = pt.y + vec.y;
	if (x < 0 || x >= g->width || y < 0 || y >= g->height ||
		!g->maps->map[pt.y][pt.x] || (g->maps->map[y][x] &&
		g->maps->map[y][x] != g->maps->map[pt.y][pt.x]))
		return (NOTHING);
	if (!g->maps->map[y][x])
	{
		g->maps->map[y][x] = g->maps->map[pt.y][pt.x];
		g->maps->map[pt.y][pt.x] = 0;
		return (DEC);
	}
	else if ((y != off_set->y || x != off_set->x) && (pt.y != off_set->y ||
		pt.x != off_set->x) && g->maps->map[y][x] == g->maps->map[pt.y][pt.x])
	{
		off_set->x = x;
		off_set->y = y;
		return (fusion(g, x, y, pt));
	}
	return (NOTHING);
}

int				call_rec(t_game *g, t_pt vec, t_pt pt, t_pt *off_set)
{
	int			ret;

	ret = resolve(g, vec, pt, off_set);
	if (ret == FUSION || ret == DEC)
	{
		g->merge_tmp++;
		g->count_tmp = 0;
		reset_pt(&pt, vec, g);
	}
	else
	{
		if (g->count_tmp == g->width - 1)
		{
			ret = g->merge_tmp;
			g->merge_tmp = 0;
			g->count_tmp = 0;
			return (ret);
		}
		pt.x -= vec.x;
		pt.y -= vec.y;
		g->count_tmp++;
	}
	return (call_rec(g, vec, pt, off_set));
}
