/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a79856 <a79856@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 22:07:40 by a79856            #+#    #+#             */
/*   Updated: 2021/10/15 22:07:52 by a79856           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned char	*s1_iter;
	unsigned char	*s2_iter;

	s1_iter = (unsigned char *)s1;
	s2_iter = (unsigned char *)s2;
	while (*s1_iter && (*s1_iter == *s2_iter))
	{
		s1_iter++;
		s2_iter++;
	}
	return (*s1_iter - *s2_iter);
}
