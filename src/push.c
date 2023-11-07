/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiaz-gu <fdiaz-gu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 11:00:15 by fdiaz-gu          #+#    #+#             */
/*   Updated: 2023/11/02 11:00:55 by fdiaz-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int push(t_stack **src, t_stack **dst)
{
    t_stack *aux;

    if (!*src)
        return (0);
    aux = *src;
    *src = aux->next;
    aux->next = NULL;
    ft_lstadd_front(dst, aux);
    return (1);
}

void    ft_pa(t_stack **stack_a, t_stack **stack_b)
{
    push(stack_b, stack_a);
    ft_printf("%s\n", "pa");
}

void    ft_pb(t_stack **stack_a, t_stack **stack_b)
{
    push(stack_a, stack_b);
    ft_printf("%s\n", "pb");
}
