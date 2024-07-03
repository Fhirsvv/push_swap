/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecortes- <ecortes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 16:55:41 by ecortes-          #+#    #+#             */
/*   Updated: 2024/07/03 15:08:26 by ecortes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	check_if_nb(char *str)
{
	int	i;	

	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (str[i] == '\0')
		ft_error();
	while (str[i] && str[i] >= '0' && str[i] <= '9')
		i++;
	if (str[i] != '\0' && !(str[i] >= '0' && str[i] <= '9'))
		ft_error();
	return (1);
}

t_stack	*check_and_save(char *str, t_stack **first_node)
{
	int				flag;
	t_stack			*aux;
	unsigned long	nb;

	nb = ft_atoi_ps(str);
	flag = check_if_nb(str);
	if (flag)
	{
		aux = ft_lstnew_ps(nb);
		ft_lstadd_back_ps(first_node, aux);
	}
	return (*first_node);
}

void	check_duplicated(t_stack **stack_a)
{
	t_stack	*aux;

	if (!stack_a)
		return ;
	while ((*stack_a)->next)
	{
		aux = (*stack_a)->next;
		while (aux != NULL)
		{
			if ((*stack_a)->value == aux->value)
				ft_error();
			aux = aux->next;
		}
		stack_a = &(*stack_a)->next;
	}
}

t_stack	*check_nb_in_argv(char *str, t_stack **stack_a)
{
	int		i;
	char	**nb_aux;
	t_stack	*aux;

	i = 0;
	nb_aux = NULL;
	while (str[++i])
	{
		if (str[i] == ' ')
		{
			nb_aux = ft_split(str, ' ');
			break ;
		}
	}
	if (nb_aux)
	{
		i = -1;
		while (nb_aux[++i])
			aux = check_and_save(nb_aux[i], stack_a);
		ft_free_split(nb_aux);
	}
	else
		aux = check_and_save(str, stack_a);
	return (aux);
}

t_stack	*resort_ags(char **argv, t_stack **stack)
{
	int		i;
	t_stack	*aux;	

	i = 1;
	while (argv[i])
	{
		aux = check_nb_in_argv(argv[i], stack);
		i++;
	}
	return (aux);
}
