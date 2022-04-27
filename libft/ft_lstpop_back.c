/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpop_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a79856 <a79856@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 22:15:49 by a79856            #+#    #+#             */
/*   Updated: 2021/10/15 22:16:55 by a79856           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstpop_back(t_list **lst)
{
	t_list	*node;
	t_list	*prev;

	if (!(*lst))
		return (NULL);
	if (!((*lst)->next))
	{
		node = *lst;
		*lst = NULL;
		return (node);
	}
	node = *lst;
	while (node->next)
	{
		prev = node;
		node = node->next;
	}
	prev->next = NULL;
	return (node);
}
