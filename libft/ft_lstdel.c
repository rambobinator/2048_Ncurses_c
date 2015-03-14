/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmasse <rmasse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 17:08:10 by rmasse            #+#    #+#             */
/*   Updated: 2013/12/04 13:16:56 by rmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*next;
	t_list	*link;

	if (!alst || !(*alst))
		return ;
	link = *alst;
	next = link;
	while (next)
	{
		link = next;
		next = link->next;
		ft_lstdelone(&link, del);
	}
	*alst = NULL;
}
