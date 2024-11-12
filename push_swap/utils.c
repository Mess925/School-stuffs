/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthant <hthant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 16:53:32 by hthant            #+#    #+#             */
/*   Updated: 2024/11/03 17:54:59 by hthant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free(char **values)
{
	int	i;

	i = 0;
	while (values[i])
	{
		free(values[i]);
		i++;
	}
	free(values);
}

int	is_sorted(t_stack **stack)
{
	t_stack	*head;

	head = *stack;
	while (head && head->next)
	{
		if (head->value > head->next->value)
			return (0);
		head = head->next;
	}
	return (1);
}

void	ft_free_stack(t_stack **stack)
{
	t_stack	*head;
	t_stack	*tem;

	head = *stack;
	while (head)
	{
		tem = head;
		head = head->next;
		free(tem);
	}
	free(stack);
}

char	**args_help(int ac, char **av, char **args, char **temp)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	while (++i < ac)
	{
		temp = ft_split(av[i], ' ');
		j = -1;
		while (temp[++j])
		{
			args[k] = ft_strdup(temp[j]);
			if (!args[k])
			{
				ft_free(temp);
				ft_free(args);
				return (NULL);
			}
			k++;
		}
		ft_free(temp);
	}
	args[k] = NULL;
	return (args);
}

void	sort_3_helper(t_stack **stack_a, int min_index)
{
	if ((*stack_a)->index == min_index)
	{
		if ((*stack_a)->next->index > (*stack_a)->next->next->index)
		{
			rra(stack_a);
			sa(stack_a);
		}
	}
	if ((*stack_a)->next->index == min_index)
	{
		if ((*stack_a)->index > (*stack_a)->next->next->index)
			ra(stack_a);
		else if ((*stack_a)->next->next->index > (*stack_a)->index)
			sa(stack_a);
	}
	if ((*stack_a)->next->next->index == min_index)
	{
		if ((*stack_a)->index > (*stack_a)->next->index)
		{
			sa(stack_a);
			rra(stack_a);
		}
		else if ((*stack_a)->next->index > (*stack_a)->index)
			rra(stack_a);
	}
}
