/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: messs <messs@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 17:16:28 by messs             #+#    #+#             */
/*   Updated: 2024/10/23 21:14:50 by messs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void    ft_print_error_msg(const char *error_msg)
{
    write(2, &error_msg ,ft_strlen(error_msg));
    write(2,"\n",1);
    exit(EXIT_FAILURE);
}

void ft_check_rectangular(window_data *window)
{
    int y;
    int expected_width;
    int expected_height;
    
    expected_width = window->width / IMG_W;
    expected_height = window->height / IMG_H;
    if (expected_width < 3 || expected_height < 3)
        ft_print_error_msg("ERROR: Map has to be at least 3x3");

    y = 0;
    while (y < (window->height / IMG_H))
    {
        if ((int)(ft_strlen)(window->map->map[y]) != expected_width)
            ft_print_error_msg("ERROR: Map has to be rectangular");
        y++;
    }
}

void    ft_check_border(window_data *window)
{
    int x;
    int y;

    y = 0;
    while (y < (window->height / IMG_H))
    {
        x = 0;
        while (x < (window->width / IMG_W))
        {
            if(window->map->map[y][x] != '0' && window->map->map[y][x] != '1' && 
            window->map->map[y][x] != 'C' && window->map->map[y][x] != 'P' &&
            window->map->map[y][x] != 'E')
                ft_print_error_msg("ERROR : Only '0' '1' 'C' 'P' 'E' are valid on the map");
            else if ((y == 0 || x == 0) && window->map->map[y][x] != '1')
				ft_print_error_msg("Error : Map has to be surrounded by walls.");
            else if ((y == ((window->height / IMG_H) - 1)
					|| x == ((window->width / IMG_W) - 1))
				&& window->map->map[y][x] != '1')
				ft_print_error_msg("Error : Map has to be surrounded by walls");
            x++;
        }
        y++;
    }
}

void    ft_check_contents(window_data *window)
{
    int y;
    int exit;
    int player;

    y = 0;
    exit = 0;
    player = 0;
    window->map->sheeps = 0;
    while (window->map->map && window->map->map[y])
    {
        exit += ft_count_c(window->map->map[y],'E');
        player += ft_count_c(window->map->map[y],'P');
        window->map->sheeps += ft_count_c(window->map->map[y],'C');
        y++;
    }
    if (player != 1)
		ft_print_error_msg("Error: Need at least one player.");
	if (exit != 1)
		ft_print_error_msg("Error: Need at least one exit.");
	if (window->map->sheeps == 0)
		ft_print_error_msg("Error: Need at least one collectiable point.");
}

void ft_check_map(window_data *window)
{
    ft_check_rectangular(window);
    ft_check_border(window);
    ft_check_contents(window);
}


