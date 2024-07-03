/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecortes- <ecortes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 16:56:24 by ecortes-          #+#    #+#             */
/*   Updated: 2024/07/03 15:08:02 by ecortes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	push(t_stack **src, t_stack **dst)
{
	t_stack	*aux;

	if (!*src)
		return ;
	aux = *src;
	*src = aux->next;
	aux->next = NULL;
	ft_lstadd_front_ps(dst, aux);
}

void	ft_pa(t_stack **stack_a, t_stack **stack_b)
{
	push(stack_b, stack_a);
	ft_printf("%s\n", "pa");
}

void	ft_pb(t_stack **stack_a, t_stack **stack_b)
{
	push(stack_a, stack_b);
	ft_printf("%s\n", "pb");
}
