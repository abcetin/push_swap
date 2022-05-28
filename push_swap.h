/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acetin <acetin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 14:17:02 by acetin            #+#    #+#             */
/*   Updated: 2022/03/31 14:51:12 by acetin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int				content;
	struct s_stack	*next;
} a_stack, b_stack,	t_stack;

t_stack		*push_swap(char **str, int len);

//RULES
void		swap(int *a, int *b);
void		sa(a_stack *a);
void		sb(b_stack *b);
void		ss(a_stack *a, b_stack *b);
void		pa(a_stack **a, b_stack **b);
void		pb(a_stack **a, b_stack **b);
void		ra(a_stack **a);
void		rb(b_stack **b);
void		rr(a_stack **a, b_stack **b);
void		rra(a_stack **a);
void		rrb(b_stack **b);
void		rrr(a_stack **a, b_stack **b);
void		push(t_stack **stack, int data);
void		pop(t_stack **stack);

//UTİLS
t_stack		*to_int(char **str, int len);
t_stack		*ft_lstlast(t_stack *lst);
int			ft_atoi(const char *str);
int			ft_lstsize(t_stack *lst);
int			is_number(char **str, int ac);
int			ft_strlen(char *str);
int			is_uniq(t_stack *stack);
int			min_index(t_stack *stack);
int			min(t_stack *stack);
int			big_index(t_stack *stack);
int			big(t_stack *stack);
int			where(t_stack *stack, int data);
int			pivot(t_stack *stack);
int			find_index(t_stack *stack, int data);

//SORT
int			is_sorted(t_stack *stack);
void		sort(a_stack **stack_a);
void		push_stack_b(t_stack **stack_a, t_stack **stack_b);
void		push_stack_a(t_stack **stack_a, t_stack **stack_b);
void		small_sort(t_stack **stack);
void		size_five(t_stack **stack_a, t_stack **stack_b);
void		give_back(t_stack **stack_a, t_stack **stack_b);
#endif
