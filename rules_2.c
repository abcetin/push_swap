/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acetin <acetin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 13:59:11 by acetin            #+#    #+#             */
/*   Updated: 2022/03/31 14:01:55 by acetin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb(a_stack **a, b_stack **b)
{
	push(b, (*a)->content);
	(*a) = (*a)->next;
	write(1, "pb\n", 3);
}

void	ra(a_stack **a)
{
	a_stack	*temp;
	a_stack	*last;

	last = ft_lstlast(*a);
	temp = (*a);
	(*a) = (*a)->next;
	last->next = temp;
	temp->next = NULL;
	write(1, "ra\n", 3);
}

void	rb(b_stack **b)
{
	b_stack	*last;
	b_stack	*temp;

	last = ft_lstlast(*b);
	temp = (*b);
	(*b) = (*b)->next;
	last->next = temp;
	temp->next = NULL;
	write(1, "rb\n", 3);
}

void	rr(a_stack **a, b_stack **b)
{
	a_stack	*a_temp;
	a_stack	*first;
	b_stack	*last;
	b_stack	*b_temp;

	first = ft_lstlast(*a);
	a_temp = (*a);
	(*a) = (*a)->next;
	first->next = a_temp;
	a_temp->next = NULL;
	last = ft_lstlast(*b);
	b_temp = (*b);
	(*b) = (*b)->next;
	last->next = b_temp;
	b_temp->next = NULL;
	write(1, "rr\n", 3);
}

void	rra(a_stack **a)
{
	a_stack	*first;

	first = ft_lstlast(*a);
	pop(a);
	first->next = (*a);
	(*a) = first;
	write(1, "rra\n", 4);
}
