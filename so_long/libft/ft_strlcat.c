/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthant <hthant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 15:49:42 by hthant            #+#    #+#             */
/*   Updated: 2024/05/24 16:13:18 by hthant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size);

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	dst_len;

	i = 0;
	j = ft_strlen(dst);
	dst_len = j;
	if (size < j)
		return (size + ft_strlen((char *)src));
	while (src[i] != '\0' && j + 1 < size)
	{
		dst[j] = src[i];
		i++;
		j++;
	}
	dst[j] = '\0';
	return (dst_len + ft_strlen((char *)src));
}

// int main(void)
// {
// 	char dst[] = "hi";
// 	char dst2[] = "hi";
// 	size_t j = ft_strlcat(dst,"hello",5);
// 	size_t k = ft_strlcat(dst2,"pello",5);
// 	printf("%zu\n%zu\n",j,k);
// }
