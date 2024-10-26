/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: messs <messs@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 00:28:16 by messs             #+#    #+#             */
/*   Updated: 2024/10/27 02:21:11 by messs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void ft_is_rectangular(map_data *map)
{
    int first_row_length;
    int current_row_length;
    int i;

    if (map->map == NULL || map->map[0] == NULL)
        return;
    
    first_row_length = (int)(ft_strlen(map->map[0]));
    i = 1;
    
    while (map->map[i] != NULL)
    {
        current_row_length = (int)(ft_strlen(map->map[i]));
        if (current_row_length != first_row_length)
        {
            ft_putstr_fd("Error: Map is not rectangular!\n", 1);
            return;
        }
        i++;
    }
}

void ft_check_walls(map_data *map,int height, int width)
{
    int i;

    i = 0;
    while (i < width)
    {
        if (map->map[0][i] != '1' || map->map[height -  1][i] != '1')
        {
            ft_putstr_fd("Error: Map has to be surrounded by walls.\n",1);
            return;
        }
        i++;
    }
    i = 0;
    while (i < height)
    {
        if (map->map[i][0] != '1' || map->map[i][width - 1] != '1')
        {
            ft_putstr_fd("Error: Map has to be surrounded by walls.\n",1);
            return;
        }
        i++;
    }
}

void ft_check_valid_characters(map_data *map,int height, int width)
{
    int i = 0;

    while (i < height)
    {
        int j = 0;
        while (j < width)
        {
            char current = map->map[i][j];
            if (current != '0' && current != '1' && current != 'C' && 
                current != 'P' && current != 'E')
            {
                ft_putstr_fd("Error: Invalid character found in the map\n",1);
                return;
            }
            j++;
        }
        i++;
    }
}

 void ft_check_validate_counts(map_data *map)
{
    int player_count;
    int exit_count;
    int i;

    i = 0;
    exit_count = 0;
    player_count = 0;
    map->sheep = 0;

    while (map->map && map->map[i])
    {
        exit_count += ft_count_char(map->map[i], 'E');
        player_count += ft_count_char(map->map[i], 'P');
        map->sheep += ft_count_char(map->map[i], 'C'); 
        i++;
    }
    ft_count(player_count,exit_count,map->sheep);
}

void ft_check_map(map_data *map)
{
    int height;
    int width;
    
    height = map->height / IMG_H;
    width = map->width / IMG_W;
    ft_is_rectangular(map);
    ft_check_walls(map,height,width);
    ft_check_valid_characters(map,height,width);
    ft_check_validate_counts(map);
}
