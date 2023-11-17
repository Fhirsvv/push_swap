/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiaz-gu <fdiaz-gu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 14:16:52 by fdiaz-gu          #+#    #+#             */
/*   Updated: 2023/11/17 10:30:57 by fdiaz-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int find_min_without_stack(t_stack **stack)
{
	int	min;
	
	while ((*stack))
	{		
		if (((*stack)->index == 0) && (min > (*stack)->value))
			min = (*stack)->value;
		stack = &(*stack)->next;
	}
//	ft_printf("find_min:%i\n", min);
	return (min);
}