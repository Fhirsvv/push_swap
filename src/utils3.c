/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiaz-gu <fdiaz-gu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 17:58:09 by fdiaz-gu          #+#    #+#             */
/*   Updated: 2023/11/14 18:44:48 by fdiaz-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int find_min(t_stack **stack)
{
	int min;
	t_stack *aux;
	// ft_printf("%s\n", "entra");
	min = (*stack)->value;
	// ft_printf("MIN:%i\n", min);
	while ((*stack)->next)
	{
		aux = (*stack)->next;		
		while (aux != NULL)
		{
			if ((aux)->value < min)
				min = (aux)->value;
			aux = aux->next;
		}
		stack = &(*stack)->next;
	}	
	return (min);
}

int find_min_pos(t_stack **stack, int min)
{	    
    int count = 1;
    t_stack *current = *stack;

    while (current != NULL)
    {
        if (current->value == min)
            break;

        count++;
        current = current->next;
    }
    
    return count;
}