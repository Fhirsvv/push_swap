/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiaz-gu <fdiaz-gu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 12:13:44 by fdiaz-gu          #+#    #+#             */
/*   Updated: 2023/11/14 11:49:57 by fdiaz-gu         ###   ########.fr       */
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

t_stack *check_and_save(char *str, t_stack **first_node)
{
	int flag;
	t_stack *aux;
	int nb;
	
	// ft_printf("%s\n", str);
	nb = ft_atoi(str);
	flag = check_if_nb(str);
	// ft_printf("Flag: %i\n", flag);
	if (flag == 1)
		{
			aux = ft_lstnew_ps(nb);
			// ft_printf("AUX VALUE: %i\n", aux->value);
			ft_lstadd_back_ps(first_node, aux);
		}
	// ft_printf("NODE: %i\n", first_node->value);
	return (*first_node);
}

int	check_duplicated(t_stack **stack_a)
{
	t_stack *aux;
	
	if (!stack_a)		
		return (0);
	ft_printf("duplicated\n");	
	ft_printf("stack value: %i\n", (*stack_a)->value);
	while ((*stack_a)->next)
	{
		ft_printf("stack value: %i\n", (*stack_a)->value);
		aux = (*stack_a)->next;
		ft_printf("aux value: %i\n", aux->value);
		while (aux != NULL)
		{
			if ((*stack_a)->value == aux->value)
				return (1);
			aux = aux->next;
		}
		stack_a = &(*stack_a)->next;
	}
	return (0);
}

t_stack	*check_nb_in_argv(char *str, t_stack **stack_a)
{
	int i;
	int	j;		
	char **nb_aux;
	t_stack *aux;

	i = 0;
	j = 1;		
	nb_aux = NULL;	
	while (str[++i])
	{
		if (str[i] == 32)
		{
			nb_aux = ft_split(str, 32);			
			break ;
		}			
	}			
	if (nb_aux)
	{
		i = -1;
		while (nb_aux[++i])	
			aux = check_and_save(nb_aux[i], stack_a);		
	}
	else		
		aux = check_and_save(str, stack_a);
	return (aux);
}

t_stack	*resort_ags(char **argv, t_stack **stack)
{
	int i;
	t_stack	*aux;	

	i = 1;	
	while (argv[i])
	{
		aux = check_nb_in_argv(argv[i], stack);
		i++;
	}
	return (aux);
}