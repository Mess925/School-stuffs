#ifndef SO_LONG_H
#define SO_LONG_H

#include "./mlx/mlx.h"
#include "./libft/libft.h"
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

#define IMG_W 32
#define IMG_H 32
#define ESC 53

typedef struct s_map
{
	char	**map;
	void	*object;
	int		x;
	int		y;
	int		sheeps;
}map_data;

typedef struct s_data
{
	void *img;
	char *addr;
	int bits_per_pixel;
	int line_length;
	int endian;
} img_data;

typedef struct s_window
{
	int	width;
	int	height;
	map_data *map;
}window_data;

typedef struct m_data
{
	void *mlx;
	void *win;

	img_data *img;
} mlx_data;

int close_window(mlx_data *vars);
int handle_keypress(int key, mlx_data *vars);

// map.c
void	ft_input_error(int	argc);
int is_ber_file(const char *filename);
void    get_window_size(window_data *window, char **av);
void	read_lines_to_map(window_data *window, int fd, char **map);
void	ft_ber_to_array(window_data *window, int argc, char **argv);

// map_checks
void	ft_check_border(window_data *window);
void    ft_check_map(window_data *window);
void	ft_check_rectangular(window_data *window);
void    ft_print_error_msg(const char *error_msg);
void    ft_check_contents(window_data *window);

#endif
