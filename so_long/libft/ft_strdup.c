/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthant <hthant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 17:29:35 by hthant            #+#    #+#             */
/*   Updated: 2024/05/30 17:00:53 by hthant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strdup(const char *s);

char	*ft_strdup(const char *s)
{
	char	*str;
	size_t	i;

	i = 0;
	str = (char *) malloc (sizeof(char) * ft_strlen(s) + 1);
	if (! str)
		return (NULL);
	while (s[i] != '\0' )
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

// int	main(void)
// {
// 	char	*i = ft_strdup("\0");
// 	printf("%s\n",i);
// 	char	*j = strdup("\0");
// 	printf("%s\n",j);
// }