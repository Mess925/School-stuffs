#ifndef SO_LONG_H
#define SO_LONG_H

#include "./mlx/mlx.h"
#include "./libft/libft.h"
#include "./get_next_line/get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

typedef struct s_data
{
	void *img;
	char *addr;
	int bits_per_pixel;
	int line_length;
	int endian;
} img_data;

typedef struct t_data
{
	char **map;
	int	width;
	int height;
} map_data;


typedef struct m_data
{
	void *mlx;
	void *win;
} mlx_data;

#define IMG_W 32;
#define IMG_H 32;

int close_window(mlx_data *vars);
int handle_keypress(int key, mlx_data *vars);

// map.c
int is_ber_file(const char *filename);
int ft_count_lines(const char *file_path);
void ft_load_map(map_data *map, const char *file_path, int height);
void get_map_size(map_data *map, char **av);
void ft_is_rectangular(map_data *map);


#endif
