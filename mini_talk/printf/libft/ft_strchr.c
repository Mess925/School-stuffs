/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthant <hthant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 14:26:48 by hthant            #+#    #+#             */
/*   Updated: 2024/05/30 12:58:41 by hthant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strchr(const char *s, int c);

char	*ft_strchr(const char *s, int c)
{
	char	ch;
	int		i;

	i = 0;
	ch = (char)c;
	while (s[i])
	{
		if (s[i] == ch)
			return ((char *)(s + i));
		i++;
	}
	if (ch == '\0')
		return ((char *)(s + i));
	return (NULL);
}

// int main(void)
// {
// 	char *str1 = ft_strchr("teste",'\0');
// 	char *str2 = ft_strchr("teste",'e');
// 	char *str3 = strchr("teste",'\0');
// 	char *str4 = strchr("teste",'e');
// 	printf("%s\n%s\n%s\n%s\n",str1,str3,str2,str4);
// }

// int	main(void)
// {
// 	char *src = "there is so \0ma\0ny \0 \\0 in t\0his stri\0ng !\0\0\0\0";
//  	char *d1 = strchr(src, '\0');
//  	char *d2 = ft_strchr(src, '\0');
// 	printf("%s\n%s",d1,d2);
// }
