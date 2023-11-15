/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiaz-gu <fdiaz-gu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 15:19:46 by fdiaz-gu          #+#    #+#             */
/*   Updated: 2023/11/15 16:06:28 by fdiaz-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int is_sorted(t_stack **stack)
{
    if (!stack)
        return (0);
    while ((*stack)->next != NULL)
    {
        if ((*stack)->value > ((*stack)->next)->value)
            return (0);
        stack = &(*stack)->next;
    }
    return (1);
}

void    ft_push_swap(t_stack **stack_a, t_stack **stack_b)
{
    int s_size;

    s_size = ft_lstsize_ps(stack_a);
    if (s_size == 2 && !(is_sorted(stack_a)))
        ft_sa(stack_a);
    else if (s_size == 3 && !(is_sorted(stack_a)))
        order_three(stack_a);
    else if (s_size == 4 && !(is_sorted(stack_a)))
        order_four(stack_a, stack_b);
    else if (s_size == 5 && !(is_sorted(stack_a)))           
       order_five(stack_a, stack_b);    
    
}
//*Leaks
void    leaks(void)
{
    system("leaks -q push_swap");
}

int main(int argc, char **argv)
{
    t_stack *stack_a;
    t_stack *stack_b;    

    atexit(leaks);
    stack_a = NULL;
    stack_b = NULL;
    if (argc < 2)
        return (0);    
    stack_a = resort_ags(argv, &stack_a);
    // while (aux)
    // {
    //     ft_printf("aux: ");
    //     ft_printf("%i\n", aux->value);
    //     aux = aux->next;
    // }
    if (check_duplicated(&stack_a))
        ft_error();
    ft_push_swap(&stack_a, &stack_b);
    freeList(stack_a);
    freeList(stack_b);
    // while (stack_a)
    // {
    //     ft_printf("stack_a: ");
    //     ft_printf("%i\n", stack_a->value);
    //     stack_a = stack_a->next;
    // }
    // while (stack_b)
    // {
    //     ft_printf("stack_b: ");
    //     ft_printf("%i\n", stack_b->value);
    //     stack_b = stack_b->next;
    // }
}
