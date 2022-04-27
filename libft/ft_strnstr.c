/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a79856 <a79856@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 22:11:33 by a79856            #+#    #+#             */
/*   Updated: 2021/10/15 22:11:33 by a79856           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//исправлено
char	*ft_strnstr(const char	*big, const char *little, size_t len)
{
	size_t	l_index;
	size_t	b_index;

	l_index = 0;
	b_index = 0;
	if (*little == '\0')
		return ((char *) big);
	while (b_index < len && big[b_index] != '\0')
	{
		if (little[l_index] == big[b_index])
			++l_index;
		else
		{
			b_index -= l_index;
			l_index = 0;
		}
		if (little[l_index] == '\0')
			return ((char *)(big + (b_index - l_index + 1)));
		++b_index;
	}
	return (NULL);
}
