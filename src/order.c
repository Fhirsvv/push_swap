/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecortes- <ecortes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 16:55:56 by ecortes-          #+#    #+#             */
/*   Updated: 2024/06/13 17:52:28 by ecortes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "../include/push_swap.h"

void	order_three(t_stack **stack_a)
{
	if ((*stack_a)->value < (*stack_a)->next->value)
	{
		if ((*stack_a)->value > (*stack_a)->next->next->value)
			ft_rra(stack_a);
		else
		{
			ft_rra(stack_a);
			ft_sa(stack_a);
		}
	}
	else
	{
		if ((*stack_a)->next->value > (*stack_a)->next->next->value)
		{
			ft_sa(stack_a);
			ft_rra(stack_a);
		}
		else
		{
			if ((*stack_a)->value > (*stack_a)->next->next->value)
				ft_ra(stack_a);
			else
				ft_sa(stack_a);
		}
	}
}

void	order_four(t_stack **stack_a, t_stack **stack_b)
{
	int	min;
	int	pos;	

	min = find_min(stack_a);
	pos = find_pos_value(stack_a, min);
	if (pos <= 2)
	{
		while (pos-- > 1)
			ft_ra(stack_a);
	}
	else
		while (pos++ <= 4)
			ft_rra(stack_a);
	ft_pb(stack_a, stack_b);
	if (!is_sorted(stack_a))
		order_three(stack_a);
	ft_pa(stack_a, stack_b);
	//ft_pa(stack_a, stack_b);
}

void	order_five(t_stack **stack_a, t_stack **stack_b)
{
	int	min;
	int	pos;

	min = find_min(stack_a);
	pos = find_pos_value(stack_a, min);
	if (pos <= 3)
	{
		while (pos-- > 1)
			ft_ra(stack_a);
	}
	else
		while (pos++ <= 5)
			ft_rra(stack_a);
	ft_pb(stack_a, stack_b);
	order_four(stack_a, stack_b);
}
