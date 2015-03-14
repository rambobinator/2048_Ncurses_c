/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmasse <rmasse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 10:36:19 by rmasse            #+#    #+#             */
/*   Updated: 2013/12/03 13:17:52 by rmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char		*ft_strnew(size_t size)
{
	char	*r;
	size_t	i;

	if (!(r = malloc((size + 1) * sizeof(*r))))
		return (NULL);
	i = 0;
	while (i < size + 1)
	{
		r[i] = 0;
		++i;
	}
	return (r);
}
