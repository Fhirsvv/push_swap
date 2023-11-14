/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiaz-gu <fdiaz-gu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 17:58:09 by fdiaz-gu          #+#    #+#             */
/*   Updated: 2023/11/14 19:33:22 by fdiaz-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int find_min(t_stack **stack)
{
	int	min;

	min = (*stack)->value;
	while (stack)
	{
		if (min > (*stack)->value)
			min = (*stack)->value;
		stack = &(*stack)->next;
	}
	return (min);
}

int find_min_pos(t_stack **stack, int min)
{	    
    int count;    
	
	count = 1;	
    while (stack)
    {
        if ((*stack)->value == min)
            break;

        count++;
        stack = &(*stack)->next;
    }
    ft_printf("MINPOS: %i\n", count);
    return (count);
}