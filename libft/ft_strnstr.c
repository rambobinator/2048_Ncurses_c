/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmasse <rmasse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/28 09:55:39 by rmasse            #+#    #+#             */
/*   Updated: 2013/12/08 14:23:16 by rmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	char	*temp1;
	char	*temp2;
	char	*pos;

	temp1 = (char *)s1;
	if (!*s2)
		return ((char *)s1);
	while (*temp1)
	{
		pos = temp1;
		temp2 = (char *)s2;
		while (*temp1 && *temp2 && n && (*temp1 == *temp2))
		{
			temp1++;
			temp2++;
			n--;
		}
		if (!*temp2)
			return (pos);
		temp1 = pos + 1;
	}
	return (NULL);
}
