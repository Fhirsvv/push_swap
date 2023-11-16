/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiaz-gu <fdiaz-gu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 17:58:09 by fdiaz-gu          #+#    #+#             */
/*   Updated: 2023/11/16 14:17:19 by fdiaz-gu         ###   ########.fr       */
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

int find_max(t_stack **stack)
{
	int	max;

	max = (*stack)->value;
	while ((*stack))
	{
		if (max < (*stack)->value)
			max = (*stack)->value;
		stack = &(*stack)->next;
	}
	// ft_printf("find_max:%i\n", max);
	return (max);
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

int find_max_pos(t_stack **stack, int max)
{	    
    int count;    
	
	count = 1;	
    while ((stack))
    {
        if ((*stack)->value == max)
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

