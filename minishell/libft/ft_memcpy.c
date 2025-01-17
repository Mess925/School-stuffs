/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthant <hthant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 11:10:52 by hthant            #+#    #+#             */
/*   Updated: 2024/05/29 18:58:38 by hthant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n);

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	if (!dest && !src)
		return (NULL);
	i = 0;
	while (i < n)
	{
		((char *)dest)[i] = ((char *)src)[i];
		i++;
	}
	return (dest);
}

// int	main(void)
// {
// 	//char des[] = "gell";
// 	char src[] = "helloab";
// 	char des[] = "gell";
// 	char d[] = "helloab";
// 	ft_memcpy(des,src,6);
// 	printf("%s\n",des);
// 	// memcpy(c,d,6);
// 	// printf("%s\n",c);
// }
