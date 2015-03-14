/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmasse <rmasse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 10:41:26 by rmasse            #+#    #+#             */
/*   Updated: 2013/12/03 12:59:16 by rmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static size_t	nb_len(int n)
{
	size_t		i;

	if (!n)
		return (1);
	i = 0;
	if (n < 0)
		++i;
	while (n)
	{
		n /= 10;
		++i;
	}
	return (i);
}

char			*ft_itoa(int n)
{
	char		*r;
	size_t		i;
	int			temp_neg;
	int			isneg;

	i = nb_len(n);
	if (!(r = malloc(sizeof(*r) * (i + 1))))
		return (NULL);
	r[i] = 0;
	isneg = 1;
	if (n < 0)
		isneg = -1;
	while (i)
	{
		--i;
		temp_neg = n % 10;
		r[i] = '0' + (temp_neg * isneg);
		n /= 10;
	}
	if (isneg == -1)
		r[0] = '-';
	return (r);
}
