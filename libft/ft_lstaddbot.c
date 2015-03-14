/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddbot.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmasse <rmasse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/26 12:33:27 by rmasse            #+#    #+#             */
/*   Updated: 2013/12/04 11:56:00 by rmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstaddbot(t_list **alst, t_list *new)
{
	t_list	*cur;

	if (!alst)
		return ;
	if (!(*alst))
	{
		*alst = new;
		return ;
	}
	cur = *alst;
	while (cur->next)
		cur = cur->next;
	cur->next = new;
	new->next = NULL;
	new->prev = cur;
}
