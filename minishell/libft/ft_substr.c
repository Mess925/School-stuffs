/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: messs <messs@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 16:26:52 by hthant            #+#    #+#             */
/*   Updated: 2024/12/09 18:02:38 by messs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len);

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*str;
	size_t	l;

	l = ft_strlen(s);
	if (len >= l - start)
		len = l - start;
	if (start >= l)
		len = 0;
	str = (char *)malloc(sizeof(char) * len + 1);
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (s[j])
	{
		if (j >= start && i < len)
			str[i++] = s[j];
		j++;
	}
	str[i] = 0;
	return (str);
}

// int	main(void)
// {
// 	char	*s= ft_substr("",1,1);
// 	//char	*p = substr(start,0,3);
// 	printf("%s\n",s);
// }
