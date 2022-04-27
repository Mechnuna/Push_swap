/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_process.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a79856 <a79856@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 00:45:15 by a79856            #+#    #+#             */
/*   Updated: 2021/10/18 06:03:11 by a79856           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isdigit_minus_i(int c, int *i)
{
	if (c >= '0' && c <= '9')
		(*i)--;
	return (c >= '0' && c <= '9');
}

static int	check_swap(t_list **a, t_list **b, char *command)
{
	if (!ft_strcmp(command, "sb"))
		return (swap(b));
	if (!ft_strcmp(command, "sa"))
		return (swap(a));
	if (!ft_strcmp(command, "ss"))
	{
		swap(a);
		return (swap(b));
	}
	return (0);
}

static int	check_push(t_list **a, t_list **b, char *command)
{
	if (!ft_strcmp(command, "pb"))
		return (push(b, a));
	if (!ft_strcmp(command, "pa"))
		return (push(a, b));
	return (0);
}

static int	check_rotate(t_list **a, t_list **b, char *command)
{
	if (!ft_strcmp(command, "rb"))
		return (rotate(b, 0));
	if (!ft_strcmp(command, "ra"))
		return (rotate(a, 0));
	if (!ft_strcmp(command, "rr"))
	{
		rotate(a, 0);
		return (rotate(b, 0));
	}
	if (!ft_strcmp(command, "rra"))
		return (rotate(a, 1));
	if (!ft_strcmp(command, "rrb"))
		return (rotate(b, 1));
	if (!ft_strcmp(command, "rrr"))
	{
		rotate(a, 1);
		return (rotate(b, 1));
	}
	return (0);
}

int	process_command(t_list **a, t_list **b, char *command)
{
	if (check_swap(a, b, command))
		return (1);
	if (check_push(a, b, command))
		return (1);
	if (check_rotate(a, b, command))
		return (1);
	return (0);
}
