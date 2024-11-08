/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthant <hthant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 02:15:00 by messs             #+#    #+#             */
/*   Updated: 2024/11/04 23:34:01 by hthant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	image_init(t_mlx_data *mlx, t_map_data map)
{
	mlx->images.dino_img.img = mlx_xpm_file_to_image(mlx->mlx,
			"./textures/dino.xpm", &map.width, &map.height);
	mlx->images.sheep_img.img = mlx_xpm_file_to_image(mlx->mlx,
			"./textures/sheep.xpm", &map.width, &map.height);
	mlx->images.exit_img.img = mlx_xpm_file_to_image(mlx->mlx,
			"./textures/cave.xpm", &map.width, &map.height);
	mlx->images.grass_img.img = mlx_xpm_file_to_image(mlx->mlx,
			"./textures/grass.xpm", &map.width, &map.height);
	mlx->images.wall_img.img = mlx_xpm_file_to_image(mlx->mlx,
			"./textures/wall.xpm", &map.width, &map.height);
	if (!mlx->images.dino_img.img || !mlx->images.sheep_img.img
		|| !mlx->images.exit_img.img || !mlx->images.grass_img.img
		|| !mlx->images.wall_img.img)
	{
		ft_write_error_msg("Error loading images\n");
		free_img(mlx);
		free_map(&mlx->map);
		free_mlx(mlx);
	}
	redraw_window(mlx, &map);
}
