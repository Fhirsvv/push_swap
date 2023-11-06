/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiaz-gu <fdiaz-gu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 15:19:46 by fdiaz-gu          #+#    #+#             */
/*   Updated: 2023/11/03 15:31:42 by fdiaz-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int main(int argc, char **argv)
{
    t_stack	*stack_a;
    t_stack	*stack_b;

    if (argc < 2)
        return (0);
	check_and_save(argv, stack_a);
    // check_args(argv);
    // printf("%i\n", check_if_nb("048"));
    // printf("%i\n", check_if_nb("123 321"));
    // printf("%i\n", check_if_nb("00"));
    return (0);
}