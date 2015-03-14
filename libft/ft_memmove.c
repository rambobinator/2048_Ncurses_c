/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmasse <rmasse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/29 10:09:07 by rmasse            #+#    #+#             */
/*   Updated: 2014/01/26 20:55:33 by rmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void				*ft_memmove(void *s1, const void *s2, size_t n)
{
	unsigned char	*temp;
	size_t			i;

	i = 0;
	temp = (unsigned char *)malloc(n);
	while (i < n)
	{
		temp[i] = ((unsigned char*)(s2))[i];
		++i;
	}
	s1 = ft_memcpy(s1, temp, n);
	free(temp);
	return (s1);
}
