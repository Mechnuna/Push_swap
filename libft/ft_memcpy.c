/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a79856 <a79856@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 22:10:37 by a79856            #+#    #+#             */
/*   Updated: 2021/10/18 00:01:01 by a79856           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *destination, const void *source, size_t n)
{
	size_t	a;

	a = 0;
	if (destination == NULL && source == NULL)
		return (NULL);
	while (a < n)
	{
		((unsigned char *) destination)[a] = ((unsigned char *) source)[a];
		++a;
	}
	return (destination);
}
