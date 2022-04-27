/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_remove_if.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a79856 <a79856@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 22:18:56 by a79856            #+#    #+#             */
/*   Updated: 2021/10/18 03:16:15 by a79856           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lst_remove(t_list **begin_list, void *ref,
							int (*cmp)(), void (*free_)(void *))
{
	t_list	*prev;
	t_list	*elem;

	prev = NULL;
	elem = *begin_list;
	while (elem)
	{
		if ((*cmp)(elem->content, ref) == 0)
		{
			if (prev == NULL)
				*begin_list = elem->next;
			else
				prev->next = elem->next;
			(*free_)(elem->content);
			free(elem);
		}
		prev = elem;
		elem = elem->next;
	}
}
