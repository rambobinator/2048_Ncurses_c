/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleger <gleger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 18:40:42 by gleger            #+#    #+#             */
/*   Updated: 2015/03/01 20:27:22 by gleger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "norme.h"

int	create_table(t_map *map, int height, int widht)
{
	int		i;
	size_t	size;

	i = -1;
	size = sizeof(int *) * height;
	map->map = malloc(size);
	if (map->map == NULL)
		return (-1);
	ft_bzero(map->map, size);
	size = sizeof(int) * widht;
	while (++i < height)
	{
		map->map[i] = malloc(size);
		if (map->map[i] == NULL)
			return (-1);
		ft_bzero(map->map[i], size);
	}
	return (0);
}
