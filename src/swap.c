/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecortes- <ecortes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 16:56:48 by ecortes-          #+#    #+#             */
/*   Updated: 2023/11/21 16:56:49 by ecortes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "../include/push_swap.h"

static void	ft_swap(t_stack **stack)
{
	t_stack	*aux_stack;

	if (ft_lstsize_ps(stack) < 2)
		return ;
	aux_stack = *stack;
	*stack = (*stack)->next;
	aux_stack->next = (*stack)->next;
	(*stack)->next = aux_stack;
}

void	ft_sa(t_stack **stack_a)
{
	ft_swap(stack_a);
	ft_printf("%s\n", "sa");
}

void	ft_sb(t_stack **stack_b)
{
	ft_swap(stack_b);
	ft_printf("%s\n", "sb");
}

void	ft_ss(t_stack **stack_a, t_stack **stack_b)
{
	ft_swap(stack_a);
	ft_swap(stack_b);
	ft_printf("%s\n", "ss");
}
