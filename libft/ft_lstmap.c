/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a79856 <a79856@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 22:10:01 by a79856            #+#    #+#             */
/*   Updated: 2021/10/15 22:10:02 by a79856           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*list;
	t_list	*new;
	t_list	*new2;

	if (!(lst))
		return (NULL);
	list = ft_lstnew((*f)(lst->content));
	if (!(list))
		return (NULL);
	new = list;
	new2 = lst->next;
	while (new2 != NULL)
	{
		new->next = ft_lstnew((*f)(new2));
		if (!(list))
		{
			ft_lstclear(&new, del);
			return (NULL);
		}
		new = new->next;
		new2 = new2->next;
	}
	return (list);
}
