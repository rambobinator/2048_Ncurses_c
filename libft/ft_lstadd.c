/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmasse <rmasse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 17:16:52 by rmasse            #+#    #+#             */
/*   Updated: 2013/12/04 11:56:47 by rmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstadd(t_list **alst, t_list *new)
{
	t_list	*cur;

	if (!alst)
		return ;
	if (!(*alst))
	{
		*alst = new;
		return ;
	}
	cur = new;
	while (cur->next)
		cur = cur->next;
	cur->next = *alst;
	*alst = new;
}
