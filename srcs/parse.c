/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a79856 <a79856@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 00:44:20 by a79856            #+#    #+#             */
/*   Updated: 2021/10/18 00:44:24 by a79856           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_strdigits(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

static int	is_int(char *str, int number)
{
	int	pos;
	int	neg;

	pos = ((ft_isdigit(str[0]) || str[0] == '+') && number < 0);
	neg = (str[0] == '-' && number > 0);
	return (!pos && !neg);
}

static int	check_duplicates(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = i + 1;
		while (j < argc)
		{
			if (!ft_strcmp(argv[i], argv[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

t_list	*parse_numbers(int argc, char **argv, int stop)
{
	t_list	*numbers;
	int		number;
	int		i;

	if (check_duplicates(argc, argv))
		return (NULL);
	numbers = NULL;
	i = argc - 1;
	while (i > stop)
	{
		if (!is_strdigits(argv[i]))
		{
			ft_lstclear(&numbers, &free);
			return (NULL);
		}
		number = ft_atoi(argv[i]);
		if (!is_int(argv[i], number))
		{
			ft_lstclear(&numbers, &free);
			return (NULL);
		}
		add_number(&numbers, number);
		i--;
	}
	return (numbers);
}
