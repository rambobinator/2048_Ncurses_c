/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmasse <rmasse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 10:35:25 by rmasse            #+#    #+#             */
/*   Updated: 2013/12/03 13:00:21 by rmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void		*ft_memalloc(size_t size)
{
	char	*r;

	if (!(r = malloc((size + 1) * sizeof(*r))))
		return (NULL);
	while (size + 1)
	{
		size--;
		r[size] = 0;
	}
	return ((void*)r);
}
