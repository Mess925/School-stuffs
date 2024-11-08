/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthant <hthant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 15:05:19 by hthant            #+#    #+#             */
/*   Updated: 2024/06/11 15:22:50 by hthant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strrchr(const char *s, int c);

char	*ft_strrchr(const char *s, int c)
{
	char	ch;
	int		i;

	i = 0;
	ch = (char)c;
	while (s[i])
		i++;
	if (ch == '\0')
		return ((char *)(s + i));
	while (i >= 0 && i < c)
	{
		if (s[i] == ch)
			return ((char *)(s + i));
		i--;
	}
	return (NULL);
}

// int main(void)
// {
// 	char *str1 = ft_strrchr("teste",'\0');
// 	char *str2 = ft_strrchr("teste",'e');
// 	char *str3 = strrchr("teste",'\0');
// 	char *str4 = strrchr("teste",'e');
// 	printf("%s\n%s\n%s\n%s\n",str1,str2,str3,str4);
// }
