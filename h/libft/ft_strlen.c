/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthant <hthant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 13:31:39 by hthant            #+#    #+#             */
/*   Updated: 2024/05/20 16:52:32 by hthant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
#include <unistd.h>

size_t	ft_strlen(const char *s);

size_t	ft_strlen(const char *s)
{
	size_t		i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

// int	main(void)
// {
// 	size_t i = strlen("hi hello");
// 	printf("%d",i);
// }
