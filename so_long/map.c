/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: messs <messs@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 03:10:45 by messs             #+#    #+#             */
/*   Updated: 2024/10/25 05:56:45 by messs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int is_ber_file(const char *filename)
{
    const char *extension = ".ber";
    size_t len_filename;
    size_t len_extension;

    len_filename = ft_strlen(filename);
    len_extension = ft_strlen(extension);

    if (len_filename >= len_extension)
    {
        if(ft_strncmp(&filename[len_filename - len_extension], extension, len_extension) == 0)
            return 1;
    }
    return 0;
}

int ft_count_lines(const char *filename)
{
    int fd;
    int height = 0;
    char *line;

    fd = open(filename, O_RDONLY);
    if (fd < 0)
        return -1; 
    while ((line = get_next_line(fd)) != NULL)
    {
        height++;
        free(line);
    }
    close(fd);
    return height;
}

void ft_load_map(map_data *map, const char *filename, int height)
{
    int fd;
    char *line;
    int i = 0;

    fd = open(filename, O_RDONLY);
    if (fd < 0)
        return;

    map->map = (char **)malloc(sizeof(char *) * (height + 1));
    if (!map->map)
        return;

    while ((line = get_next_line(fd)) != NULL)
    {
        if (line[ft_strlen(line) - 1] == '\n')
            line[ft_strlen(line) - 1] = '\0'; 
        map->map[i] = ft_strdup(line);
        free(line);
        i++;
    }
    map->map[i] = NULL;
    close(fd);

    map->width = (ft_strlen(map->map[0])) * IMG_W;
    map->height = height * IMG_H;
}
void get_map_size(map_data *map, char **av)
{
    int height;

    if (!is_ber_file(av[1]))
    {
        ft_putstr_fd("Error: File is not a .ber file\n", 1);
        return;
    }

    height = ft_count_lines(av[1]);
    if (height < 0)
        return;

    ft_load_map(map, av[1], height);
}

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
    ft_putstr_fd("Map is rectangular.\n", 1);
}
