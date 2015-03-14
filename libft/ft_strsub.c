/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmasse <rmasse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 10:39:33 by rmasse            #+#    #+#             */
/*   Updated: 2013/12/03 13:19:34 by rmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char		*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*r;
	size_t	i;

	if (!s)
		return (NULL);
	if (!(r = malloc(sizeof(*r) * (len + 1))))
		return (NULL);
	i = 0;
	while (len)
	{
		--len;
		r[i] = s[start + i];
		++i;
	}
	r[i] = 0;
	return (r);
}
