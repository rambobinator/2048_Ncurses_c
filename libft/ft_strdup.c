/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmasse <rmasse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/27 10:00:56 by rmasse            #+#    #+#             */
/*   Updated: 2013/12/08 14:21:32 by rmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char		*ft_strdup(const char *s1)
{
	size_t	size;
	char	*s2;
	int		i;

	i = 0;
	s2 = 0;
	if (s1 == 0)
		return (s2);
	size = ft_strlen(s1) + 1;
	s2 = (char *)malloc(sizeof(*s1) * size);
	if (s2 == NULL)
		return (s2);
	while (i < (int)size - 1)
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}
