/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a79856 <a79856@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 00:45:01 by a79856            #+#    #+#             */
/*   Updated: 2021/10/18 04:03:20 by a79856           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rr(t_list **a, t_list **b, t_steps steps)
{
	while (steps.rr > 0)
	{
		rotate(a, 0);
		rotate(b, 0);
		ft_putendl_fd("rr", 1);
		steps.rr--;
	}
	while (steps.rrr > 0)
	{
		rotate(a, 1);
		rotate(b, 1);
		ft_putendl_fd("rrr", 1);
		steps.rrr--;
	}
}

static void	ra(t_list **a, t_steps steps)
{
	while (steps.ra > 0)
	{
		rotate(a, 0);
		ft_putendl_fd("ra", 1);
		steps.ra--;
	}
	while (steps.rra > 0)
	{
		rotate(a, 1);
		ft_putendl_fd("rra", 1);
		steps.rra--;
	}
}

static void	rb(t_list **b, t_steps steps)
{
	while (steps.rb > 0)
	{
		rotate(b, 0);
		ft_putendl_fd("rb", 1);
		steps.rb--;
	}
	while (steps.rrb > 0)
	{
		rotate(b, 1);
		ft_putendl_fd("rrb", 1);
		steps.rrb--;
	}
}

void	apply_steps(t_list **a, t_list **b, t_steps steps)
{
	rr(a, b, steps);
	ra(a, steps);
	rb(b, steps);
}
