/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a79856 <a79856@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 22:08:29 by a79856            #+#    #+#             */
/*   Updated: 2021/10/15 22:08:30 by a79856           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	unsigned long int	i;
	int					num;
	int					minus;

	i = 0;
	minus = 1;
	num = 0;
	while (str[i] == '\n' || str[i] == '\t'
		|| str[i] == ' ' || str[i] == '\f' || str[i] == '\r' || str[i] == '\v')
		++i;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			minus *= -1;
		++i;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + (str[i] - '0');
		++i;
	}
	return (num * minus);
}
