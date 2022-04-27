/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a79856 <a79856@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 00:45:22 by a79856            #+#    #+#             */
/*   Updated: 2021/10/18 06:05:52 by a79856           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_flag(char c, t_flags *flags)
{
	if (c == 'v')
		flags->debug = 1;
	else if (c == 'c')
		flags->color = 1;
	else
		return (1);
	return (0);
}

static void	inicialize(t_flags	*flags)
{
	flags->debug = 0;
	flags->color = 0;
}

static t_flags	*get_flags(int argc, char **argv, int *i)
{
	int		j;
	t_flags	*flags;

	flags = malloc(sizeof(t_flags));
	inicialize(flags);
	while (*i < argc && argv[*i][0] == '-' && argv[*i][1])
	{
		j = 1;
		while (argv[*i][j])
		{
			if (ft_isdigit_minus_i(argv[*i][j], i))
				return (flags);
			if (check_flag(argv[*i][j], flags))
			{
				free(flags);
				return (NULL);
			}
			j++;
		}
		(*i)++;
	}
	(*i)--;
	if (!flags->debug && flags->color)
		return (NULL);
	return (flags);
}

static int	process_commands(t_list **a, t_list **b, t_flags *flags)
{
	char	*command;

	command = NULL;
	while (get_next_line(0, &command) > 0)
	{
		if (!process_command(a, b, command))
			return (error(a, b, command));
		free(command);
		if (flags->debug && flags->color)
			print_stacks(*a, *b, command);
		else if (flags->debug)
			print_stacks(*a, *b, NULL);
	}
	if (is_list_sorted(*a, ft_lstsize(*a), 0) && *b == NULL)
		ft_putendl_fd("OK", 1);
	else
		ft_putendl_fd("KO", 1);
	free(command);
	return (0);
}

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;
	int		i;
	t_flags	*flags;

	if (argc < 2)
		return (0);
	i = 1;
	flags = get_flags(argc, argv, &i);
	if (!flags)
	{
		ft_putendl_fd("\x1b[32mUsage: ./checker [-vc] numbers\x1b[0m", 1);
		ft_putendl_fd("\x1b[32m-v -- visual \n-c -- color\x1b[0m", 1);
		return (1);
	}
	b = NULL;
	a = parse_numbers(argc, argv, i);
	if (!a)
		return (error(&a, &b, NULL));
	process_commands(&a, &b, flags);
	ft_lstclear(&a, free);
	ft_lstclear(&b, free);
	free(flags);
	return (0);
}
