/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmasse <rmasse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/27 10:00:56 by rmasse            #+#    #+#             */
/*   Updated: 2013/12/01 20:39:29 by rmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strncat(char *s1, const char *s2, size_t n)
{
	char	*temp;

	temp = (char *)s1;
	while (*temp)
		++temp;
	while (*s2 && n--)
		*temp++ = *s2++;
	return (s1);
}
