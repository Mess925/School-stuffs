/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthant <hthant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 15:50:10 by hthant            #+#    #+#             */
/*   Updated: 2024/11/05 02:42:45 by hthant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	free_img(t_mlx_data *data)
{
	if (data->images.dino_img.img)
		mlx_destroy_image(data->mlx, data->images.dino_img.img);
	if (data->images.sheep_img.img)
		mlx_destroy_image(data->mlx, data->images.sheep_img.img);
	if (data->images.wall_img.img)
		mlx_destroy_image(data->mlx, data->images.wall_img.img);
	if (data->images.grass_img.img)
		mlx_destroy_image(data->mlx, data->images.grass_img.img);
	if (data->images.exit_img.img)
		mlx_destroy_image(data->mlx, data->images.exit_img.img);
	data->images.dino_img.img = NULL;
	data->images.sheep_img.img = NULL;
	data->images.wall_img.img = NULL;
	data->images.grass_img.img = NULL;
	data->images.exit_img.img = NULL;
}

void	free_mlx(t_mlx_data *data)
{
	if (data->mlx)
	{
		mlx_destroy_display(data->mlx);
		free(data->mlx);
		data->mlx = NULL;
	}
}

void	free_all(t_mlx_data *mlx, t_map_data *map)
{
	free_img(mlx);
	free_map(map);
	free_mlx(mlx);
}

int	main(int ac, char **av)
{
	t_map_data	map;
	t_mlx_data	mlx;
	t_player	player;

	if (ac != 2)
		return (0);
	get_map_size(&map, av);
	ft_check_map(&map);
	init_player(&player, &map);
	is_map_valid(&map, player.x, player.y);
	mlx.player = player;
	mlx.map = map;
	mlx.player.moves = 1;
	mlx.player.collected = 0;
	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, map.width * IMG_W, map.height * IMG_H,
			"So long");
	if (!mlx.mlx || !mlx.win)
		ft_write_error_msg("Error initializing MLX or creating window\n");
	image_init(&mlx, map);
	mlx_hook(mlx.win, 17, 1L << 17, close_window, &mlx);
	mlx_hook(mlx.win, 2, 1L << 0, handle_keypress, &mlx);
	mlx_loop(mlx.mlx);
	free_all(&mlx, &map);
	return (0);
}
