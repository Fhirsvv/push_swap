/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiaz-gu <fdiaz-gu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 12:13:44 by fdiaz-gu          #+#    #+#             */
/*   Updated: 2023/11/03 15:17:57 by fdiaz-gu         ###   ########.fr       */
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
	t_stack *peep;

	flag = 1;
	flag = check_if_nb(str);
	if (flag == 1)
		{
			peep = ft_lst_new(str);
			ft_lstadd_back(&first_node, peep);
		}
	return (flag);
}

int	check_nb_in_argv(char *str)
{
	int i;
	int flag;
	char **nb_aux;

	i = 0;
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
		check_and_save(nb_aux[i], t_stack);
	else
		check_and_save(str, t_stack);
}

// int	check_args(char **str)
// {
// 	int	i;
// 	int sum_zero;
	
// 	i = 1;
// 	while (str[i])
// 	{
// 		if (!(check_if_nb(str[i])))
// 			return (0);
// 		//TODO: PASAR A NUMERO Y DPS DUPLICADOS
// 		i++;
// 	}
// 	return (1);
// }