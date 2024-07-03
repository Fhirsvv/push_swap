/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecortes- <ecortes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 16:56:35 by ecortes-          #+#    #+#             */
/*   Updated: 2024/07/03 15:08:11 by ecortes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	reverse_rotate(t_stack **stack)
{
	t_stack	*last;
	t_stack	*aux;
	t_stack	*new_last;

	last = ft_lstlast_ps(*stack);
	new_last = ft_get_penultimate(*stack);
	aux = *stack;
	*stack = last;
	(*stack)->next = aux;
	new_last->next = NULL;
}

void	ft_rra(t_stack **stack_a)
{
	reverse_rotate(stack_a);
	ft_printf("%s\n", "rra");
}

void	ft_rrb(t_stack **stack_b)
{
	reverse_rotate(stack_b);
	ft_printf("%s\n", "rrb");
}

void	ft_rrr(t_stack **stack_a, t_stack **stack_b)
{
	ft_rra(stack_a);
	ft_rrb(stack_b);
	ft_printf("%s\n", "rrr");
}
