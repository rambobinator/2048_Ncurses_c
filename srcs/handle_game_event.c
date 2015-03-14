/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_game_event.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleger <gleger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 18:40:42 by gleger            #+#    #+#             */
/*   Updated: 2015/03/01 20:26:42 by gleger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "norme.h"

int			handle_keyboard_game_event(t_game *game)
{
	int		key;

	key = getch();
	if (key == 27)
		return (END_GAME);
	else if (key == KEY_DOWN)
		return (list_add_map(game, DOWN));
	else if (key == KEY_UP)
		return (list_add_map(game, TOP));
	else if (key == KEY_LEFT)
		return (list_add_map(game, LEFT));
	else if (key == KEY_RIGHT)
		return (list_add_map(game, RIGHT));
	else if (key == KEY_ENTER)
		return (list_undo_map(game, 1));
	else
		return (0);
}
