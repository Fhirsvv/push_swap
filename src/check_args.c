/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiaz-gu <fdiaz-gu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 12:13:44 by fdiaz-gu          #+#    #+#             */
/*   Updated: 2023/11/10 14:06:08 by fdiaz-gu         ###   ########.fr       */
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

	// flag = 1;
	flag = check_if_nb(str);
	if (flag == 1)
		{
			aux = ft_lst_new(str);
			ft_lstadd_back(&first_node, aux);
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

int	check_nb_in_argv(char **str, t_stack *stack_a)
{
	int i;
	int flag;
	char **nb_aux;

	i = 1;
	flag = 1;
	nb_aux = NULL;
	while(str[++i])
	{
		if (str[i] == 32)
		{
			nb_aux = ft_split(str, " ");
			break ;
		}		
	}
	if (nb_aux)
	while (nb_aux[++i])
		check_and_save(nb_aux[i], stack_a);
	else
		check_and_save(str, stack_a);
	return (flag);
}
