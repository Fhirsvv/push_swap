/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiaz-gu <fdiaz-gu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 15:40:56 by fdiaz-gu          #+#    #+#             */
/*   Updated: 2023/11/16 18:18:28 by fdiaz-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_error(void)
{	
	ft_printf("%s\n", "Error");
	exit(EXIT_FAILURE);
}

void freeList(t_stack *stack)
{
   t_stack *tmp;

   while (stack != NULL)
    {
       tmp = stack;
       stack = stack->next;
       free(tmp);
    }
}

void	assign_index(t_stack **stack, int index, int stack_size)
{
	t_stack *first;
	int min;

	ft_printf("%sindice: %i\n",COLOR_RESET, index);
	first = (*stack);
	min = find_min_without_stack(stack);
	ft_printf("%smin: %i\n", COLOR_GREEN,first->value);
	while((*stack))
	{
		// ft_printf("inside while\n");
		if (((*stack)->index == 0) && ((*stack)->value == min))
		{
			(*stack)->index = index;
			ft_printf("%sNB:%i -> INDEX: %i\n", COLOR_BLUE,(*stack)->value, (*stack)->index);
			break ;
		}
		stack = &(*stack)->next;
	}
	ft_printf("stack_size: %i\n", stack_size);
	ft_printf("%sindex before recursivity: %i\n", COLOR_RED,index);
	if (index  <= stack_size)
		assign_index(&first, (index + 1), stack_size);
}