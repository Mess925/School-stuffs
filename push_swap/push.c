/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthant <hthant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 13:10:49 by hthant            #+#    #+#             */
/*   Updated: 2024/10/20 22:05:53 by hthant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push(t_stack **to_stack, t_stack **from_stack)
{
	t_stack	*to_head;
	t_stack	*from_head;
	t_stack	*temp_node;

	if (ft_stacksize(*from_stack) == 0)
		return (-1);
	to_head = *to_stack;
	from_head = *from_stack;
	temp_node = from_head;
	from_head = from_head->next;
	*from_stack = from_head;
	if (!to_head)
	{
		to_head = temp_node;
		to_head->next = NULL;
		*to_stack = to_head;
	}
	else
	{
		temp_node->next = to_head;
		*to_stack = temp_node;
	}
	return (0);
}

int	pa(t_stack **stack_a, t_stack **stack_b)
{
	if (push(stack_a, stack_b) == -1)
		return (-1);
	ft_putendl_fd("pa", 1);
	return (0);
}

int	pb(t_stack **stack_a, t_stack **stack_b)
{
	if (push(stack_b, stack_a) == -1)
		return (-1);
	ft_putendl_fd("pb", 1);
	return (0);
}
