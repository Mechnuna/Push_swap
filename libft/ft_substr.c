/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a79856 <a79856@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 22:11:43 by a79856            #+#    #+#             */
/*   Updated: 2021/10/15 22:11:44 by a79856           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	length;
	char	*s2;

	i = 0;
	length = ft_strlen(s);
	if (length <= start)
	{
		s2 = malloc(sizeof(char));
		s2[0] = '\0';
		return (s2);
	}
	if (len > length - start)
		len = length - start;
	s2 = malloc((len + 1) * sizeof(char));
	if (!(s2))
		return (NULL);
	while (i < len && i + start < length)
	{
		s2[i] = s[start + i];
		++i;
	}
	s2[i] = '\0';
	return (s2);
}
