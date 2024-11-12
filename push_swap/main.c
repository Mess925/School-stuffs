/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthant <hthant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 16:53:39 by hthant            #+#    #+#             */
/*   Updated: 2024/10/29 17:32:56 by hthant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_stack(t_stack **stack, int ac, char **av)
{
	t_stack	*new_node;
	char	**args;
	int		i;

	i = 0;
	if (ac < 2)
		return ;
	args = ft_args(ac, av);
	if (!args)
		return ;
	while (args[i])
	{
		new_node = create_node(ft_atoi(args[i]));
		ft_lstadd_b(stack, new_node);
		i++;
	}
	asign_index(stack);
	ft_free(args);
}

void	sort_stack(t_stack **stack_a, t_stack **stack_b)
{
	if (ft_stacksize(*stack_a) <= 5)
		non_complex_sort(stack_a, stack_b);
	else
		radix_sort(stack_a, stack_b);
}

int	main(int ac, char **av)
{
	t_stack	**stack_a;
	t_stack	**stack_b;

	if (ac < 2)
		return (-1);
	if (!ft_check_args(ac, av))
		return (0);
	stack_a = (t_stack **)malloc(sizeof(t_stack));
	stack_b = (t_stack **)malloc(sizeof(t_stack));
	*stack_a = NULL;
	*stack_b = NULL;
	add_stack(stack_a, ac, av);
	if (is_sorted(stack_a))
	{
		ft_free_stack(stack_a);
		ft_free_stack(stack_b);
		return (0);
	}
	sort_stack(stack_a, stack_b);
	ft_free_stack(stack_a);
	ft_free_stack(stack_b);
	return (0);
}
