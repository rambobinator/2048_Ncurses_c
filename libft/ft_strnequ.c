/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmasse <rmasse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 10:39:11 by rmasse            #+#    #+#             */
/*   Updated: 2013/12/03 13:17:14 by rmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t	i;

	if (!n)
		return (1);
	if ((!s1 && s2) || (!s2 && s1))
		return (0);
	if (!s1 && !s2)
		return (1);
	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i] && i < n)
		++i;
	if ((!s1[i] && !s2[i]) || i == n)
		return (1);
	return (0);
}
