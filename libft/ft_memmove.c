/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a79856 <a79856@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 22:10:41 by a79856            #+#    #+#             */
/*   Updated: 2021/10/18 00:09:58 by a79856           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *destination, const void *source, size_t n)
{
	size_t			a;
	char			step;
	unsigned char	*d;
	unsigned char	*s;

	a = 0;
	step = +1;
	s = (unsigned char *)source;
	d = (unsigned char *)destination;
	if (destination == NULL && source == NULL)
		return (NULL);
	if (destination > source)
	{
		step = -1;
		d += n - 1;
		s += n - 1;
	}
	while (a < n)
	{
		*d = *s;
		d += step;
		s += step;
		++a;
	}
	return (destination);
}
