/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthant <hthant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 14:51:43 by hthant            #+#    #+#             */
/*   Updated: 2024/05/30 17:35:36 by hthant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n);

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	len;

	if (!dest && !src)
		return (NULL);
	len = 0;
	if (src < dest)
	{
		len = n;
		while (len > 0)
		{
			len--;
			((unsigned char *)dest)[len] = ((unsigned char *)src)[len];
		}
	}
	else
	{
		len = 0;
		while (len < n)
		{
			((unsigned char *)dest)[len] = ((unsigned char *)src)[len];
			len++;
		}
	}
	return (dest);
}

// int	main(void)
// {
// 	char src[] = "HELLOHIOOO";
// 	char dest1[]= "hellohio";
// 	char src1[] = "HELLOHIOOO";
// 	char dest[] = "hellohio";
// 	char *i = ft_memmove(dest1,src,10);
// 	char *j = memmove(dest,src1,10);
// 	printf("%s\n%s\n",i,j);
// }
