
#include "../include/push_swap.h"

t_stack	*ft_get_penultimate(t_stack *stack)
{
	if (stack == NULL || stack->next == NULL)
		return (NULL);
	while (stack && (stack->next)->next != NULL)
		stack = stack->next;
	return (stack);
}

void order_three(t_stack **stack_a)
{
	if ((*stack_a)->value < (*stack_a)->next->value)
	{
		if ((*stack_a)->value > (*stack_a)->next->next->value)
			ft_rra(stack_a);
		else
		{
			ft_rra(stack_a);
			ft_sa(stack_a);
		}
	}
	else
	{
		if ((*stack_a)->next->value > (*stack_a)->next->next->value)
		{
			ft_sa(stack_a);
			ft_rra(stack_a);
		}
		else
		{
			if ((*stack_a)->value > (*stack_a)->next->next->value)
				ft_ra(stack_a);
			else
				ft_sa(stack_a);
		}
	}
}
