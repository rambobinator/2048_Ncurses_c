/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_ascii.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleger <gleger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 18:40:42 by gleger            #+#    #+#             */
/*   Updated: 2015/03/01 20:25:51 by gleger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "norme.h"

#define ALPHA_SIZE 3
#define ALPHA_1 ".-. . ,-.--. ,..-- ,---,,-..-."
#define ALPHA_2 "| |'|  / --|'-|'-.:-. / :-:`-;"
#define ALPHA_3 "'-''-''----'  '`-'`-''  `-' ' "

static void		display_alpha(int val, t_pt pos)
{
	int		i;

	i = val * ALPHA_SIZE - 1;
	if (val > 9 || val < 0)
		return ;
	while (++i < (ALPHA_SIZE * val) + ALPHA_SIZE)
	{
		mvaddch(pos.y + -1, pos.x, ALPHA_1[i]);
		mvaddch(pos.y + 0, pos.x, ALPHA_2[i]);
		mvaddch(pos.y + 1, pos.x, ALPHA_3[i]);
		pos.x++;
	}
}

static void		display_alpha_str(int val, t_pt pos)
{
	char		*str;
	int			i;

	i = -1;
	str = ft_itoa(val);
	pos.x -= ((ft_strlen(str) * ALPHA_SIZE / 2));
	while (str[++i])
	{
		display_alpha(str[i] - 48, pos);
		pos.x += 3;
	}
	free(str);
}

void			overwrite_ascii(t_game *game)
{
	t_pt		pos;
	int			x;
	int			y;

	y = -1;
	while (++y < game->height)
	{
		x = -1;
		while (++x < game->width)
		{
			pos.x = x * (game->term.col - 1) / game->width +
			((game->term.col - 1) / game->width / 2);
			pos.y = y * (game->term.row - 1) / game->height +
			((game->term.row - 1) / game->width / 2);
			if (game->maps->map[y][x])
			{
				choose_color(game->maps->map[y][x]);
				display_alpha_str(game->maps->map[y][x], pos);
				attron(COLOR_PAIR(1));
			}
		}
	}
}
