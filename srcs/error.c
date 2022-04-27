/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a79856 <a79856@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 00:45:38 by a79856            #+#    #+#             */
/*   Updated: 2021/10/18 00:45:39 by a79856           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	error(t_list **a, t_list **b, char *command)
{
	if (*a)
		ft_lstclear(a, &free);
	if (*b)
		ft_lstclear(b, &free);
	if (command)
		free(command);
	ft_putendl_fd("Error", 2);
	return (1);
}
