/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a79856 <a79856@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 00:45:28 by a79856            #+#    #+#             */
/*   Updated: 2021/10/18 03:06:54 by a79856           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	swap(t_list **stack)
{
	void	*tmp;

	if (!(*stack) || !((*stack)->next))
		return (1);
	tmp = (*stack)->content;
	(*stack)->content = (*stack)->next->content;
	(*stack)->next->content = tmp;
	return (1);
}

int	push(t_list **stack1, t_list **stack2)
{
	t_list	*lst;

	if (!(*stack2))
		return (1);
	lst = ft_lstpop_front(stack2);
	ft_lstadd_front(stack1, lst);
	return (1);
}

int	rotate(t_list **stack, int reverse)
{
	t_list	*lst;

	if (!reverse)
	{
		lst = ft_lstpop_front(stack);
		if (lst)
			ft_lstadd_back(stack, lst);
	}
	else
	{
		lst = ft_lstpop_back(stack);
		if (lst)
			ft_lstadd_front(stack, lst);
	}
	return (1);
}
