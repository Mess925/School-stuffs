/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthant <hthant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 16:53:23 by hthant            #+#    #+#             */
/*   Updated: 2024/10/20 22:05:46 by hthant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*get_mini(t_stack **stack)
{
	t_stack	*head;
	t_stack	*mini;

	head = *stack;
	mini = NULL;
	while (head)
	{
		if (head->index == -1 && (!mini || head->value < mini->value))
			mini = head;
		head = head->next;
	}
	return (mini);
}

void	asign_index(t_stack **stack)
{
	t_stack	*head;
	int		index;

	index = 0;
	head = get_mini(stack);
	while (head)
	{
		head->index = index++;
		head = get_mini(stack);
	}
}

// int main() {

//     t_stack *stack = create_node(3);
//     stack->next = create_node(1);
//     stack->next->next = create_node(2);

//     printf("Before indexing:\n");
//     print_list(stack);

//     printf("Indices before indexing:\n");
//     t_stack *current = stack;
//     while (current) {
//         printf("Value: %d, Index: %d\n", current->value, current->index);
//         current = current->next;
//     }

//     asign_index(&stack);
//     printf("\nAfter indexing:\n");

//     print_list(stack);
//     printf("Indices after indexing:\n");

//     current = stack;
//     while (current) {
//         printf("Value: %d, Index: %d\n", current->value, current->index);
//         current = current->next;
//     }
//     current = stack;
//     t_stack *next_node;
//     while (current) {
//         next_node = current->next;
//         free(current);
//         current = next_node;
//     }

//     return (0);
// }
