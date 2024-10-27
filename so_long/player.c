/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: messs <messs@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 02:17:48 by messs             #+#    #+#             */
/*   Updated: 2024/10/28 02:28:05 by messs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int find_player_start_x(map_data *map)
{
    int i;
    int j;

    i = 0;
    while (map->map[i])
    {
        j = 0;
        while (map->map[i][j])
        {
            if (map->map[i][j] == 'P')
                return i;
            j++;
        }
        i++;
    }
    return -1;
}

int find_player_start_y(map_data *map)
{
    int i;
    int j;
    
    i = 0;
    while (map->map[i])
    {
        j = 0;
        while (map->map[i][j])
        {
            if (map->map[i][j] == 'P')
                return j;
            j++;
        }
        i++;
    }
    return -1;
}
