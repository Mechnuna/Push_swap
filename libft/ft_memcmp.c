/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a79856 <a79856@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 22:10:34 by a79856            #+#    #+#             */
/*   Updated: 2021/10/18 00:07:58 by a79856           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *arr1, const void *arr2, size_t n)
{
	unsigned char	*array1;
	unsigned char	*array2;

	array1 = (unsigned char *)arr1;
	array2 = (unsigned char *)arr2;
	if (n == 0)
		return (0);
	while (0 < n - 1 && (*array1 == *array2))
	{
		++array1;
		++array2;
		--n;
	}
	return (*array1 - *array2);
}
