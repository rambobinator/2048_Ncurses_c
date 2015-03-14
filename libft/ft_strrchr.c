/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmasse <rmasse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/27 10:00:56 by rmasse            #+#    #+#             */
/*   Updated: 2013/12/01 20:46:08 by rmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strrchr(const char *s, int c)
{
	int		size;
	char	*temp;

	temp = (char *)s;
	size = ft_strlen(temp) + 1;
	while (size-- >= 0)
	{
		if (temp[size] == (char)c)
			return (temp + size);
	}
	return (NULL);
}
