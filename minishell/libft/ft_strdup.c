/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysetiawa <ysetiawa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 17:29:35 by hthant            #+#    #+#             */
/*   Updated: 2025/01/13 17:40:34 by ysetiawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strdup(const char *s);

char	*ft_strdup(const char *s)
{
	char	*str;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
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
