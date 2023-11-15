/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiaz-gu <fdiaz-gu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 17:58:09 by fdiaz-gu          #+#    #+#             */
/*   Updated: 2023/11/15 16:06:09 by fdiaz-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int find_min(t_stack **stack)
{
	int	min;

	min = (*stack)->value;
	while ((*stack))
	{
		if (min > (*stack)->value)
			min = (*stack)->value;
		stack = &(*stack)->next;
	}
	// ft_printf("find_min:%i\n", min);
	return (min);
}

int find_min_pos(t_stack **stack, int min)
{	    
    int count;    
	
	count = 1;	
    while ((stack))
    {
        if ((*stack)->value == min)
            break;

        count++;
        stack = &(*stack)->next;
		// printf("Esta es la línea 42\n");
    }
	// ft_printf("find_min_pos:%i\n", count);
    return (count);
}

int	ft_lstsize_ps(t_stack **stack)
{
	int	i;

	i = 0;
	while ((*stack))
	{
		stack = &(*stack) -> next;
		i++;
	}
	return (i);
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
