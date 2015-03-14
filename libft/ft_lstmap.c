/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmasse <rmasse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 17:27:48 by rmasse            #+#    #+#             */
/*   Updated: 2013/12/04 12:21:28 by rmasse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static void	delfree(void *ptr, size_t size)
{
	free(ptr);
	(void)size;
}

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*start;
	t_list	*cur;
	t_list	*applied;

	if (!lst)
		return (NULL);
	start = NULL;
	while (lst)
	{
		if (!(cur = f(lst)))
		{
			ft_lstdel(&start, &delfree);
			return (NULL);
		}
		applied = ft_lstnew(cur->content, cur->content_size);
		ft_lstaddbot(&start, applied);
		lst = lst->next;
	}
	return (start);
}
