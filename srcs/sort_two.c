/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_two.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a79856 <a79856@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 00:46:02 by a79856            #+#    #+#             */
/*   Updated: 2021/10/18 00:46:03 by a79856           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_list **stack)
{
	if (!(*stack)->next)
		return ;
	if (get_number(*stack, 0) > get_number(*stack, 1))
	{
		swap(stack);
		ft_putendl_fd("sa", 1);
	}
}
