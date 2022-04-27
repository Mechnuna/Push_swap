/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a79856 <a79856@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 22:11:10 by a79856            #+#    #+#             */
/*   Updated: 2021/10/15 22:11:11 by a79856           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	size_t	a;
	char	*str2;

	a = ft_strlen(str);
	str2 = ft_calloc(a + 1, sizeof(char));
	if (!(str2))
		return (NULL);
	ft_memcpy(str2, str, a);
	str2[a] = '\0';
	return (str2);
}
