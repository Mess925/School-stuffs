/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthant <hthant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 16:46:59 by hthant            #+#    #+#             */
/*   Updated: 2024/06/04 16:05:37 by hthant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new);

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
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

// 	t_list *new_node = ft_lstnew("1");
// 	ft_lstadd_front(&head, new_node);
// 	printf("New List: ");
// 	print_list(head);
// }
