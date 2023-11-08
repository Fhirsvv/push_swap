/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiaz-gu <fdiaz-gu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 11:00:05 by fdiaz-gu          #+#    #+#             */
/*   Updated: 2023/11/03 12:51:49 by fdiaz-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int reverse_rotate(t_stack **stack)
{
    t_stack *last;
    t_stack *aux;
    t_stack *new_last;

    last = ft_lstlast(*stack);
    new_last = ft_get_penultimate(*stack);
    aux = *stack;
    *stack = last;
    (*stack)->next = aux;
    new_last->next = NULL;
    return (1);
}

void    ft_rra(t_stack **stack_a)
{
    reverse_rotate(stack_a);
    ft_printf("%s", "rra");
}

void    ft_rrb(t_stack **stack_b)
{
    reverse_rotate(stack_b);
    ft_printf("%s", "rrb");
}

void    ft_rrr(t_stack **stack_a, t_stack **stack_b)
{
    ft_rra(stack_a);
    ft_rrb(stack_b);
    ft_printf("%s", "rrr");
}