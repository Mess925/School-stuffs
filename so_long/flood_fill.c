/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: messs <messs@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 01:50:42 by messs             #+#    #+#             */
/*   Updated: 2024/10/28 02:49:48 by messs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char **copy_map(map_data *map)
{
    char **copy = (char **)malloc((map->height / IMG_H + 1) * sizeof(char *));
    int i = 0;

    if (!copy)
        return NULL;

    while (map->map[i])
    {
        copy[i] = ft_strdup(map->map[i]);
        if (!copy[i])
        {
            while (--i >= 0)
                free(copy[i]);
            free(copy);
            return NULL;
        }
        i++;
    }
    copy[i] = NULL;
    return copy;
}

int **create_visited(int rows, int cols)
{
    int **visited;
    int i;
    int j;

    visited = (int **)malloc(rows * sizeof(int *));

    if (!visited)
        return NULL;

    i = 0;
    while (i < rows)
    {
        visited[i] = (int *)malloc(cols * sizeof(int));
        if (!visited[i])
            return NULL;
        j = 0;
        while (j < cols)
        {
            visited[i][j] = 0;
            j++;
        }
        i++;
    }
    return visited;
}

void free_visited(int **visited, int rows)
{
    int i;
    
    i = 0;
    while (i < rows)
    {
        free(visited[i]);
        i++;
    }
    free(visited);
}

int flood_fill(map_data *map, char **map_copy, int x, int y, int **visited)
{
    if (x < 0 || y < 0 || x >= map->height / IMG_H || y >= map->width / IMG_W)
        return 0;
    if (visited[x][y] || map_copy[x][y] == '1')
        return 0;

    visited[x][y] = 1;

    if (map_copy[x][y] == 'C' || map_copy[x][y] == 'E')
        return 1;

    return flood_fill(map, map_copy, x + 1, y, visited) ||
           flood_fill(map, map_copy, x - 1, y, visited) ||
           flood_fill(map, map_copy, x, y + 1, visited) ||
           flood_fill(map, map_copy, x, y - 1, visited);
}

int is_reachable(map_data *map, int start_x, int start_y)
{
    char **map_copy;
    int **visited;
    int reachable;
    int i;

    i = 0;
    map_copy = copy_map(map);
    visited = create_visited(map->height / IMG_H, map->width / IMG_W);
    if (!map_copy || !visited) {
        ft_write_error_msg("Error: Memory allocation failed for visited array or map copy\n");
        return 0;
    }

    reachable = flood_fill(map, map_copy, start_x, start_y, visited);
    free_visited(visited, map->height / IMG_H);

    while(map_copy[i])
    {
        free(map_copy[i]);
        i++;
    }
    free(map_copy);

    return reachable;
}
