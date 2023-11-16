/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiaz-gu <fdiaz-gu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 14:16:52 by fdiaz-gu          #+#    #+#             */
/*   Updated: 2023/11/16 18:25:26 by fdiaz-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int find_min_without_stack(t_stack **stack)
{
	int	min;

	min = (*stack)->value;
	while ((*stack))
	{
		//TODO: VER XQ SIEMPRE PILLA EL MÍNIMO VALOR
		if (min > (*stack)->value && ((*stack)->index == 0))
			min = (*stack)->value;
		stack = &(*stack)->next;
	}
//	ft_printf("find_min:%i\n", min);
	return (min);
}