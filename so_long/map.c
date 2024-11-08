/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthant <hthant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 03:10:45 by messs             #+#    #+#             */
/*   Updated: 2024/11/05 02:06:32 by hthant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_ber_file(const char *filename)
{
	const char	*extension = ".ber";
	size_t		len_filename;
	size_t		len_extension;

	len_filename = ft_strlen(filename);
	len_extension = ft_strlen(extension);
	if (len_filename >= len_extension)
	{
		if (ft_strncmp(&filename[len_filename - len_extension], extension,
				len_extension) == 0)
			return (1);
	}
	return (0);
}

int	ft_count_lines(const char *filename)
{
	int		fd;
	int		height;
	char	*line;

	height = 0;
	fd = open(filename, O_RDONLY);
	if (errno == 13)
		ft_write_error_msg("Error : No permission\n");
	if (fd < 0)
		ft_write_error_msg("Error: File not found\n");
	line = get_next_line(fd);
	while (line != NULL)
	{
		height++;
		free(line);
		line = NULL;
		line = get_next_line(fd);
	}
	close(fd);
	return (height);
}

void	get_size(t_map_data *map, int height)
{
	map->width = (ft_strlen(map->map[0]));
	map->height = height;
	if (map->height >= 22 || map->width >= 39)
	{
		free_map(map);
		ft_write_error_msg("Error: Map size is too big\n");
	}
}

void	ft_load_map(t_map_data *map, const char *filename, int height)
{
	int		fd;
	char	*line;
	int		i;

	i = 0;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		ft_write_error_msg("Error: File not found\n");
	map->map = (char **)malloc(sizeof(char *) * (height + 1));
	if (!map->map)
		ft_write_error_msg("Error: Memory allocation failed\n");
	line = get_next_line(fd);
	while (line != NULL)
	{
		if (line[ft_strlen(line) - 1] == '\n')
			line[ft_strlen(line) - 1] = '\0';
		map->map[i] = line;
		i++;
		line = get_next_line(fd);
	}
	map->map[i] = NULL;
	free(line);
	line = NULL;
	close(fd);
	get_size(map, height);
}

void	get_map_size(t_map_data *map, char **av)
{
	int	height;

	if (!is_ber_file(av[1]))
		ft_write_error_msg("Error: File is not a .ber file\n");
	height = ft_count_lines(av[1]);
	if (height < 1)
		ft_write_error_msg("Error: Invalid map height\n");
	ft_load_map(map, av[1], height);
}
