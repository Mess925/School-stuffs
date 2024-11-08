/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthant <hthant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 14:09:37 by hthant            #+#    #+#             */
/*   Updated: 2024/05/20 16:52:33 by hthant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include<unistd.h>
#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size);

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size > 0)
	{
		while (src[i] != '\0' && i < (size -1))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (ft_strlen((char *)src));
}
//int main(void) {
//	const char *src= "hello";
//  char dest[] = "";
//    unsigned int i = ft_strlcpy(dest, src, 3);
//    printf("%s (%d)\n", dest, i);
//    return (0);
//}
// #include <unistd.h>
// #include <stdio.h>
// #include "libft.h"

// size_t    ft_strlcpy(char *dst, const char *src, size_t size);

// size_t    ft_strlcpy(char *dst, const char *src, size_t size)
// {
//     size_t    i;
//     printf("%zu\n",ft_strlen((char *)src));
//     i = 0;
//     if (size > 0)
//     {
//         while (src[i] != '\0' && i < (size - 1))
//         {
//             dst[i] = src[i];
//             i++;
//         }
// 		printf("%zu\n",ft_strlen((char *)src));
//         dst[i] = '\0';
// 		printf("%zu\n",ft_strlen((char *)src));
//     }
//     return (ft_strlen((char *)src));
// }

// int    main()
// {
//     const char src[] = "asdfdf";
//     char dst[] = "";
//     printf("%zu", ft_strlcpy(dst, src, 4));
// }
