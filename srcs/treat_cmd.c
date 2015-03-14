/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleger <gleger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 18:40:42 by gleger            #+#    #+#             */
/*   Updated: 2015/03/01 20:28:14 by gleger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "norme.h"

#define HASH_NB 4

static void	reset_off_set(t_pt *pt, t_pt vec, t_game *g)
{
	pt->x = -1;
	pt->y = -1;
	reset_pt(pt, vec, g);
}

static void	assign_vec(t_pt *vec, int input)
{
	int		i;
	t_hash	hash[HASH_NB];

	hash[0].val = TOP;
	hash[0].x = 0;
	hash[0].y = -1;
	hash[1].val = DOWN;
	hash[1].x = 0;
	hash[1].y = 1;
	hash[2].val = LEFT;
	hash[2].x = -1;
	hash[2].y = 0;
	hash[3].val = RIGHT;
	hash[3].x = 1;
	hash[3].y = 0;
	i = -1;
	while (++i < HASH_NB)
	{
		if (hash[i].val == input)
		{
			vec->x = hash[i].x;
			vec->y = hash[i].y;
		}
	}
}

static void	init_treatment(t_pt *pt, t_pt *off_set, t_pt *vec, t_game *g)
{
	ft_bzero(pt, sizeof(t_pt));
	ft_bzero(off_set, sizeof(t_pt));
	reset_pt(pt, *vec, g);
	reset_off_set(off_set, *vec, g);
}

int			treat_cmd(t_game *g, int input)
{
	t_pt	vec;
	t_pt	pt;
	t_pt	off_set;
	int		ret;

	ret = 0;
	assign_vec(&vec, input);
	init_treatment(&pt, &off_set, &vec, g);
	while (pt.y < g->height && pt.x < g->width)
	{
		ret += call_rec(g, vec, pt, &off_set);
		reset_pt(&pt, vec, g);
		reset_off_set(&off_set, vec, g);
		if (vec.x != 0)
		{
			off_set.y++;
			pt.y++;
		}
		else
		{
			off_set.x++;
			pt.x++;
		}
	}
	return (ret);
}
