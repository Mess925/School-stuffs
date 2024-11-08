/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthant <hthant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 19:49:00 by hthant            #+#    #+#             */
/*   Updated: 2024/05/29 18:35:03 by hthant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n);

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	if (n == 0)
		return (0);
	i = 0;
	while (i < n)
	{
		if (((unsigned char *)s1)[i] != ((unsigned char *)s2)[i])
		{
			if (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i] < 0)
				return (-1);
			else if (((unsigned char *)s1)[i] -
			((unsigned char *)s2)[i] > 0)
				return (1);
		}
		i++;
	}
	return (0);
}

// int	main(void)
// {
// 	int	i = ft_memcmp("addsd","adddd",5);
// 	int	j = memcmp("addsd","adddd",5);
// 	printf("%d\n%d\n",i,j);
// }
