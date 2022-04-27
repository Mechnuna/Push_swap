/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a79856 <a79856@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 22:11:26 by a79856            #+#    #+#             */
/*   Updated: 2021/10/15 22:11:27 by a79856           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	a;
	char	*new_str;
	size_t	len;

	a = 0;
	if (!(s) || !(f))
		return (NULL);
	len = ft_strlen(s);
	new_str = ft_calloc((len + 1), sizeof(char));
	if (!(new_str))
		return (NULL);
	while (a < len)
	{
		new_str[a] = (*f)(a, s[a]);
		++a;
	}
	new_str[a] = '\0';
	return (new_str);
}
