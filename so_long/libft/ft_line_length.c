/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_line_length.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: messs <messs@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 15:42:17 by tblaase           #+#    #+#             */
/*   Updated: 2024/10/23 20:25:08 by messs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include "libft.h"

int	ft_line_length(int fd)
/* this function will find the length of the first line in a file */
{
	char	*line;
	int		length;

	// Get the first line of the file using get_next_line (or similar)
	line = get_next_line(fd);

	// If line is NULL, return 0 (no content or error)
	if (!line)
		return (0);

	// Calculate the length of the line
	length = ft_strlen(line);

	// Free the line after calculating the length
	free(line);

	return (length);
}

