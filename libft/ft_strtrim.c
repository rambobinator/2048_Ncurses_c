/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmasse <rmasse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 10:39:58 by rmasse            #+#    #+#             */
/*   Updated: 2014/01/26 20:54:30 by rmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static size_t	find_str_blank_limit_start(const char *s)
{
	size_t		i;

	i = 0;
	while (s[i])
	{
		if (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
			++i;
		else
			return (i + 1);
	}
	return (0);
}

static size_t	find_str_blank_limit_end(const char *s)
{
	size_t		i;

	i = 0;
	while (s[i])
		++i;
	--i;
	while (i)
	{
		if (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
			--i;
		else
			return (i + 1);
	}
	if (s[0] == ' ' || s[0] == '\n' || s[0] == '\t')
		return (0);
	else
		return (1);
}

char			*ft_strtrim(char const *s)
{
	size_t		start;
	size_t		end;
	size_t		i;
	char		*r;

	if ((!s))
		return (NULL);
	start = find_str_blank_limit_start(s);
	end = find_str_blank_limit_end(s);
	if (start)
		start--;
	if (!(*s))
		return (ft_strdup((char*)s));
	if (!(r = malloc(sizeof(*r) * (end - start + 1))))
		return (NULL);
	i = 0;
	while (i < end - start)
	{
		r[i] = s[i + start];
		++i;
	}
	r[i] = 0;
	return (r);
}
