/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a79856 <a79856@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 22:10:25 by a79856            #+#    #+#             */
/*   Updated: 2021/10/18 00:00:05 by a79856           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *destination, const void *source, int c, size_t n)
{
	size_t			a;
	unsigned char	znak;
	unsigned char	*dst;
	unsigned char	*src;

	a = 0;
	znak = c;
	dst = (unsigned char *)destination;
	src = (unsigned char *)source;
	while (a < n)
	{
		dst[a] = src[a];
		if (dst[a] == znak)
			return (destination + a + 1);
		++a;
	}
	return (NULL);
}
