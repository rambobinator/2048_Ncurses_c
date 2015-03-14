/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmasse <rmasse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/29 10:09:07 by rmasse            #+#    #+#             */
/*   Updated: 2013/12/08 16:10:07 by rmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memset(void *b, int c, size_t len)
{
	int				i;
	unsigned char	*temp;

	i = 0;
	temp = (unsigned char *)b;
	while (len--)
	{
		temp[i] = (unsigned char)c;
		i++;
	}
	return (temp);
}
