/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_map_valid.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: messs <messs@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 14:41:11 by messs             #+#    #+#             */
/*   Updated: 2024/10/28 15:09:19 by messs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

copy_map_data *init_copy_map_data(int height, int width)
{
    copy_map_data *copy;
    
    copy = (copy_map_data *)malloc(sizeof(copy_map_data));
    if (!copy)
        return NULL;

    copy->height = height;
    copy->width = width;
    copy->collected = 0;
    copy->exit_found = 0;  
    copy->map = (char **)malloc((height + 1) * sizeof(char *));
    
    if (!copy->map)
    {
        free(copy);
        return NULL;
    }
    return copy;
}
int copy_map_content(copy_map_data *copy, char **original_map)
{
    int i;
    
    i = 0;
    while (original_map[i])
    {
        copy->map[i] = ft_strdup(original_map[i]);
        if (!copy->map[i])
        {
            while (--i >= 0)
                free(copy->map[i]);
            free(copy->map);
            return 0;
        }
        i++;
    }
    copy->map[i] = NULL;
    return 1;
}
copy_map_data *create_copy_map(map_data *original_map)
{
    int height;
    int width;
    copy_map_data *copy;
    
    width = original_map->width / IMG_W;
    height = original_map->height / IMG_H;
    copy = init_copy_map_data(height, width);
    if (!copy)
        return NULL;
\
    if (!copy_map_content(copy, original_map->map))
    {
        free(copy->map);
        free(copy);
        return NULL;
    }
    return copy;
}


int flood_fill(copy_map_data *copy, int x, int y)
{
    if (x < 0 || y < 0 || x >= copy->height || y >= copy->width || 
        copy->map[x][y] == '1' || copy->map[x][y] == 'V')
        return 0;

    if (copy->map[x][y] == 'C')
        copy->collected++;
    else if (copy->map[x][y] == 'E')
        copy->exit_found = 1;

    copy->map[x][y] = 'V'; 

    flood_fill(copy, x + 1, y);
    flood_fill(copy, x - 1, y);
    flood_fill(copy, x, y + 1);
    flood_fill(copy, x, y - 1);

    return 0;
}

int is_map_valid(map_data *map, int start_x, int start_y)
{
    copy_map_data *map_copy;
    
    map_copy = create_copy_map(map);

    if (!map_copy)
    {
        ft_write_error_msg("Error: Memory allocation failed\n");
        return 0;
    }

    flood_fill(map_copy, start_x, start_y);

    if(map_copy->collected != map->sheep)
    {
        ft_write_error_msg("Error: Not all collectibles are reachable\n");
        return 0;
    }
    
    if (map_copy->exit_found != 1)
    {
        ft_write_error_msg("Error: Exit is not reachable\n");
        return 0;
    }
    free_copy_map(map_copy);
    return 1;
}
