/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecortes- <ecortes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 16:56:18 by ecortes-          #+#    #+#             */
/*   Updated: 2023/11/21 16:56:19 by ecortes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "../include/push_swap.h"

int	find_first_occurrence(t_stack **stack, int first, int last)
{
	int	i;
	int	pos;

	pos = 1;
	while (*stack)
	{
		i = first;
		while (i <= last)
		{
			if ((*stack)->index == i)
				return ((*stack)->index);
			i++;
		}
		stack = &(*stack)->next;
	}
	return (pos);
}

int	find_last_occurrence(t_stack **stack, int first, int last)
{
	int	i;
	int	pos;

	pos = 1;
	while (*stack)
	{
		i = first;
		while (i <= last)
		{
			if ((*stack)->index == i)
				pos = (*stack)->index;
			i++;
		}
		stack = &(*stack)->next;
	}
	return (pos);
}

void	order_by_chunks(t_stack **stack_a, t_stack **stack_b,
	int first, int last)
{
	int	lst_size;
	int	first_el;
	int	last_el;	

	lst_size = ft_lstsize_ps(stack_a);
	if (*stack_a)
	{
		first_el = find_pos_index(stack_a,
				find_first_occurrence(stack_a, first, last));
		last_el = find_pos_index(stack_a,
				find_last_occurrence(stack_a, first, last));
		if ((first_el - 1) <= (lst_size - last_el))
		{
			while (first_el-- >= 1 && (first_el) > 0)
				ft_ra(stack_a);
		}
		else
		{
			while (last_el++ <= lst_size)
				ft_rra(stack_a);
		}	
		ft_pb(stack_a, stack_b);
	}	
}

void	min_to_top(t_stack **stack)
{	
	int	pos;
	int	size;

	if (! stack || !(*stack))
		return ;
	size = ft_lstsize_ps(stack);
	pos = find_pos_value(stack, find_min(stack));
	if (pos != 1 && pos <= size / 2)
	{
		while (pos > 1)
		{
			ft_rb(stack);
			pos--;
		}
	}
	else if (pos != 1 && pos > size / 2)
	{
		while (pos <= size)
		{
			ft_rrb(stack);
			pos++;
		}
	}
}

void	max_to_top(t_stack **stack)
{
	int	pos;
	int	size;

	if (! stack || !(*stack))
		return ;
	size = ft_lstsize_ps(stack);
	pos = find_pos_value(stack, find_max(stack));
	if (pos != 1 && pos < size / 2)
	{
		while (pos-- > 1)
			ft_rb(stack);
	}
	else if (pos != 1 && pos >= size / 2)
	{
		while (pos++ <= size)
			ft_rrb(stack);
	}
}
