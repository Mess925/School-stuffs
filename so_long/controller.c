/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controller.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: messs <messs@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 16:38:41 by messs             #+#    #+#             */
/*   Updated: 2024/10/24 17:11:56 by messs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int close_window(mlx_data *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	exit(0); // Exit the program after closing the window
}

// Function to handle key press events
int handle_keypress(int key, mlx_data *vars)
{
	if (key == 53) // 'ESC' key on macOS
	{
		close_window(vars);
	}
	return (0);
}
