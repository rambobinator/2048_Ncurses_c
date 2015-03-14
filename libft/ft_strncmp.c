/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmasse <rmasse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 12:15:42 by rmasse            #+#    #+#             */
/*   Updated: 2013/12/22 17:12:24 by rmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int		c;
	int		i;

	i = 0;
	c = (int)n;
	while (s1[i] != '\0' && s1[i] == s2[i] && i < c - 1)
		i++;
	if (s1[i] < s2[i] && c != 0)
		return (-1);
	else if (s2[i] < s1[i] && c != 0)
		return (1);
	else
		return (0);
}
