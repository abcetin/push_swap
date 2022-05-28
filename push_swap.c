/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acetin <acetin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 13:57:00 by acetin            #+#    #+#             */
/*   Updated: 2022/03/31 13:57:02 by acetin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort(a_stack **stack_a)
{
	b_stack	*stack_b;
	int		pivot1;
	int		i;

	stack_b = NULL;
	if (is_sorted(*stack_a))
		return ;
	pivot1 = pivot(*stack_a);
	if (pivot1 < 0)
		i = 1;
	else 
		i = 2;
	while (!is_sorted(*stack_a))
	{
		push_stack_b(stack_a, &stack_b);
		if (i > 0 && ft_lstsize(stack_b) > 5 && !is_sorted(*stack_a))
		{
			push_stack_a(stack_a, &stack_b);
			i--;
		}
	}
	if (stack_b)
		give_back(stack_a, &stack_b);
	free(stack_b);
}

t_stack	*push_swap(char **str, int len)
{
	a_stack	*stack_a;
	b_stack	*stack_b;

	stack_b = NULL;
	stack_a = to_int(str, len);
	if (!is_uniq(stack_a))
	{
		write(2, "Error\n", 6);
		free(stack_a);
		exit(EXIT_FAILURE);
	}
	if (ft_lstsize(stack_a) <= 3 && !is_sorted(stack_a))
		small_sort(&stack_a);
	else if (ft_lstsize(stack_a) <= 5 && !is_sorted(stack_a))
		size_five(&stack_a, &stack_b);
	sort(&stack_a);
	free(stack_b);
	return (stack_a);
}

int	main(int argc, char **argv)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
	{
		write(2, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
	if (!is_number(argv, argc))
	{
		write(2, "Error\n", 6);
		free(stack);
		exit(EXIT_FAILURE);
	}
	else if (argc > 1)
	{
		stack = push_swap(argv, argc);
		free(stack);
		exit(EXIT_SUCCESS);
	}
	return (0);
}
