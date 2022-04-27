/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a79856 <a79856@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 00:44:47 by a79856            #+#    #+#             */
/*   Updated: 2021/10/18 06:03:28 by a79856           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

typedef struct s_steps
{
	int	ra;
	int	rra;
	int	rb;
	int	rrb;
	int	rr;
	int	rrr;
}	t_steps;

typedef struct s_flags
{
	int	debug;
	int	color;
}	t_flags;

int		process_command(t_list **a, t_list **b, char *command);
int		error(t_list **a, t_list **b, char *command);
void	sort_two(t_list **stack);
void	sort_three(t_list **stack);
void	sort_more(t_list **a, t_list **b, const int *sorted);
void	apply_steps(t_list **a, t_list **b, t_steps steps);
t_list	*parse_numbers(int argc, char **argv, int stop);
int		is_list_sorted(t_list *lst, int len, int reverse);
int		swap(t_list **stack);
int		push(t_list **stack1, t_list **stack2);
int		rotate(t_list **stack, int reverse);
t_steps	get_steps(t_list *a, t_list *b);
void	print_stacks(t_list *a, t_list *b, char *command);
void	add_number(t_list **stack, int number);
int		get_number(t_list *stack, int n);
int		find_left(t_list *list, int n);
int		find_right(t_list *list, int n);
int		*stack_to_array(t_list *list, int len);
void	free_all_list(t_list *a, t_list	*b);
int		ft_isdigit_minus_i(int c, int *i);

#endif
