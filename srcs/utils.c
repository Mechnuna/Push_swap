/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a79856 <a79856@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 00:46:16 by a79856            #+#    #+#             */
/*   Updated: 2021/10/18 00:46:17 by a79856           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_number(t_list **stack, int number)
{
	int		*number_pointer;

	number_pointer = (int *)malloc(sizeof(int));
	*number_pointer = number;
	ft_lstadd_front(stack, ft_lstnew(number_pointer));
}

int	get_number(t_list *stack, int n)
{
	return (*(int *)(ft_lst_at(stack, n)->content));
}

int	find_left(t_list *list, int n)
{
	t_list	*node;
	int		max;

	max = n;
	node = list;
	while (node)
	{
		if (*(int *)(node->content) < n)
		{
			max = *(int *)(node->content);
			break ;
		}
		node = node->next;
	}
	while (node)
	{
		if (*(int *)(node->content) > max
			&& *(int *)(node->content) < n)
			max = *(int *)(node->content);
		node = node->next;
	}
	return (max);
}

int	find_right(t_list *list, int n)
{
	t_list	*node;
	int		min;

	min = n;
	node = list;
	while (node)
	{
		if (*(int *)(node->content) > n)
		{
			min = *(int *)(node->content);
			break ;
		}
		node = node->next;
	}
	while (node)
	{
		if (*(int *)(node->content) < min
			&& *(int *)(node->content) > n)
			min = *(int *)(node->content);
		node = node->next;
	}
	return (min);
}

int	*stack_to_array(t_list *list, int len)
{
	int		*array;
	t_list	*node;
	int		i;

	array = (int *)malloc(len * sizeof(int));
	node = list;
	i = 0;
	while (i < len)
	{
		array[i] = *(int *)(node->content);
		node = node->next;
		i++;
	}
	return (array);
}
