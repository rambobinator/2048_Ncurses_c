/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleger <gleger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 18:40:42 by gleger            #+#    #+#             */
/*   Updated: 2015/03/01 20:25:57 by gleger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "norme.h"

static int		tile_get_value(int x, int y, t_game *game)
{
	int		map_x;
	int		map_y;

	map_x = x / ((game->term.col - 1) / game->width);
	map_y = y / ((game->term.row - 1) / game->height);
	return (game->maps->map[map_y][map_x]);
}

static void		draw_tile(int x, int y, t_game *game)
{
	int			value;
	char		*str;
	int			w;
	int			h;

	w = game->term.col - 1;
	h = game->term.row - 1;
	value = tile_get_value(x, y, game);
	str = ft_itoa(value);
	choose_color(value);
	if (x % (w / game->width) == (w / 2 / game->width)
		&& y % (h / game->height) == (h / 2 / game->height)
		&& value && (w / game->width) < 4 * 3 * 4)
	{
		game->term.cur_x += ft_strlen(str) - 1;
		addstr(str);
	}
	else
		addch(' ');
	attron(COLOR_PAIR(1));
	free(str);
}

static void		draw_frame(int x, int y, t_game *game)
{
	int			w;
	int			h;
	int			y_max;
	int			x_max;

	w = game->term.col - 1;
	h = game->term.row - 1;
	x_max = game->width * (w / game->width);
	y_max = game->height * (h / game->height);
	attron(COLOR_PAIR(1));
	if (x > x_max || y > y_max)
		return ;
	if (x % (w / game->width) == 0)
		addch('|');
	else if (y % (h / game->height) == 0)
		addch('.');
	else
	{
		draw_tile(x, y, game);
	}
}

void			display_game(t_game *game, int y, int x)
{
	t_term		*term;

	clear();
	x += y;
	term = &(game->term);
	term->cur_y = 0;
	game->term.row -= 5;
	while (term->cur_y < term->row)
	{
		term->cur_x = 0;
		while (term->cur_x < term->col)
		{
			move(term->cur_y, term->cur_x);
			draw_frame(term->cur_x, term->cur_y, game);
			term->cur_x++;
		}
		term->cur_y++;
	}
	if (((game->term.col - 1) / game->width) >= 4 * 3 * 4)
		overwrite_ascii(game);
	mvprintw(term->cur_y++, 0, "SCORE :%d ", game->maps->score);
	mvprintw(term->cur_y++, 0, "STROKE :%d ", game->maps->stroke);
	mvprintw(term->cur_y++, 0, "UNDO :%d ", game->undo);
	if (game->win == WIN_MAP)
		mvprintw(term->cur_y, 0, "YOU WON", game->undo);
}
