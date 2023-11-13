
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

t_stack	*ft_lstnew_ps(int content)
{
	t_stack	*new;

	new = malloc(sizeof(*new));
	if (!new)
		return (NULL);
	new->value = content;
	new->next = NULL;
	return (new);
}

void	ft_lstadd_back_ps(t_stack **lst, t_stack *new)
{
	t_stack	*last;

	if (!*lst)
		*lst = new;
	else
	{
		last = *lst;
		while (last->next != NULL)
		{
			last = last->next;
		}
		last->next = new;
	}
}
void	ft_lstadd_front_ps(t_stack **lst, t_stack *new)
{
	new->next = *lst;
	*lst = new;
}
