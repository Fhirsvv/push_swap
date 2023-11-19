/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdiaz-gu <fdiaz-gu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 10:50:44 by fdiaz-gu          #+#    #+#             */
/*   Updated: 2023/11/19 17:52:02 by fdiaz-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <stdlib.h>
# include "../libft/libft.h"
# include "../libft/ft_printf.h"
# include "../libft/get_next_line.h"
# define COLOR_RED "\033[0;31m"
# define COLOR_GREEN "\033[0;32m"
# define COLOR_BLUE "\033[0;36m"
# define COLOR_RESET "\033[0m"


typedef struct s_stack
{
	int		value;
	int     index;
	struct  s_stack *next;
}t_stack;

t_stack     *ft_get_penultimate(t_stack *stack);
void		order_three(t_stack **stack_a);
void		ft_sa(t_stack **stack_a);
void		ft_sb(t_stack **stack_b);
void		ft_ss(t_stack **stack_a, t_stack **stack_b);
void		ft_ra(t_stack **stack_a);
void		ft_rb(t_stack **stack_b);
void		ft_rr(t_stack **stack_a, t_stack **stack_b);
void		ft_rra(t_stack **stack_a);
void		ft_rrb(t_stack **stack_b);
void		ft_rrr(t_stack **stack_a, t_stack **stack_b);
void		ft_pa(t_stack **stack_a, t_stack **stack_b);
void		ft_pb(t_stack **stack_a, t_stack **stack_b);
t_stack		*check_nb_in_argv(char *str, t_stack **stack_a);
void		check_duplicated(t_stack **stack_a);
t_stack		*check_and_save(char *str, t_stack **first_node);
int			check_if_nb(char *str);
t_stack		*ft_lstnew_ps(int content);
void		ft_lstadd_back_ps(t_stack **lst, t_stack *new);
void		ft_lstadd_front_ps(t_stack **lst, t_stack *new);
t_stack		*ft_lstlast_ps(t_stack *lst);
t_stack		*resort_ags(char **argv, t_stack **stack);
void		ft_error(void);
int			find_min(t_stack **stack);
void		order_five(t_stack **stack_a, t_stack **stack_b);
int			is_sorted(t_stack **stack);
void		order_four(t_stack **stack_a, t_stack **stack_b);
int			ft_lstsize_ps(t_stack **stack);
void		freeList(t_stack *stack);
void		ft_free_split(char **str);
void		assign_index(t_stack **stack, int index);
int			find_min_without_stack(t_stack **stack);
int			find_first_occurrence(t_stack **stack, int first, int last);
int			find_last_occurrence(t_stack **stack, int first, int last);
int			find_pos_index(t_stack **stack, int nb);
int			find_pos_value(t_stack **stack, int nb);
void		order_by_chunks(t_stack **stack_a, t_stack **stack_b, int first, int last);
void		min_to_top(t_stack **stack);
void		max_to_top(t_stack **stack);
int			find_max(t_stack **stack);
void	loops_for_hundred(t_stack **stack_a, t_stack **stack_b, int size);
void	loops_for_five_hundred(t_stack **stack_a, t_stack **stack_b, int size);
void    ft_print(t_stack **stack_a, t_stack **stack_b);