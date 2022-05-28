/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acetin <acetin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 14:16:11 by acetin            #+#    #+#             */
/*   Updated: 2022/03/31 14:49:12 by acetin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*to_int(char **str, int ac)
{
	t_stack	*ret;
	int		size;

	ret = NULL;
	while (--ac >= 1)
	{
		size = ft_strlen(str[ac]);
		while (str[ac][--size] && size >= 0)
		{
			while ((str[ac][size] >= '0' && str[ac][size] <= '9')
				|| str[ac][size] == '-')
				size--;
			push(&ret, ft_atoi(&str[ac][size + 1]));
			while (str[ac][size] == ' ')
				size--;
			if (size == 0)
				push(&ret, ft_atoi(&str[ac][size]));
		}
	}
	return (ret);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	pivot(t_stack *stack)
{
	t_stack	*temp;
	int		ret;

	temp = stack;
	ret = 0;
	while (temp)
	{
		ret += temp->content;
		temp = temp->next;
	}
	ret = ret / ft_lstsize(stack);
	while (where(stack, ret) != 0)
		stack = stack->next;
	return (stack->content);
}

int	find_index(t_stack *stack, int data)
{
	int		first;
	int		last;
	int		j;
	int		size;

	first = 0;
	size = ft_lstsize(stack);
	while (stack && data <= stack->content)
	{
		stack = stack->next;
		first++;
	}
	j = first;
	while (stack)
	{
		if (data > stack->content)
			last = j;
		stack = stack->next;
		j++;
	}
	if (first > (size - last))
		return (last);
	return (first);
}
