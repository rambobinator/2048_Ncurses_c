/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stradd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmasse <rmasse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 10:39:45 by rmasse            #+#    #+#             */
/*   Updated: 2013/12/03 13:12:20 by rmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char		*ft_stradd(char *s1, char *s2)
{
	char	*r;
	size_t	i;
	size_t	j;

	i = ft_strlen(s1) + ft_strlen(s2);
	if (!(r = malloc(sizeof(*r) * (i + 1))))
		return (NULL);
	i = 0;
	while (s1 && s1[i])
	{
		r[i] = s1[i];
		++i;
	}
	j = 0;
	while (s2 && s2[j])
	{
		r[i] = s2[j];
		++i;
		++j;
	}
	r[i] = 0;
	free(s1);
	return (r);
}
