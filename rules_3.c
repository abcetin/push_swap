/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acetin <acetin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 14:02:15 by acetin            #+#    #+#             */
/*   Updated: 2022/03/31 14:03:52 by acetin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pop(t_stack **stack)
{
	t_stack	*iter;

	iter = (*stack);
	while (iter->next->next != NULL)
		iter = iter->next;
	iter->next = NULL;
}

void	push(t_stack **stack, int data)
{
	t_stack	*temp;

	temp = (t_stack *)malloc(sizeof(t_stack));
	if (!temp)
		return ;
	temp->content = data;
	temp->next = NULL;
	if (!stack)
	{
		(*stack) = temp;
		return ;
	}
	temp->next = (*stack);
	(*stack) = temp;
}

void	rrb(b_stack **b)
{
	b_stack	*first;

	first = ft_lstlast(*b);
	pop(b);
	first->next = (*b);
	(*b) = first;
	write(1, "rrb\n", 4);
}

void	rrr(a_stack **a, b_stack **b)
{
	a_stack	*first;
	b_stack	*last;

	last = ft_lstlast(*b);
	pop(b);
	last->next = (*b);
	(*b) = last;
	first = ft_lstlast(*a);
	pop(a);
	first->next = (*a);
	(*a) = first;
	write(1, "rrr\n", 4);
}
