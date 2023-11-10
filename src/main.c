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

int is_shorted(t_stack *stack)
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
    t_stack *stack_node1 = malloc(sizeof(t_stack));
    t_stack *stack_node2 = malloc(sizeof(t_stack));
    t_stack *stack_node3 = malloc(sizeof(t_stack));

    // Asignar valores a los nodos
    stack_node1->value = 3;
    stack_node2->value = 1;
    stack_node3->value = 2;

    // Construir la pila: 3 -> 1 -> 2
    stack_node1->next = stack_node2;
    stack_node2->next = stack_node3;
    stack_node3->next = NULL;

    // Imprimir la pila antes de la operación order_three
    printf("Pila antes de order_three: ");
    print_stack(stack_node1);

    // Llamar a la función order_three para ordenar la pila
    order_three(&stack_node1);

    // Imprimir la pila después de la operación order_three
    printf("Pila después de order_three: ");
    print_stack(stack_node1);

    // Liberar la memoria
    free(stack_node1);
    free(stack_node2);
    free(stack_node3);
    return (0);
}