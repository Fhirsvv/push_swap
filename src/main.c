/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiaz-gu <fdiaz-gu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 15:19:46 by fdiaz-gu          #+#    #+#             */
/*   Updated: 2023/11/03 13:21:48 by fdiaz-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ft_atoi(const char *str)
{
	unsigned long	result;
	int				sign;

	sign = 1;
	result = 0;
	while ((*str == ' ' || ('\t' <= *str && *str <= '\r')))
		str++;
	if (*str == '-')
	{
		sign = -sign;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		if (result > LONG_MAX && sign > 0)
			return (-1);
		if (result > LONG_MAX && sign < 0)
			return (0);
		str++;
	}
	return (result * sign);
}

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

int main(int argc, char **argv)
{
    t_stack	*stack_a;
    t_stack	*stack_b;
    
    if (argc < 2)
        return (0);
    // check_args(argv);
    printf("%i\n", check_if_nb("048"));
    printf("%i\n", check_if_nb("123 321 "));
    printf("%i\n", check_if_nb("00"));
    return (0);
}