/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiaz-gu <fdiaz-gu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 12:13:44 by fdiaz-gu          #+#    #+#             */
/*   Updated: 2023/11/13 17:49:58 by fdiaz-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	check_if_nb(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
		i++;
	if (str[i] != '\0' && !(str[i] >= '0' && str[i] <= '9'))
		return (0);
	return (1);
}

int check_and_save(char *str, t_stack *first_node)
{
	int flag;
	t_stack *aux;
	int nb;
	// flag = 1;
	nb = ft_atoi(str);
	ft_printf("%s\n", "cas");
	ft_printf("%i\n", nb);
	flag = check_if_nb(str);
	if (flag == 1)
		{
			aux = ft_lstnew_ps(nb);
			ft_lstadd_back_ps(&first_node, aux);
		}
	return (flag);
}

int	check_duplicated(t_stack *stack_a)
{
	t_stack *aux;
	
	if (!stack_a)
		return (0);
	while (stack_a != NULL)
	{
		aux = stack_a->next;
		while (aux != NULL)
		{
			if (stack_a->value == aux->value)
				return (1);
			aux = aux->next;
		}
		stack_a = stack_a->next;
	}
	return (0);
}
//TODO: Acortar función
//TODO: Modificar función para passar cada argumento y no todo del tirón
int	check_nb_in_argv(char **str, t_stack *stack_a)
{
	int i;
	int	j;
	int k;
	int flag;
	char **nb_aux;

	i = 1;
	j = 1;
	k = 0;
	flag = 1;
	nb_aux = NULL;
	while(str[i])
	{
		while (str[i][k])
		{
			if (str[i][k] == 32)
			{
				nb_aux = ft_split(str[i], 32);
				break ;
			}
			k++;
		}
		i++;
	}	
	i = 0;
	if (nb_aux)
	{
		while (nb_aux[i])
		{
			check_and_save(nb_aux[i], stack_a);
			i++;
		}
	}
	else
	{
		while (str[j])
		{
			check_and_save(str[j], stack_a);
			j++;	
		}
	}
	return (flag);
}
