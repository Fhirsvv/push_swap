/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiaz-gu <fdiaz-gu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 11:00:12 by fdiaz-gu          #+#    #+#             */
/*   Updated: 2023/11/02 11:00:56 by fdiaz-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int    ft_swap(t_stack **stack)
{    
    t_stack *aux_stack;

    if (ft_lstsize(*stack) < 2)
        return (0);
	aux_stack = *stack;
	*stack = (*stack)->next;
	aux_stack->next = (*stack)->next;
	(*stack)->next = aux_stack;
    return(1);
}

void	do_sa(t_stack **stack_a)
{
	ft_swap(stack_a);
	ft_printf("%s","sa\n");
}

void	do_sb(t_stack **stack_b)
{
	ft_swap(stack_b);
	ft_printf("%s","sb\n");
}