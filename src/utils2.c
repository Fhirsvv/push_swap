/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecortes- <ecortes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 16:56:59 by ecortes-          #+#    #+#             */
/*   Updated: 2023/11/21 16:57:00 by ecortes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "../include/push_swap.h"

void	ft_error(void)
{	
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

void	free_list(t_stack *stack)
{
	t_stack	*tmp;

	while (stack != NULL)
	{
		tmp = stack;
		stack = stack->next;
		free(tmp);
	}
}

void	assign_index(t_stack **stack, int index)
{
	t_stack	*first;
	int		min;
	int		stack_size;

	first = (*stack);
	stack_size = ft_lstsize_ps(stack);
	min = find_min_without_stack(stack);
	while (*stack)
	{
		if (((*stack)->index == 0) && ((*stack)->value == min))
		{
			(*stack)->index = index;
			break ;
		}
		stack = &(*stack)->next;
	}
	if (index <= stack_size)
		assign_index(&first, (index + 1));
}
