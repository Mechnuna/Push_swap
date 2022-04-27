/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_to_array.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a79856 <a79856@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 22:19:33 by a79856            #+#    #+#             */
/*   Updated: 2021/10/15 22:19:35 by a79856           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	**ft_lst_to_array(t_list *lst)
{
	t_list	*node;
	void	**array;
	void	**iter;

	if (lst == NULL)
		return (NULL);
	array = (void **)malloc((ft_lstsize(lst) + 1) * sizeof(void *));
	if (array == NULL)
		return (NULL);
	iter = array;
	node = lst;
	while (node)
	{
		*iter = node->content;
		node = node->next;
		iter++;
	}
	*iter = NULL;
	return (array);
}
