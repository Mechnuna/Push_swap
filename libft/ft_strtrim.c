/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a79856 <a79856@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 22:11:40 by a79856            #+#    #+#             */
/*   Updated: 2021/10/15 22:11:40 by a79856           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	yes_no(char c, const char *set)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

static size_t	start_end(const char *str, const char *set, size_t length,
						char step)
{
	size_t	step2;
	size_t	index;

	step2 = 0;
	while (step2 < length)
	{
		index = step2;
		if (step < 0)
			index = length - 1 - step2;
		if (!(yes_no(str[index], set)))
			return (index);
		++step2;
	}
	return (step2);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	length;
	size_t	start;
	size_t	end;
	char	*str;

	if (!(s1) || !(set))
		return (NULL);
	length = ft_strlen(s1);
	start = start_end(s1, set, length, 1);
	end = start_end(s1, set, length, -1);
	length = 0;
	if (start < end)
		length = end - start + 1;
	if (length <= 0)
		return (ft_strdup(""));
	str = malloc((length + 1) * sizeof(char));
	if (!(str))
		return (NULL);
	ft_memcpy(str, s1 + start, length);
	str[length] = '\0';
	return (str);
}
