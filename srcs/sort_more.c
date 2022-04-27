/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_more.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a79856 <a79856@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 00:45:48 by a79856            #+#    #+#             */
/*   Updated: 2021/10/18 00:45:49 by a79856           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_steps	get_steps_start(t_list *stack, int min, int max)
{
	int		steps_top;
	int		steps_bottom;
	int		len;
	t_steps	steps;

	steps.ra = 0;
	steps.rb = 0;
	steps.rra = 0;
	steps.rrb = 0;
	steps.rr = 0;
	steps.rrr = 0;
	len = ft_lstsize(stack);
	steps_top = 0;
	while (get_number(stack, steps_top) != min)
		steps_top++;
	steps_bottom = 0;
	while (get_number(stack, len - steps_bottom - 1) != max)
		steps_bottom++;
	if (steps_top + 1 <= steps_bottom)
		steps.ra = steps_top;
	else
		steps.rra = steps_bottom;
	return (steps);
}

static void	align_stack(t_list **a, t_list **b, const int *sorted)
{
	int		len;
	int		min;
	int		max;
	t_steps	steps;

	len = ft_lstsize(*a);
	min = sorted[0];
	max = sorted[len - 1];
	steps = get_steps_start(*a, min, max);
	apply_steps(a, b, steps);
}

static void	return_to_a(t_list **a, t_list **b)
{
	t_steps	steps;

	while (*b)
	{
		steps = get_steps(*a, *b);
		apply_steps(a, b, steps);
		push(a, b);
		ft_putendl_fd("pa", 1);
	}
}

void	sort_more(t_list **a, t_list **b, const int *sorted)
{
	int	len;
	int	median;

	len = ft_lstsize(*a);
	median = sorted[len / 2];
	while (len > 3 && !is_list_sorted(*a, len, 0))
	{
		push(b, a);
		ft_putendl_fd("pb", 1);
		if (get_number(*b, 0) < median)
		{
			rotate(b, 0);
			ft_putendl_fd("rb", 1);
		}
		len--;
	}
	sort_three(a);
	return_to_a(a, b);
	align_stack(a, b, sorted);
}
