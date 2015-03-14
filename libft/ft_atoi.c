/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmasse <rmasse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/27 10:00:56 by rmasse            #+#    #+#             */
/*   Updated: 2013/12/08 16:10:14 by rmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_atoi_additionner(const char *str, int sign)
{
	size_t	i;
	int		res;

	i = 0;
	res = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = (res << 3) + (res << 1) + (str[i] - '0');
		++i;
	}
	return (sign * res);
}

int			ft_atoi(const char *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\v'
		|| str[i] == '\r' || str[i] == '\f' || str[i] == '\n')
		i++;
	if ((str[i] < '0' || str[i] > '9') && str[i] != '-' && str[i] != '+')
		return (0);
	if (str[i] == '-')
		return (ft_atoi_additionner(str + i + 1, -1));
	if (str[i] == '+')
		return (ft_atoi_additionner(str + i + 1, 1));
	return (ft_atoi_additionner(str + i, 1));
}
