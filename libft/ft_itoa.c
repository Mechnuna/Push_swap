/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a79856 <a79856@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 22:09:11 by a79856            #+#    #+#             */
/*   Updated: 2021/10/15 22:09:12 by a79856           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	size(int n)
{
	size_t	x;

	if (n < 0)
	{
		x = 1;
		x *= 1;
	}
	else
	{
		x = 0;
	}
	while (1)
	{
		n /= 10;
		++x;
		if (n == 0)
			break ;
	}
	return (x);
}

char	*ft_itoa(int n)
{
	char	*str;
	long	num;
	size_t	x;

	num = n;
	x = size(n);
	str = malloc((x + 1) * sizeof(char));
	if (!(str))
		return (NULL);
	if (num < 0)
	{
		str[0] = '-';
		num *= -1;
	}
	str[x] = '\0';
	while (1)
	{
		str[x - 1] = (num % 10) + '0';
		num /= 10;
		--x;
		if (num == 0)
			break ;
	}
	return (str);
}
