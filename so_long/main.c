// #include <stdio.h>
// #include "../so_long.h"

// int main(void)
// {
// 	mlx_data mlx;
// 	img_data dino_img, wall_img, cave_img, sheep_img;
// 	int width = 25;
// 	int height = 25;

// 	mlx.mlx = mlx_init();
// 	mlx.win = mlx_new_window(mlx.mlx, 700, 640, "My Window");
// 	if (!mlx.mlx || !mlx.win)
// 	{
// 		printf("Error initializing MLX or creating window\n");
// 		return (1);
// 	}

// 	// Load the Dino image
// 	dino_img.img = mlx_xpm_file_to_image(mlx.mlx, "./images/dino.xpm", &width, &height);
// 	if (!dino_img.img)
// 	{
// 		printf("Error loading image dino.xpm\n");
// 		return (1);
// 	}
// 	mlx_put_image_to_window(mlx.mlx, mlx.win, dino_img.img, 0, 0);

// 	// Load the Wall image
// 	wall_img.img = mlx_xpm_file_to_image(mlx.mlx, "./images/wall.xpm", &width, &height);
// 	if (!wall_img.img)
// 	{
// 		printf("Error loading image wall.xpm\n");
// 		return (1);
// 	}
// 	mlx_put_image_to_window(mlx.mlx, mlx.win, wall_img.img, 50, 0);

// 	// Load the Cave image
// 	cave_img.img = mlx_xpm_file_to_image(mlx.mlx, "./images/cave.xpm", &width, &height);
// 	if (!cave_img.img)
// 	{
// 		printf("Error loading image cave.xpm\n");
// 		return (1);
// 	}
// 	mlx_put_image_to_window(mlx.mlx, mlx.win, cave_img.img, 100, 0);

// 	// Load the Sheep image
// 	sheep_img.img = mlx_xpm_file_to_image(mlx.mlx, "./images/sheep.xpm", &width, &height);
// 	if (!sheep_img.img)
// 	{
// 		printf("Error loading image sheep.xpm\n");
// 		return (1);
// 	}
// 	mlx_put_image_to_window(mlx.mlx, mlx.win, sheep_img.img, 150, 0);

// 	// Hook to handle key presses and close window
// 	// mlx_hook(mlx.win, 2, 1L << 0, handle_keypress, &mlx);

// 	// Hook to handle window close event (clicking the close button)
// 	mlx_hook(mlx.win, 17, 0, close_window, &mlx);

// 	// Start the MLX loop
// 	mlx_loop(mlx.mlx);
// }

#include <stdio.h>
#include "so_long.h"

void print_map(window_data *window)
{
	int i = 0;
	while ( i < window->height / IMG_H)
	{
		printf("%s\n", window->map->map[i]);
		i++;
	}
}

int main(int argc, char **argv)
{
    window_data window;
    map_data map_data;

    window.map = &map_data;

    // Load the map from the .ber file into the array
    ft_ber_to_array(&window, argc, argv);

    // Print the map to verify if it's loaded correctly
    print_map(&window);

    // Free the allocated memory
	int i = 0;
	while ( i < window.height / IMG_H)
	{
		free(window.map->map[i]);
		i++;
	}
    free(window.map->map);

    return (0);
}

