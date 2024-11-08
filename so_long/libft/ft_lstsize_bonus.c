/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthant <hthant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 13:05:12 by hthant            #+#    #+#             */
/*   Updated: 2024/06/04 20:08:48 by hthant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst);

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

// void print_list(t_list *lst)
// {
//     while (lst)
//     {
//         printf("%s -> ", lst->content);
//         lst = lst->next;
//     }
//     printf("NULL\n");
// }

// int	main(void)
// {
// 	t_list *head = ft_lstnew("2");
// 	head->next = ft_lstnew("3");
// 	printf("Original List: ");
// 	print_list(head);

// 	int j = ft_lstsize(head);
// 	printf("Size of the original list = %d\n",j);

// 	t_list *new_node = ft_lstnew("1");
// 	ft_lstadd_front(&head, new_node);
// 	printf("New List: ");
// 	print_list(head);

// 	int	i = ft_lstsize(head);
// 	printf("Size of the new list = %d\n",i);
// }
