/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   background.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthant <hthant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 02:16:08 by messs             #+#    #+#             */
/*   Updated: 2024/11/05 02:45:51 by hthant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_tile(t_mlx_data *mlx, char indicator, int x, int y)
{
	if (indicator == 'P' && mlx->images.dino_img.img)
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->images.dino_img.img, x
			* IMG_W, y * IMG_H);
	else if (indicator == 'C' && mlx->images.sheep_img.img)
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->images.sheep_img.img, x
			* IMG_W, y * IMG_H);
	else if (indicator == 'E' && mlx->images.exit_img.img)
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->images.exit_img.img, x
			* IMG_W, y * IMG_H);
	else if (indicator == '1' && mlx->images.wall_img.img)
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->images.wall_img.img, x
			* IMG_W, y * IMG_H);
	else if (indicator == '0' && mlx->images.grass_img.img)
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->images.grass_img.img, x
			* IMG_W, y * IMG_H);
}

void	redraw_window(t_mlx_data *mlx, t_map_data *map)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->height && map->map[y] && mlx->mlx)
	{
		x = 0;
		while (x < map->width && map->map[y][x])
		{
			draw_tile(mlx, map->map[y][x], x, y);
			x++;
		}
		y++;
	}
}

void	ft_write(t_mlx_data *mlx)
{
	ft_putstr_fd("Move :", 1);
	ft_putnbr_fd(mlx->player.moves, 1);
	ft_putchar_fd('\n', 1);
}
