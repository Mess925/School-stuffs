/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthant <hthant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 11:56:36 by hthant            #+#    #+#             */
/*   Updated: 2024/06/04 21:41:04 by hthant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_split(char const *s, char c);

static size_t	ft_wordcount(char *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			while (s[i + 1] != c && s[i + 1])
				i++;
			count++;
			i++;
		}
	}
	return (count);
}

static char	*ft_wordalloc(size_t start, size_t end, char *s)
{
	size_t	size;
	char	*word;

	word = NULL;
	size = end - start;
	word = (char *)malloc((size + 1) * sizeof(char));
	if (!word)
		return (NULL);
	ft_strlcpy(word, s, size + 1);
	return (word);
}

static void	*ft_makeword(char *s, char c, size_t *i)
{
	size_t	start;
	size_t	end;

	start = 0;
	end = 0;
	while (s[*i])
	{
		if (s[*i] == c)
			(*i)++;
		else
		{
			start = *i;
			while (s[*i] && s[*i] != c)
				(*i)++;
			end = *i;
			return (ft_wordalloc(0, end - start, s + start));
		}
	}
	return (NULL);
}

static void	ft_free(char **str, size_t i)
{
	while (i > 0)
	{
		i--;
		free(str[i]);
	}
	free(str);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	size_t	size;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	size = ft_wordcount((char *)s, c);
	str = (char **)malloc((size + 1) * sizeof(char *));
	if (!str)
		return (NULL);
	while (i < size)
	{
		str[i] = ft_makeword((char *)s, c, &j);
		if (str[i] == NULL)
		{
			ft_free(str, i);
			return (NULL);
		}
		i++;
	}
	str[size] = NULL;
	return (str);
}
// int main() {

// 	char	s[] = "";
// 	char	c = 'a';
// 	char	**result = ft_split(s,c);
// 	size_t	i = 0;

// 	while (result[i]) {
// 		printf("split[%zu]: %s\n", i, result[i]);
// 		i++;
// 	}
// }
