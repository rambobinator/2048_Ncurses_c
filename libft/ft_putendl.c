/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmasse <rmasse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 10:42:47 by rmasse            #+#    #+#             */
/*   Updated: 2013/12/08 16:06:59 by rmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putendl(const char *s)
{
	char	c;

	while ((c = *s) != '\0')
	{
		write(1, &c, 1);
		s++;
	}
	write(1, "\n", 1);
}
