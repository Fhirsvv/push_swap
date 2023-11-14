/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiaz-gu <fdiaz-gu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 15:19:46 by fdiaz-gu          #+#    #+#             */
/*   Updated: 2023/11/14 19:29:05 by fdiaz-gu         ###   ########.fr       */
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
    t_stack *stack_b;
    
    stack_a = NULL;
    stack_b = NULL;
    if (argc < 2)
        return (0);    
    stack_a = resort_ags(argv, &stack_a);        
    check_duplicated(&stack_a);
    if (argc == 4)
        order_three(&stack_a);
    if (argc == 6)
       order_five(&stack_a, &stack_b);
    while (stack_a)
    {
        ft_printf("stack_a: ");
        ft_printf("%i\n", stack_a->value);
        stack_a = stack_a->next;
    }
    // while (stack_b)
    // {
    //     ft_printf("stack_b: ");
    //     ft_printf("%i\n", stack_b->value);
    //     stack_b = stack_b->next;
    // }
}
