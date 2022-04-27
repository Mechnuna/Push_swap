/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a79856 <a79856@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 00:45:55 by a79856            #+#    #+#             */
/*   Updated: 2021/10/18 00:45:56 by a79856           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sa(t_list **stack)
{
	swap(stack);
	ft_putendl_fd("sa", 1);
}

static void	ra(t_list **stack)
{
	rotate(stack, 0);
	ft_putendl_fd("ra", 1);
}

static void	rra(t_list **stack)
{
	rotate(stack, 1);
	ft_putendl_fd("rra", 1);
}

void	sort_three(t_list **stack)
{
	if (!(*stack)->next || !(*stack)->next->next)
		return ;
	if (get_number(*stack, 1) < get_number(*stack, 0)
		&& get_number(*stack, 0) < get_number(*stack, 2))
		sa(stack);
	else if (get_number(*stack, 2) < get_number(*stack, 1)
		&& get_number(*stack, 1) < get_number(*stack, 0))
	{
		sa(stack);
		rra(stack);
	}
	else if (get_number(*stack, 1) < get_number(*stack, 2)
		&& get_number(*stack, 2) < get_number(*stack, 0))
		ra(stack);
	else if (get_number(*stack, 0) < get_number(*stack, 2)
		&& get_number(*stack, 2) < get_number(*stack, 1))
	{
		sa(stack);
		ra(stack);
	}
	else if (get_number(*stack, 2) < get_number(*stack, 0)
		&& get_number(*stack, 0) < get_number(*stack, 1))
		rra(stack);
}
