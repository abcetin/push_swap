/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acetin <acetin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 14:08:07 by acetin            #+#    #+#             */
/*   Updated: 2022/03/31 14:14:32 by acetin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	give_back(t_stack **stack_a, t_stack **stack_b)
{
	int	size;
	int	index;

	while (*stack_b != NULL)
	{
		size = ft_lstsize(*stack_b);
		index = big_index(*stack_b);
		if (index == 1)
			sb(*stack_b);
		else if (index <= size / 2 && index != 0)
			rb(stack_b);
		else if (index >= size / 2 && index != 0)
			rrb(stack_b);
		else
			pa(stack_a, stack_b);
	}
}

void	push_stack_b(t_stack **stack_a, t_stack **stack_b)
{
	int	ort;
	int	size;
	int	index;

	ort = pivot(*stack_a);
	while (min(*stack_a) != ort)
	{
		size = ft_lstsize(*stack_a);
		index = find_index(*stack_a, ort);
		if (index <= size / 2 && index != 0)
			ra(stack_a);
		else if (index >= size / 2 && index != 0)
			rra(stack_a);
		else
			pb(stack_a, stack_b);
		if (min(*stack_a) == ort && !is_sorted(*stack_a) && size <= 5)
			size_five(stack_a, stack_b);
	}
}

void	push_stack_a(t_stack **stack_a, t_stack **stack_b)
{
	int	index;
	int	size;
	int	ort;

	ort = pivot(*stack_b);
	while (min(*stack_b) != ort)
	{
		index = find_index(*stack_b, ort);
		size = ft_lstsize(*stack_b);
		if (index <= size / 2 && index != 0)
			rb(stack_b);
		else if (index >= size / 2 && index != 0)
			rrb(stack_b);
		else
			pa(stack_a, stack_b);
		if (min(*stack_b) == ort && !is_sorted(*stack_b) && size <= 5)
			size_five(stack_b, stack_a);
	}
}

void	small_sort(t_stack **stack)
{
	if (big_index(*stack) == 0 && (min_index(*stack) == 2)
		&& ft_lstsize(*stack) != 2)
	{
		sa(*stack);
		rra(stack);
	}
	else if (big_index(*stack) == 0 && ft_lstsize(*stack) == 2)
		sa(*stack);
	else if (big_index(*stack) == 0 && is_sorted((*stack)->next))
		ra(stack);
	else if (big_index(*stack) == 1 && min_index(*stack) == 0)
	{
		rra(stack);
		sa(*stack);
	}
	else if (min_index(*stack) == 2 && big_index(*stack) == 1)
		rra(stack);
	else
		sa(*stack);
}

void	size_five(t_stack **stack, t_stack **stack_b)
{
	int	size;
	int	index;
	int	i;

	i = 0;
	size = ft_lstsize(*stack);
	while (ft_lstsize(*stack) > 3)
	{
		index = min_index(*stack);
		if (index >= ft_lstsize(*stack) / 2 && index != 0)
			rra(stack);
		else if (index <= ft_lstsize(*stack) / 2 && index != 0)
			ra(stack);
		else
			pb(stack, stack_b);
	}
	if (ft_lstsize(*stack) <= 3 && !is_sorted(*stack))
		small_sort(stack);
	while (i <= (size - ft_lstsize(*stack)))
	{
		pa(stack, stack_b);
		i++;
	}
}
