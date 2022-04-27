/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a79856 <a79856@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 22:11:14 by a79856            #+#    #+#             */
/*   Updated: 2021/10/15 22:11:14 by a79856           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_size;
	size_t	s2_size;
	char	*str;

	if (!(s1) || !(s2))
	{
		return (NULL);
	}
	s1_size = ft_strlen(s1);
	s2_size = ft_strlen(s2);
	str = malloc((s1_size + s2_size) * sizeof(char) + 1);
	if (!(str))
		return (NULL);
	ft_memcpy(str, s1, s1_size);
	ft_memcpy(str + s1_size, s2, s2_size);
	str[s2_size + s1_size] = '\0';
	return (str);
}
