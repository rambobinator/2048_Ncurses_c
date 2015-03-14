/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_pt.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleger <gleger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 18:40:42 by gleger            #+#    #+#             */
/*   Updated: 2015/03/01 20:27:51 by gleger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "norme.h"

void	reset_pt(t_pt *pt, t_pt vec, t_game *g)
{
	if (vec.x > 0)
		pt->x = g->width - 1;
	else if (vec.x < 0)
		pt->x = 0;
	if (vec.y > 0)
		pt->y = g->height - 1;
	else if (vec.y < 0)
		pt->y = 0;
}
