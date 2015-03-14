/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_change.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleger <gleger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 18:40:42 by gleger            #+#    #+#             */
/*   Updated: 2015/03/01 20:25:35 by gleger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "norme.h"

void		choose_color(int value)
{
	int		pow_two;

	pow_two = 1;
	while ((value /= 2) > 0)
	{
		pow_two++;
		if (pow_two > 12)
			pow_two = 1;
	}
	attron(COLOR_PAIR(pow_two));
}
