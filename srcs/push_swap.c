/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a79856 <a79856@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 00:44:02 by a79856            #+#    #+#             */
/*   Updated: 2021/10/18 00:44:10 by a79856           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_all_list(t_list *a, t_list	*b)
{
	ft_lstclear(&a, &free);
	ft_lstclear(&b, &free);
}

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;
	int		len;
	int		*sorted;

	if (argc < 2)
		return (0);
	b = NULL;
	a = parse_numbers(argc, argv, 0);
	if (!a)
		return (error(&a, &b, NULL));
	len = ft_lstsize(a);
	if (len == 2)
		sort_two(&a);
	else if (len == 3)
		sort_three(&a);
	else
	{
		sorted = stack_to_array(a, ft_lstsize(a));
		ft_bubble_sort(sorted, len);
		sort_more(&a, &b, sorted);
		free(sorted);
	}
	free_all_list(a, b);
	return (0);
}
