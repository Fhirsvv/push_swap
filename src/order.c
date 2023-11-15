/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiaz-gu <fdiaz-gu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 17:38:51 by fdiaz-gu          #+#    #+#             */
/*   Updated: 2023/11/15 11:23:54 by fdiaz-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void order_three(t_stack **stack_a)
{
	if ((*stack_a)->value < (*stack_a)->next->value)
	{
		if ((*stack_a)->value > (*stack_a)->next->next->value)
			ft_rra(stack_a);
		else
		{
			ft_rra(stack_a);
			ft_sa(stack_a);
		}
	}
	else
	{
		if ((*stack_a)->next->value > (*stack_a)->next->next->value)
		{
			ft_sa(stack_a);
			ft_rra(stack_a);
		}
		else
		{
			if ((*stack_a)->value > (*stack_a)->next->next->value)
				ft_ra(stack_a);
			else
				ft_sa(stack_a);
		}
	}
}

void	order_five(t_stack **stack_a, t_stack **stack_b)
{
	int min;
	int pos;
	int i;

	i = 2;	
	while (i > 0)
	{
		min = find_min(stack_a);		
		pos = find_min_pos(stack_a, min);
		if (pos <= 3)
		{
			while (pos-- > 1)
				ft_ra(stack_a);				
		}
		else
			while (pos++ <= 5)
				ft_rra(stack_a);
		ft_pb(stack_a, stack_b);
		i--;		
	}
	while (stack_b)
    {
        ft_printf("stack_b: ");
        ft_printf("%i\n", (*stack_b)->value);
        stack_b = &(*stack_b)->next;
    }
	if (!is_sorted(stack_a))
		order_three(stack_a);
	// while (stack_a)
    // {
    //     ft_printf("stack_a: ");
    //     ft_printf("%i\n", (*stack_a)->value);
    //     stack_a = &(*stack_a)->next;
    // }
	ft_pa(stack_a, stack_b);
	ft_pa(stack_a, stack_b);
}

// printf("Macarrones con queso|n"); i = 9;
