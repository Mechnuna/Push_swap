/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a79856 <a79856@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 00:45:06 by a79856            #+#    #+#             */
/*   Updated: 2021/10/18 00:45:08 by a79856           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_list_sorted(t_list *lst, int len, int reverse)
{
	t_list	*prev;
	t_list	*node;

	if (!lst || !lst->next)
		return (1);
	prev = lst;
	node = lst->next;
	while (len > 1)
	{
		if (!reverse && *(int *)prev->content > *(int *)node->content)
			return (0);
		if (reverse && *(int *)prev->content < *(int *)node->content)
			return (0);
		prev = node;
		node = node->next;
		len--;
	}
	return (1);
}
