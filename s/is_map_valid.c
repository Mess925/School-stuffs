/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_map_valid.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthant <hthant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 14:41:11 by messs             #+#    #+#             */
/*   Updated: 2024/11/04 23:09:40 by hthant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_copy__map_data	*init_t_copy__map_data(int height, int width)
{
	t_copy__map_data	*copy;

	copy = (t_copy__map_data *)malloc(sizeof(t_copy__map_data));
	if (!copy)
		return (NULL);
	copy->height = height;
	copy->width = width;
	copy->collected = 0;
	copy->exit_found = 0;
	copy->map = (char **)malloc((height + 1) * sizeof(char *));
	if (!copy->map)
	{
		free(copy);
		return (NULL);
	}
	return (copy);
}

int	copy_map_content(t_copy__map_data *copy, char **original_map)
{
	int	i;

	i = 0;
	while (original_map[i])
	{
		copy->map[i] = ft_strdup(original_map[i]);
		if (!copy->map[i])
		{
			while (--i >= 0)
				free(copy->map[i]);
			free(copy->map);
			return (0);
		}
		i++;
	}
	copy->map[i] = NULL;
	return (1);
}

t_copy__map_data	*create_copy_map(t_map_data *original_map)
{
	int					height;
	int					width;
	t_copy__map_data	*copy;

	width = original_map->width;
	height = original_map->height;
	copy = init_t_copy__map_data(height, width);
	if (!copy)
		return (NULL);
	if (!copy_map_content(copy, original_map->map))
	{
		free(copy->map);
		free(copy);
		return (NULL);
	}
	return (copy);
}

void	flood_fill(t_copy__map_data *copy, int x, int y)
{
	if (x < 0 || y < 0 || y >= copy->height || x >= copy->width
		|| copy->map[y][x] == '1' || copy->map[y][x] == 'R')
		return ;
	if (copy->map[y][x] == 'C')
		copy->collected++;
	if (copy->map[y][x] == 'E')
		copy->exit_found = 1;
	copy->map[y][x] = 'R';
	flood_fill(copy, x + 1, y);
	flood_fill(copy, x - 1, y);
	flood_fill(copy, x, y + 1);
	flood_fill(copy, x, y - 1);
}

int	is_map_valid(t_map_data *map, int start_x, int start_y)
{
	t_copy__map_data	*map_copy;

	map_copy = create_copy_map(map);
	if (!map_copy)
	{
		free_copy_map(map_copy);
		free_map(map);
		ft_write_error_msg("Error: Memory allocation failed\n");
	}
	flood_fill(map_copy, start_x, start_y);
	if (map_copy->collected != map->sheep)
	{
		free_copy_map(map_copy);
		free_map(map);
		ft_write_error_msg("Error: Not all collectibles are reachable\n");
	}
	if (map_copy->exit_found != 1)
	{
		free_copy_map(map_copy);
		free_map(map);
		ft_write_error_msg("Error: Exit is not reachable\n");
	}
	free_copy_map(map_copy);
	return (1);
}
