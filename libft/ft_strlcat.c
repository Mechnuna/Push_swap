/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a79856 <a79856@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 22:11:17 by a79856            #+#    #+#             */
/*   Updated: 2021/10/15 22:11:17 by a79856           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	len;
	size_t	size2;
	char	*d;
	char	*s;

	d = dst;
	s = (char *)src;
	size2 = size;
	while (size2-- != 0 && *d != '\0')
		++d;
	len = d - dst;
	size2 = size - len;
	if (size2 == 0)
		return (len + ft_strlen(s));
	while (*s != '\0')
	{
		if (size2 > 1)
		{
			*d++ = *s;
			size2--;
		}
		s++;
	}
	*d = '\0';
	return (len + (s - src));
}
