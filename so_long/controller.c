/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controller.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthant <hthant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 15:49:42 by hthant            #+#    #+#             */
/*   Updated: 2024/11/05 02:46:20 by hthant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_window(t_mlx_data *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	vars->win = NULL;
	free_img(vars);
	free_map(&vars->map);
	free_mlx(vars);
	exit(1);
}

int	handle_move(int key, int *new_y, int *new_x)
{
	if (key == KEY_W)
	{
		(*new_y)--;
		return (1);
	}
	else if (key == KEY_S)
	{
		(*new_y)++;
		return (1);
	}
	else if (key == KEY_A)
	{
		(*new_x)--;
		return (1);
	}
	else if (key == KEY_D)
	{
		(*new_x)++;
		return (1);
	}
	return (0);
}

void	handle_exit(t_mlx_data *mlx, int new_y, int new_x, int *exit)
{
	if (mlx->map.map[new_y][new_x] == 'C')
	{
		mlx->player.collected++;
		mlx->map.map[new_y][new_x] = '0';
	}
	if (mlx->map.map[new_y][new_x] == 'E'
		&& mlx->player.collected == mlx->map.sheep)
		close_window(mlx);
	if (mlx->map.map[new_y][new_x] == 'E'
		&& mlx->player.collected != mlx->map.sheep)
	{
		(*exit) = 1;
		mlx->map.map[new_y][new_x] = 'P';
		mlx->map.map[mlx->player.y][mlx->player.x] = '0';
	}
}

void	update_player(t_mlx_data *mlx, int new_y, int new_x, int *exit)
{
	if (mlx->map.map[new_y][new_x] == '0')
	{
		if ((*exit) == 1)
		{
			mlx->map.map[mlx->player.y][mlx->player.x] = 'E';
			(*exit) = 0;
		}
		else
			mlx->map.map[mlx->player.y][mlx->player.x] = '0';
		mlx->map.map[new_y][new_x] = 'P';
	}
	mlx->player.x = new_x;
	mlx->player.y = new_y;
	mlx->player.moves++;
}

int	handle_keypress(int key, t_mlx_data *mlx)
{
	int			new_x;
	int			new_y;
	int			moved;
	static int	lee = 0;

	if (key == ESC)
	{
		mlx_destroy_window(mlx->mlx, mlx->win);
		free_all(mlx, &mlx->map);
		exit(1);
	}
	new_x = mlx->player.x;
	new_y = mlx->player.y;
	moved = handle_move(key, &new_y, &new_x);
	if (moved == 1)
	{
		if (mlx->map.map[new_y][new_x] != '1' && mlx->map.map[new_y][new_x])
		{
			ft_write(mlx);
			handle_exit(mlx, new_y, new_x, &lee);
			update_player(mlx, new_y, new_x, &lee);
			redraw_window(mlx, &mlx->map);
		}
	}
	return (0);
}
