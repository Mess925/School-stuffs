/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthant <hthant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 19:14:06 by hthant            #+#    #+#             */
/*   Updated: 2024/06/04 21:21:23 by hthant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

static	void	ft_delete(void *content, void (*del)(void *), t_list *new_list)
{
	del(content);
	ft_lstclear(&new_list, del);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_node;
	t_list	*temp;
	void	*current_content;

	new_list = NULL;
	if (!lst || !f || !del)
		return (NULL);
	while (lst)
	{
		current_content = f(lst->content);
		temp = ft_lstnew(current_content);
		if (!temp)
		{
			ft_delete(current_content, del, new_list);
			return (NULL);
		}
		if (!new_list)
			new_list = temp;
		else
			new_node->next = temp;
		new_node = temp;
		lst = lst->next;
	}
	return (new_list);
}
