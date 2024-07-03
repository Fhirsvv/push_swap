/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecortes- <ecortes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 16:57:05 by ecortes-          #+#    #+#             */
/*   Updated: 2024/07/03 15:08:19 by ecortes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	find_min(t_stack **stack)
{
	int	min;

	min = (*stack)->value;
	while ((*stack))
	{
		if (min > (*stack)->value)
			min = (*stack)->value;
		stack = &(*stack)->next;
	}
	return (min);
}

int	find_max(t_stack **stack)
{
	int	max;

	max = (*stack)->value;
	while (*stack)
	{
		if (max < (*stack)->value)
			max = (*stack)->value;
		stack = &(*stack)->next;
	}
	return (max);
}

int	ft_lstsize_ps(t_stack **stack)
{
	int	i;

	i = 0;
	while (*stack)
	{
		stack = &(*stack)->next;
		i++;
	}
	return (i);
}

int	find_pos_index(t_stack **stack, int nb)
{
	int	pos;

	pos = 1;
	while (*stack)
	{
		if ((*stack)->index == nb)
			break ;
		pos++;
		stack = &(*stack)->next;
	}
	return (pos);
}

int	find_pos_value(t_stack **stack, int nb)
{
	int	pos;

	pos = 1;
	while (*stack)
	{
		if ((*stack)->value == nb)
			break ;
		pos++;
		stack = &(*stack)->next;
	}
	return (pos);
}
