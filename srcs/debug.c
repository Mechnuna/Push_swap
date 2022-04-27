/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a79856 <a79856@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 00:44:37 by a79856            #+#    #+#             */
/*   Updated: 2021/10/18 04:03:20 by a79856           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_number(const int *n, int color)
{
	if (color)
		ft_putstr_fd("\x1b[32m", 1);
	ft_putnbr_fd(*n, 1);
	ft_putchar_fd(' ', 1);
	if (color)
		ft_putstr_fd("\x1b[0m", 1);
}

static void	print_stack(t_list *stack, char *command)
{
	t_list	*lst;
	int		i;
	int		f;
	int		ft;
	int		l;

	i = 0;
	lst = stack;
	while (lst)
	{
		f = (command && (!ft_strcmp(command, "pa") || !ft_strcmp(command, "pb")
					|| !ft_strcmp(command, "rra") || !ft_strcmp(command, "rrb")
					|| !ft_strcmp(command, "rrr")));
		ft = (command && (!ft_strcmp(command, "sa") || !ft_strcmp(command, "sb")
					|| !ft_strcmp(command, "ss")));
		l = (command && (!ft_strcmp(command, "ra")
					|| !ft_strcmp(command, "rb")
					|| !ft_strcmp(command, "rr")));
		if ((f && i == 0) || (ft && i >= 0 && i <= 1) || (l && !lst->next))
			print_number(lst->content, 1);
		else
			print_number(lst->content, 0);
		lst = lst->next;
		i++;
	}
}

void	print_stacks(t_list *a, t_list *b, char *command)
{
	ft_putstr_fd("a: ", 1);
	if (command
		&& (!ft_strcmp(command, "pa") || !ft_strcmp(command, "sa")
			|| !ft_strcmp(command, "ss") || !ft_strcmp(command, "ra")
			|| !ft_strcmp(command, "rra") || !ft_strcmp(command, "rr")
			|| !ft_strcmp(command, "rrr")))
		print_stack(a, command);
	else
		print_stack(a, NULL);
	ft_putchar_fd('\n', 1);
	ft_putstr_fd("b: ", 1);
	if (command
		&& (!ft_strcmp(command, "pb") || !ft_strcmp(command, "sb")
			|| !ft_strcmp(command, "ss") || !ft_strcmp(command, "rb")
			|| !ft_strcmp(command, "rrb") || !ft_strcmp(command, "rr")
			|| !ft_strcmp(command, "rrr")))
		print_stack(b, command);
	else
		print_stack(b, NULL);
	ft_putchar_fd('\n', 1);
}
