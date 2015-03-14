/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_map_undo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleger <gleger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 18:40:42 by gleger            #+#    #+#             */
/*   Updated: 2015/03/01 20:27:09 by gleger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "norme.h"

int			list_undo_map(t_game *game, int cmd)
{
	t_map	*old;
	int		i;

	if ((cmd && game->undo < 1) || !game->maps->prev)
		return (0);
	if (cmd)
		game->undo--;
	old = game->maps;
	game->maps = game->maps->prev;
	game->maps->next = NULL;
	i = -1;
	while (++i < game->height)
		free(old->map[i]);
	free(old->map);
	free(old);
	old = NULL;
	return (1);
}
