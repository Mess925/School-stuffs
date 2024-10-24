/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthant <hthant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 14:27:03 by hthant            #+#    #+#             */
/*   Updated: 2024/06/04 19:02:23 by hthant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *));

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
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

// void print_last_list(t_list *lst)
// {
//     while (lst)
//     {
//         printf("%s\n", lst->content);
//         lst = lst->next;
//     }
// }

// int	main(void)
// {
// 	t_list *head = ft_lstnew("2");
// 	head->next = ft_lstnew("3");
// 	printf("Original List: ");
// 	print_list(head);
// 	t_list *last = ft_lstlast(head);
// 	printf("The last node of the original list is ");
// 	print_last_list(last);

// 	int j = ft_lstsize(head);
// 	printf("Size of the original list = %d\n",j);

// 	t_list *new_node = ft_lstnew("1");
// 	ft_lstadd_front(&head, new_node);

// 	t_list *sec_new_node = ft_lstnew("4");
// 	ft_lstadd_back (&head, sec_new_node);

// 	printf("New List: ");
// 	print_list(head);
// 	last = ft_lstlast(head);

// 	int	i = ft_lstsize(head);
// 	printf("Size of the new list = %d\n",i);
// 	printf("The last node of the new list is ");
// 	print_last_list(last);

// 	ft_lstdelone(last,);
// 	printf("The list is: ");
// 	print_list(head);
// }
