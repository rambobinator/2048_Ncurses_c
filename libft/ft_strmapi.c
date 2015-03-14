/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmasse <rmasse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 10:38:19 by rmasse            #+#    #+#             */
/*   Updated: 2013/12/03 13:15:47 by rmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char		*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*res;
	size_t	i;

	if (!s)
		return (NULL);
	if (!(res = (char*)malloc((ft_strlen(s) + 1) * sizeof(*res))))
		return (NULL);
	i = 0;
	while (s[i])
	{
		if (f)
			res[i] = f(i, s[i]);
		i++;
	}
	res[i] = 0;
	return (res);
}
