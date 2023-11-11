/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiaz-gu <fdiaz-gu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 15:19:46 by fdiaz-gu          #+#    #+#             */
/*   Updated: 2023/11/10 14:48:17 by fdiaz-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int is_sorted(t_stack *stack)
{
    if (!stack)
        return (0);
    while (stack->next != NULL)
    {
        if (stack->value > (stack->next)->value)
            return (0);
        stack = stack->next;
    }
    return (1);
}

int main(int argc, char **argv)
{
    t_stack *stack_a;
    
    if (argc < 2)
        return (NULL);
    check_nb_in_argv(argv, &stack_a);
    while (stack_a != NULL) {
        printf("%d ", stack_a->value);
        stack_a = stack_a->next;
    }
    check_duplicated(&stack_a);
}