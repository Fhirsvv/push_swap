/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiaz-gu <fdiaz-gu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 14:16:52 by fdiaz-gu          #+#    #+#             */
/*   Updated: 2023/11/21 13:34:21 by fdiaz-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	find_min_without_stack(t_stack **stack)
{
	int	min;

	min = INT_MAX;
	while ((*stack))
	{
		if (((*stack)->index == 0) && (min > (*stack)->value))
			min = (*stack)->value;
		stack = &(*stack)->next;
	}
	return (min);
}

void	loops_for_hundred(t_stack **stack_a, t_stack **stack_b, int size)
{
	int	count;
	int	i;
	int	chunk;

	chunk = size / 5;
	i = 1;
	count = 1;
	while ((*stack_a))
	{
		while (count <= (chunk * i))
		{		
			order_by_chunks(stack_a, stack_b,
				(chunk * i + 1) - chunk, chunk * i);
			count++;
		}
		i++;
	}
	while ((*stack_b))
	{
		max_to_top(stack_b);
		ft_pa(stack_a, stack_b);
	}
}

void	loops_for_five_hundred(t_stack **stack_a, t_stack **stack_b, int size)
{
	int	count;
	int	i;
	int	chunk;

	chunk = size / 11;
	i = 1;
	count = 1;
	while ((*stack_a))
	{
		while (count <= (chunk * i))
		{		
			order_by_chunks(stack_a, stack_b,
				(chunk * i + 1) - chunk, chunk * i);
			count++;
		}
		i++;
	}
	while ((*stack_b))
	{
		max_to_top(stack_b);
		ft_pa(stack_a, stack_b);
	}
}

int	ft_atoi_ps(const char *str)
{
	unsigned long	result;
	int				sign;

	sign = 1;
	result = 0;
	while ((*str == ' ' || ('\t' <= *str && *str <= '\r')))
		str++;
	if (*str == '-')
	{
		sign = -sign;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		if (result > INT_MAX && sign > 0)
			ft_error();
		if (result > INT_MAX && sign < 0)
			ft_error();
		str++;
	}
	return (result * sign);
}
