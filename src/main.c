/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiaz-gu <fdiaz-gu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 15:19:46 by fdiaz-gu          #+#    #+#             */
/*   Updated: 2023/11/19 18:03:57 by fdiaz-gu         ###   ########.fr       */
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

void    ft_print(t_stack **stack_a, t_stack **stack_b)
{
    while ((*stack_a))
    {
        ft_printf("%s (*stack_a) -> ", COLOR_GREEN);
        ft_printf("%s nb: %i index: %i\n",COLOR_RESET ,(*stack_a)->value, (*stack_a)->index);
        stack_a = &(*stack_a)->next;
    }
    if (*stack_b)
        ft_printf("---------------------------\n");
    while ((*stack_b))
    {
        ft_printf("%s stack_b -> ", COLOR_BLUE);
        ft_printf("%snb: %i index: %i\n",COLOR_RESET ,(*stack_b)->value, (*stack_b)->index);
        stack_b = &(*stack_b)->next;
    }
    
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
    else if (s_size <= 100 && !(is_sorted(stack_a)))
        loops_for_hundred(stack_a, stack_b, s_size);
    else if (s_size > 100 && !(is_sorted(stack_a)))
        loops_for_five_hundred(stack_a, stack_b, s_size);
    
}
//*Leaks
// void    leaks(void)
// {
//     system("leaks -q push_swap");
// }

void	ft_free_split(char **str)
{
    int i;
    i = 0;
    while (str[i])
    {    
        free(str[i]);           
        i++;
    }
    free(str);
}

int main(int argc, char **argv)
{
    t_stack *stack_a;
    t_stack *stack_b;
    // t_stack *aux;   

    // atexit(leaks);
    stack_a = NULL;
    stack_b = NULL;
    if (argc < 2)
        return (0);    
    stack_a = resort_ags(argv, &stack_a);
    check_duplicated(&stack_a);
    assign_index(&stack_a, 1);
    // max_to_top(&stack_a);
    // aux = stack_a;
    // // if (stack_a == NULL)
    // //     ft_error();
    // while (aux)
    // {
    //     ft_printf("aux: ");
    //     ft_printf("nb: %i index: %i\n", aux->value, aux->index);
    //     aux = aux->next;
    // }
    // while (stack_a)
    // {
    //     ft_printf("%s stack_a -> ", COLOR_RESET);
    //     ft_printf("nb: %i index: %i\n", stack_a->value, stack_a->index);
    //     stack_a = stack_a->next;
    // }
    ft_push_swap(&stack_a, &stack_b);
    // aux = stack_a;   
    // min_to_top(&stack_b);
    // ft_printf("---------------------------\n");
    // aux = stack_b;
    // while (aux)
    // {
    //     ft_printf("aux: ");
    //     ft_printf("nb: %i index: %i\n", aux->value, aux->index);
    //     aux = aux->next;
    // }
    // while (stack_b)
    // {
    //     ft_printf("stack_a: ");
    //     ft_printf("%i\n", stack_b->value);
    //     stack_b = stack_b->next;
    // }
    freeList(stack_a);
    freeList(stack_b);
    // while (stack_b)
    // {
    //     ft_printf("stack_b: ");
    //     ft_printf("%i\n", stack_b->value);
    //     stack_b = stack_b->next;
    // }
}
