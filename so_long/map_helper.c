/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_helper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthant <hthant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 01:29:25 by messs             #+#    #+#             */
/*   Updated: 2024/11/05 02:22:05 by hthant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_write_error_msg(char *str)
{
	write(1, str, ft_strlen(str));
	exit(1);
}

int	ft_count_char(const char *str, char c)
{
	int	count;

	count = 0;
	while (*str)
	{
		if (*str == c)
			count++;
		str++;
	}
	return (count);
}

void	ft_count(int player_count, int exit_count, int sheep, t_map_data *map)
{
	if (player_count != 1)
	{
		free_map(map);
		ft_write_error_msg("Error: There must be exactly 1 player in the map\n");
	}
	if (sheep <= 0)
	{
		free_map(map);
		ft_write_error_msg("Error: Need at least 1 collectible in the map\n");
	}
	if (exit_count != 1)
	{
		free_map(map);
		ft_write_error_msg("Error: There must be exactly 1 exit in the map\n");
	}
}

void	free_map(t_map_data *map)
{
	int	i;

	i = 0;
	if (map->map)
	{
		while (i < map->height)
		{
			free(map->map[i]);
			i++;
		}
		free(map->map);
		map->map = NULL;
	}
}

void	free_copy_map(t_copy__map_data *copy)
{
	int	i;

	i = 0;
	if (!copy)
		return ;
	while (i < copy->height)
	{
		free(copy->map[i]);
		i++;
	}
	free(copy->map);
	free(copy);
}
