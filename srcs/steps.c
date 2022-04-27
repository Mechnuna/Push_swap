/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   steps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a79856 <a79856@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 00:46:09 by a79856            #+#    #+#             */
/*   Updated: 2021/10/18 00:46:11 by a79856           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_steps	init_steps(int rb, int len)
{
	t_steps	steps;

	steps.ra = 0;
	steps.rra = 0;
	steps.rb = rb;
	steps.rrb = 0;
	steps.rr = 0;
	steps.rrr = 0;
	if (len - steps.rb < steps.rb)
	{
		steps.rrb = len - steps.rb;
		steps.rb = 0;
	}
	return (steps);
}

static t_steps	steps_sum(t_steps steps)
{
	steps.rr = steps.ra;
	if (steps.rb < steps.rr)
		steps.rr = steps.rb;
	steps.ra -= steps.rr;
	steps.rb -= steps.rr;
	steps.rrr = steps.rra;
	if (steps.rrb < steps.rrr)
		steps.rrr = steps.rrb;
	steps.rra -= steps.rrr;
	steps.rrb -= steps.rrr;
	return (steps);
}

static t_steps	get_steps_place(t_steps steps, t_list *a, int n)
{
	int	left;
	int	right;
	int	len;
	int	place;

	len = ft_lstsize(a);
	left = find_left(a, n);
	right = find_right(a, n);
	place = 0;
	while ((place >= len || get_number(a, place) != right)
		&& (place == 0 || get_number(a, place - 1) != left))
		place++;
	if (len - place < place)
		steps.rra = len - place;
	else
		steps.ra = place;
	return (steps_sum(steps));
}

static int	steps_count(t_steps steps)
{
	return (steps.ra + steps.rra + steps.rb + steps.rrb + steps.rr + steps.rrr);
}

t_steps	get_steps(t_list *a, t_list *b)
{
	t_steps	steps;
	t_steps	steps_tmp;
	int		i;
	int		len;

	len = ft_lstsize(b);
	steps_tmp = init_steps(0, len);
	steps_tmp = get_steps_place(steps_tmp, a, get_number(b, 0));
	steps = steps_tmp;
	i = 1;
	while (i < len)
	{
		steps_tmp = init_steps(i, len);
		steps_tmp = get_steps_place(steps_tmp, a, get_number(b, i));
		if (steps_count(steps_tmp) < steps_count(steps))
			steps = steps_tmp;
		i++;
	}
	return (steps);
}
