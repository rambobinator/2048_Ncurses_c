/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmasse <rmasse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/29 10:09:07 by rmasse            #+#    #+#             */
/*   Updated: 2013/12/01 21:28:56 by rmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memccpy(void *s1, const void *s2, int c, size_t n)
{
	unsigned char	*temp;
	unsigned char	*temp2;

	temp = (unsigned char *)s1;
	temp2 = (unsigned char *)s2;
	while (n--)
	{
		if (*temp2 == (unsigned char)c)
			return (++temp);
		*(temp++) = *(temp2++);
	}
	return (NULL);
}
