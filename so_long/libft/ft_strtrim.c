/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthant <hthant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 17:00:36 by hthant            #+#    #+#             */
/*   Updated: 2024/06/06 21:45:52 by hthant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	check_char(char c, char const *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (c == s[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *s2);

char	*ft_strtrim(char const *s1, char const *s2)
{
	char	*str;
	size_t	start;
	size_t	end;
	size_t	i;

	start = 0;
	end = ft_strlen (s1);
	while (s1[start] && check_char(s1[start], s2))
		start++;
	while (end > start && check_char(s1[end - 1], s2))
		end--;
	str = (char *)malloc(sizeof(char) * (end - start) + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (start < end)
		str[i++] = s1[start++];
	str[i] = '\0';
	return (str);
}
// int main(void)
// {
//     char p[] = "ssoooss     hello  hello      oosososososo";
//     char q[] = "so";
//     char *r = ft_strtrim(p,q);
//     printf("%s\n",r);
// }
