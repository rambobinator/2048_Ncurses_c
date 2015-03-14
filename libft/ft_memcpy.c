/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmasse <rmasse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/28 09:55:39 by rmasse            #+#    #+#             */
/*   Updated: 2013/12/01 18:48:25 by rmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memcpy(void *s1, const void *s2, size_t n)
{
	unsigned char	*temp;
	unsigned char	*temp2;

	temp = (unsigned char *)s1;
	temp2 = (unsigned char *)s2;
	while (n--)
		*(temp++) = *(temp2++);
	return (s1);
}
