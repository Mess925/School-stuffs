/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthant <hthant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 18:59:48 by hthant            #+#    #+#             */
/*   Updated: 2025/07/17 18:59:55 by hthant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./get_next_line.h"

int	ft_malloc_count(char *stock)
{
	int	i;

	i = 0;
	if (f_strchr_gnl(stock, '\n') == NULL)
		return (ft_strlen(stock));
	while (stock[i] != '\n' && stock[i] != '\0')
		i++;
	return (i + 1);
}

char	*ft_get_the_line(char *stock)
{
	char	*line;
	int		i;
	int		len;

	line = NULL;
	len = ft_malloc_count(stock);
	line = (char *)malloc(sizeof(char) * (len + 1));
	if (!line)
		return (NULL);
	i = 0;
	while (stock[i] && i < len)
	{
		line[i] = stock[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

void	ft_get_the_spare(char *buffer)
{
	int	i;
	int	j;

	i = 0;
	while (buffer[i] != '\n')
		i++;
	i = i + 1;
	j = 0;
	while (i < BUFFER_SIZE)
	{
		buffer[j] = buffer[i];
		i++;
		j++;
	}
	buffer[j] = '\0';
}

char	*ft_line_results(int ret, char *stock, char *buffer)
{
	char		*line;

	line = NULL;
	if (ft_strlen(stock) == 0)
	{
		free(stock);
		return (NULL);
	}
	line = ft_get_the_line(stock);
	if (ret > 0)
		ft_get_the_spare(buffer);
	free(stock);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*stock;
	int			ret;

	stock = NULL;
	if ((read(fd, buffer, 0) == -1) || BUFFER_SIZE <= 0)
		return (NULL);
	ret = 1;
	stock = f_strjoin_gnl(stock, buffer);
	while (f_strchr_gnl(stock, '\n') == NULL && ret > 0)
	{
		ret = read(fd, buffer, BUFFER_SIZE);
		if (ret < 0)
		{
			free(stock);
			return (NULL);
		}
		buffer[ret] = '\0';
		stock = f_strjoin_gnl(stock, buffer);
	}
	return (ft_line_results(ret, stock, buffer));
}
// #include<fcntl.h>
// #include <stdio.h>
// int	main(void)
// {
// 	int			fd;
// 	const char	*path;

// 	path = "map1.ber";
// 	// path = "test.txt";
// 	// path = "test-long.txt";
// 	printf("BUFFER_SIZE -> %i\n",BUFFER_SIZE);
// 	fd = open(path, O_RDONLY);
// 	char *res1 = get_next_line(fd);
// 	char *res2 = get_next_line(fd);
// 	char *res3 = get_next_line(fd);
// 	char *res4 = get_next_line(fd);
// 	char *res5 = get_next_line(fd);
// 	printf("res1 : %s", res1);
// 	// printf("\n-----------\n");
// 	printf("res2 : %s", res2);
// 	// printf("\n-----------\n");
// 	printf("res3 : %s", res3);
// 	// printf("\n-----------\n");
// 	printf("res4 : %s", res4);
// 	// printf("\n-----------\n");
// 	printf("res5 : %s", res5);

// 	free(res1);
// 	free(res2);
// 	free(res3);
// 	free(res4);
// 	free(res5);
// }
