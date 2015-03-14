/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleger <gleger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 18:40:42 by gleger            #+#    #+#             */
/*   Updated: 2015/03/01 20:25:39 by gleger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "norme.h"

static void		display_string(char *data, int y, int x)
{
	mvprintw(y, x, "%s", data);
}

static void		display_int(int *data, int y, int x)
{
	mvprintw(y, x, "%d", *data);
}

int				display(void *data, int y, int x, int type)
{
	if (type == STRING)
		display_string((char *)data, y, x);
	else if (type == INT)
		display_int((int *)data, y, x);
	else if (type == GAME)
		display_game((t_game *)data, y, x);
	refresh();
	return (0);
}
