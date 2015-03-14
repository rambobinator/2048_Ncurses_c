/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpopone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmasse <rmasse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/26 17:35:27 by rmasse            #+#    #+#             */
/*   Updated: 2013/12/08 13:34:15 by rmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstpopone(t_list **lst, void (*del)(void *, size_t))
{
	t_list	*prev;
	t_list	*next;

	prev = (*lst)->prev;
	next = (*lst)->next;
	if (prev)
	{
		prev->next = next;
		ft_lstdelone(lst, del);
	}
	else
	{
		ft_lstdelone(lst, del);
		*lst = next;
		(*lst)->prev = NULL;
	}
}
