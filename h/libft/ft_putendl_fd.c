/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthant <hthant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 11:08:47 by hthant            #+#    #+#             */
/*   Updated: 2024/05/24 16:57:37 by hthant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	ft_putendl_fd(char *s, int fd);

void	ft_putendl_fd(char *s, int fd)
{
	const char	nl = '\n';

	write(fd, s, ft_strlen(s));
	write(fd, &nl, 1);
}

// int	main(void)
// {
// 	ft_putendl_fd("hello",1);
// }
