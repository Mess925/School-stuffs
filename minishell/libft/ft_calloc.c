/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthant <hthant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 15:52:52 by hthant            #+#    #+#             */
/*   Updated: 2024/05/30 14:59:30 by hthant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	*ft_calloc(size_t nmeb, size_t size);

void	*ft_calloc(size_t nmeb, size_t size)
{
	void	*ptr;

	ptr = (void *)malloc(nmeb * size);
	if (!ptr)
		return (NULL);
	ft_bzero (ptr, nmeb * size);
	return (ptr);
}

// int	main(void)
// {
// 	int size = 8539;
// 	// unsigned char *s = ft_calloc(10,8);
// 	// unsigned char *a = calloc(10,8);
// 	// printf("%s\n%s\n",s,a);
// 	char *d1 = ft_calloc(size, sizeof(int));
//  	char *d2 = calloc(size, sizeof(int));
//  	// if (memcmp(d1, d2, size * sizeof(int)))
//  	// 	exit(TEST_FAILED);
// 	printf("%s\n%s\n",d1,d2);

// }
