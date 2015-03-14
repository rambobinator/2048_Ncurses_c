/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ncurses_manager.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleger <gleger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 18:40:42 by gleger            #+#    #+#             */
/*   Updated: 2015/03/01 20:44:02 by gleger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "norme.h"

static void		create_colors(void)
{
	init_color(21, 186 * 4, 172 * 4, 160 * 4);
	init_color(10, 237 * 4, 228 * 4, 218 * 4);
	init_color(11, 235 * 4, 223 * 4, 202 * 4);
	init_color(12, 237 * 4, 177 * 4, 128 * 4);
	init_color(13, 245 * 4, 149 * 4, 98 * 4);
	init_color(14, 242 * 4, 124 * 4, 94 * 4);
	init_color(15, 245 * 4, 94 * 4, 56 * 4);
	init_color(16, 235 * 4, 204 * 4, 113 * 4);
	init_color(17, 235 * 4, 197 * 4, 103 * 4);
	init_color(18, 235 * 4, 198 * 4, 80 * 4);
	init_color(19, 235 * 4, 194 * 4, 70 * 4);
	init_color(20, 237 * 4, 193 * 4, 47 * 4);
}

static void		init_color_codes(void)
{
	start_color();
	create_colors();
	init_pair(1, COLOR_BLACK, 21);
	init_pair(2, COLOR_BLACK, 10);
	init_pair(3, COLOR_BLACK, 11);
	init_pair(4, COLOR_BLACK, 12);
	init_pair(5, COLOR_BLACK, 13);
	init_pair(6, COLOR_BLACK, 14);
	init_pair(7, COLOR_BLACK, 15);
	init_pair(8, COLOR_BLACK, 16);
	init_pair(9, COLOR_BLACK, 17);
	init_pair(10, COLOR_BLACK, 18);
	init_pair(11, COLOR_BLACK, 19);
	init_pair(12, COLOR_BLACK, 20);
	bkgd(COLOR_PAIR(1));
}

int				set_ncurses(int mode)
{
	if (mode == INIT_NCURSES || mode == RESET_NCURSES)
	{
		initscr();
		noecho();
		cbreak();
		curs_set(FALSE);
		keypad(stdscr, TRUE);
		init_color_codes();
	}
	else if (mode == END_NCURSES)
	{
		delwin(stdscr);
		endwin();
	}
	else
		return (0);
	return (1);
}
