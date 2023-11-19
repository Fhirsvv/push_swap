/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiaz-gu <fdiaz-gu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 13:21:14 by fdiaz-gu          #+#    #+#             */
/*   Updated: 2023/11/19 17:40:30 by fdiaz-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/* 
*:
		Paso 1: Agregar int index a stack
*:
		Paso 2: Agregar índice correspondiente a cada número (min:0, max: nº argc - 1)
*:
		Paso 3: Dividir en 5 chunks (de 20 nºs del 0 al 99 (0-19, 20-39, 40-59, 60-79, 80-99), para 100 nms)
*:
		Paso 4: Buscar (con el ínidice) la primera coincidencia con el chunk 1
*:
		Paso 5: Igual que paso 4 pero con la última coincidencia
*:
		Paso 6: Ver cual es más eficiente de poner en el top del stack A
*:
		Paso 7: Verificar que el número en el top del stack B sea el menor de todos
*:
		Paso 8: Pushear el top de stack A a stack B
TODO:
		Repetir proceso hasta acabar con todo el chunk 1 y posteroirm ente con todos los chunks
TODO:
		Cuando A esté vacío, poner en top de B el mayor y pushear a A
TODO:
		Repetir hasta tener A lleno.
*/

int	find_first_occurrence(t_stack **stack, int first, int last)
{	
	int i;
	int	pos;

	pos = 1;	
	while (*stack)
	{		
		i = first;
		while (i <= last)
		{
			if ((*stack)->index == i)
			{
				// ft_printf("%s, find_last_occurrence: Index: %i\n", COLOR_RED,(*stack)->index);
				return ((*stack)->index);
			}
			i++;
		}
		stack = &(*stack)->next;
	}
	return (pos);
}

int	find_last_occurrence(t_stack **stack, int first, int last)
{	
	int i;
	int	pos;

	pos = 1;	
	while (*stack)
	{		
		i = first;
		while (i <= last)
		{	
			if ((*stack)->index == i)		
				pos = (*stack)->index;
			i++;
		}
		stack = &(*stack)->next;
	}
	// ft_printf("find_last_occurrence: F: %i\n", first);
	// ft_printf("find_last_occurrence: L: %i\n", last);
	return (pos);
}

//TODO: Arreglar recursividad(chunk_size para ir avanzando)
void	order_by_chunks(t_stack **stack_a, t_stack **stack_b, int first, int last)
{
	int	lst_size;
	int first_el;
	int last_el;
	// int	aux_size;
	
	lst_size = ft_lstsize_ps(stack_a);
	// aux_size = lst_size;
	// ft_printf("size :%i\n", lst_size);
	if((*stack_a))
	{
		first_el = find_pos_index(stack_a,
			find_first_occurrence(stack_a, first, last));
		// ft_printf("First :%i\n", first);
		last_el = find_pos_index(stack_a, find_last_occurrence(stack_a, first, last));
		// ft_printf("Last :%i\n", last);
		if ((first_el - 1) <= (lst_size - last_el))
		{
			while (first_el-- >= 1 && (first_el - 1) > 0)
			{
				ft_ra(stack_a);
				// first--;
				// ft_print(stack_a, stack_b);
			}
		}
		else
		{
			while (last_el++ <= lst_size)
			{
				ft_rra(stack_a);
				// last++;
				// ft_print(stack_a, stack_b);
			}
		}
	min_to_top(stack_b);
	ft_pb(stack_a, stack_b);
	// ft_print(stack_a, stack_b);
	}	
}

void min_to_top(t_stack **stack)
{	
	int pos;
	int size;
	
	if (! stack || !(*stack))
		return ;
	size = ft_lstsize_ps(stack);			
	pos = find_pos_value(stack, find_min(stack));
	if (pos != 1 && pos <= size / 2)
	{
		while (pos > 1)
		{
			ft_rb(stack);
			pos--;
		}
	}
	else if (pos != 1 && pos > size / 2)
	{
		while (pos <= size)
		{
			ft_rrb(stack);
			pos++;
		}
	}
}

void max_to_top(t_stack **stack)
{	
	int pos;
	int size;
	
	if (! stack || !(*stack))
		return ;
	size = ft_lstsize_ps(stack);	
	pos = find_pos_value(stack, find_max(stack));
	if (pos != 1 && pos < size / 2)
	{
		while (pos > 1)
		{
			ft_rb(stack);
			pos--;
		}

	}
	else if (pos != 1 && pos >= size / 2)
	{
		while (pos++ <= size)		
			ft_rrb(stack);		
	}
}
