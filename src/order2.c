/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiaz-gu <fdiaz-gu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 13:21:14 by fdiaz-gu          #+#    #+#             */
/*   Updated: 2023/11/17 11:43:19 by fdiaz-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/* 
*:
		Paso 1: Agregar int index a stack
*:
		Paso 2: Agregar índice correspondiente a cada número (min:0, max: nº argc - 1)
TODO:
		Paso 3: Dividir en 5 chunks (de 20 nºs del 0 al 99 (0-19, 20-39, 40-59, 60-79, 80-99), para 100 nms)
TODO:
		Paso 4: Buscar (con el ínidice) la primera coincidencia con el chunk 1
TODO:
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
	while (aux)
	{		
		i = 1;
		while (i <= chunk_size)
		{	
			if (aux->index == i)
			{				
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
	ft_printf("LAST: %i\n", pos);
	return (pos);
}