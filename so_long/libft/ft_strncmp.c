/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthant <hthant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 15:20:57 by hthant            #+#    #+#             */
/*   Updated: 2024/05/30 12:20:30 by hthant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n);

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (s1[i] != s2[i])
			return (((unsigned char)s1[i] - (unsigned char)s2[i]));
		if (s1[i] == '\0')
			return (0);
		i++;
	}
	if (n == 0)
		return (0);
	return (0);
}

// int main(void)
// {
// 	int i = ft_strncmp("abc","abc",7);
// 	int j = strncmp("abc","abc",7);
// 	printf("%d\n%d\n",i,j);
// }
// int	main(void)
// {
// 	char *s1 = "atoms\0\0\0\0";
//  	char *s2 = "atoms\0abc";
//  	size_t size = 8;
//  	int i1 = ((strncmp(s1, s2, size) > 0) ? 1 :
//((strncmp(s1, s2, size) < 0) ? -1 : 0));
//  	int i2 = ((ft_strncmp(s1, s2, size) > 0) ?
//1 : ((ft_strncmp(s1, s2, size) < 0) ? -1 : 0));
// 	printf("%d\n%d\n",i1,i2);
// }
