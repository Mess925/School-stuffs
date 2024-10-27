#ifndef SO_LONG_H
#define SO_LONG_H

#include "./mlx/mlx.h"
#include "./libft/libft.h"
#include "./get_next_line/get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

#define IMG_W 32
#define IMG_H 32

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
	int sheep;
} map_data;


typedef struct m_data
{
	void *mlx;
	void *win;
} mlx_data;

int close_window(mlx_data *vars);
int handle_keypress(int key, mlx_data *vars);

// map.c
int is_ber_file(const char *filename);
int ft_count_lines(const char *file_path);
void ft_load_map(map_data *map, const char *file_path, int height);
void get_map_size(map_data *map, char **av);
void get_size(map_data *map, int height);

// check_map.c
void ft_is_rectangular(map_data *map);
void ft_check_walls(map_data *map,int height,int width);
void ft_check_valid_characters(map_data *map,int height,int width);
void ft_validate_counts(map_data *map);
void ft_check_map(map_data *map);

// map_helper.c
void ft_write_error_msg(char *str);
int ft_count_char(const char *str, char c);
void ft_count(int player_count, int exit_count ,int sheep);

// flood_fill.c
char **copy_map(map_data *map);
int **create_visited(int rows, int cols);
void free_visited(int **visited, int rows);
int flood_fill(map_data *map, char **map_copy, int x, int y, int **visited);
int is_reachable(map_data *map, int start_x, int start_y);

// player.c
int find_player_start_y(map_data *map);
int find_player_start_x(map_data *map);

#endif
