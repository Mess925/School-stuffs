/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   non_complex_sort.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthant <hthant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 15:06:31 by hthant            #+#    #+#             */
/*   Updated: 2024/11/03 17:54:32 by hthant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	get_min_index(t_stack *stack)
{
	int	min_index;

	if (!stack)
		return (0);
	min_index = stack->index;
	while (stack)
	{
		if (stack->index < min_index)
			min_index = stack->index;
		stack = stack->next;
	}
	return (min_index);
}

void	sort_3(t_stack **stack_a)
{
	int	min_index;

	min_index = get_min_index(*stack_a);
	sort_3_helper(stack_a, min_index);
}

void	sort_4(t_stack **stack_a, t_stack **stack_b)
{
	int	min_index;

	min_index = get_min_index(*stack_a);
	while ((*stack_a)->index != min_index)
		ra(stack_a);
	pb(stack_a, stack_b);
	sort_3(stack_a);
	pa(stack_a, stack_b);
}

void	sort_5(t_stack **stack_a, t_stack **stack_b, int size)
{
	int		min_index;
	int		pos;
	t_stack	*temp;

	min_index = get_min_index(*stack_a);
	pos = 0;
	temp = *stack_a;
	while (temp && temp->index != min_index)
	{
		pos++;
		temp = temp->next;
	}
	if (pos <= size / 2)
	{
		while ((*stack_a)->index != min_index)
			ra(stack_a);
	}
	else
	{
		while ((*stack_a)->index != min_index)
			rra(stack_a);
	}
	pb(stack_a, stack_b);
	sort_4(stack_a, stack_b);
	pa(stack_a, stack_b);
}

void	non_complex_sort(t_stack **stack_a, t_stack **stack_b)
{
	int	size;

	size = ft_stacksize(*stack_a);
	if (size == 1)
		return ;
	else if (size == 2)
	{
		if ((*stack_a)->index > (*stack_a)->next->index)
			sa(stack_a);
	}
	else if (size == 3)
		sort_3(stack_a);
	else if (size == 4)
		sort_4(stack_a, stack_b);
	else if (size == 5)
		sort_5(stack_a, stack_b, size);
}
