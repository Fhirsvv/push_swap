/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiaz-gu <fdiaz-gu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 13:21:14 by fdiaz-gu          #+#    #+#             */
/*   Updated: 2023/11/18 16:04:26 by fdiaz-gu         ###   ########.fr       */
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
TODO:
		Paso 6: Ver cual es más eficiente de poner en el top del stack A
TODO:
		Paso 7: Verificar que el número en el top del stack B sea el menor de todos
TODO:
		Paso 8: Pushear el top de stack A a stack B
TODO:
		Repetir proceso hasta acabar con todo el chunk 1 y posteroirm ente con todos los chunks
TODO:
		Cuando A esté vacío, poner en top de B el mayor y pushear a A
TODO:
		Repetir hasta tener A lleno.
*/

int	find_first_occurrence(t_stack **stack, int chunk_size)
{
	t_stack	*aux;
	int i;
	int	pos;

	pos = 1;
	aux = *stack;
	ft_printf("CHUNK_SIZE: %i\n", chunk_size);
	while (aux)
	{		
		i = 1;
		while (i <= chunk_size)
		{
			if (aux->index == i)
			{
				ft_printf("FIRST IN FUNCTION: %i\n", aux->index);
				return (aux->index);
			}
			i++;
		}
		aux = aux->next;
	}	
	return (pos);
}

int	find_last_occurrence(t_stack **stack, int chunk_size)
{
	t_stack	*aux;
	int i;
	int	pos;

	pos = 1;
	aux = *stack;
	while (aux)
	{		
		i = 1;
		while (i <= chunk_size)
		{	
			if (aux->index == i)		
				pos = aux->index;
			i++;
		}
		aux = aux->next;
	}
	// ft_printf("LASTT: %i\n", pos);
	return (pos);
}

//TODO: Arreglar recursividad(chunk_size para ir avanzando)
void	order_til_hundred(t_stack **stack_a, t_stack **stack_b)
{
	int	lst_size;
	int first;
	int last;
	int	aux_size;
	
	lst_size = ft_lstsize_ps(stack_a);
	aux_size = lst_size;
	ft_printf("size :%i\n", lst_size);
	while(lst_size > 0)
	{
		first = find_pos_index(stack_a,
			find_first_occurrence(stack_a, lst_size / 5));
		ft_printf("First :%i\n", first);
		last = find_pos_index(stack_a, find_last_occurrence(stack_a, lst_size / 5));
		ft_printf("Last :%i\n", last);
		if ((first - 1) < (lst_size - last))
		{
			while (first > 1)
			{
				ft_ra(stack_a);
				first--;
			}
		}
		else
		{
			while (last < lst_size)
			{
				ft_rra(stack_a);
				last++;
			}
		}
	min_to_top(stack_b);
	ft_pb(stack_a, stack_b);
	lst_size--;
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
			ft_ra(stack);
			pos--;
		}
	}
	else if (pos != 1 && pos > size / 2)
	{
		while (pos <= size)
		{
			ft_rra(stack);
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
	if (pos != 1 && pos < size / 2 && stack)
	{
		while (pos > 1)
		{
			ft_ra(stack);
			pos--;
		}

	}
	else if (pos != 1 && pos >= size / 2 && stack)
	{
		while (pos <= size)
		{
			ft_rra(stack);
			pos++;
		}
	}
}
