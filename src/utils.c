
#include "../include/push_swap.h"

t_stack ft_get_penultimate(t_stack *stack)
{
    if (stack == NULL || stack->next == NULL)
    return NULL;    
    while (stack && (stack->next)->next != NULL)
		stack = stack->next;
	return (stack);
}