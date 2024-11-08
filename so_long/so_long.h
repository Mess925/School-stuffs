/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthant <hthant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 15:50:43 by hthant            #+#    #+#             */
/*   Updated: 2024/11/05 02:46:01 by hthant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./get_next_line/get_next_line.h"
# include "./libft/libft.h"
# include "./mlx/mlx.h"
# include <errno.h>
# include <fcntl.h>
# include <stdio.h>

# define IMG_W 50
# define IMG_H 50
# define ESC 65307
# define KEY_D 100
# define KEY_W 119
# define KEY_S 115
# define KEY_A 97

typedef struct s_data
{
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
}					t_img_data;

typedef struct s_images
{
	t_img_data		dino_img;
	t_img_data		sheep_img;
	t_img_data		exit_img;
	t_img_data		grass_img;
	t_img_data		wall_img;
}					t_images;

typedef struct t_data
{
	char			**map;
	int				width;
	int				height;
	int				sheep;
}					t_map_data;

typedef struct s_player
{
	int				x;
	int				y;
	int				moves;
	int				collected;
}					t_player;

typedef struct s_copy__map_data
{
	char			**map;
	int				height;
	int				width;
	int				collected;
	int				exit_found;
}					t_copy__map_data;

typedef struct m_data
{
	void			*mlx;
	void			*win;
	int				window_width;
	int				window_height;
	t_images		images;
	t_player		player;
	t_map_data		map;
}					t_mlx_data;

typedef struct s_background_data
{
	void			*img;
	int				img_width;
	int				img_height;
}					t_background_data;

int					close_window(t_mlx_data *vars);
int					handle_move(int key, int *new_y, int *new_x);
void				handle_exit(t_mlx_data *mlx, int new_y, int new_x,
						int *exit);
int					handle_keypress(int key, t_mlx_data *mlx);
void				update_player(t_mlx_data *mlx, int new_y, int new_x,
						int *exit);

// map.c
int					is_ber_file(const char *filename);
int					ft_count_lines(const char *file_path);
void				ft_load_map(t_map_data *map, const char *file_path,
						int height);
void				get_map_size(t_map_data *map, char **av);
void				get_size(t_map_data *map, int height);

// check_map.c
void				ft_is_rectangular(t_map_data *map);
void				ft_check_walls(t_map_data *map, int height, int width);
void				ft_check_valid_characters(t_map_data *map, int height,
						int width);
void				ft_validate_counts(t_map_data *map);
void				ft_check_map(t_map_data *map);

// map_helper.c
void				ft_write_error_msg(char *str);
int					ft_count_char(const char *str, char c);
void				ft_count(int player_count, int exit_count, int sheep,
						t_map_data *map);
void				free_copy_map(t_copy__map_data *copy);

// is_map_valid.c
int					copy_map_content(t_copy__map_data *copy,
						char **original_map);
t_copy__map_data	*init_t_copy__map_data(int rows, int cols);
t_copy__map_data	*create_copy_map(t_map_data *original_map);
void				flood_fill(t_copy__map_data *copy, int x, int y);
int					is_map_valid(t_map_data *map, int start_x, int start_y);

// player.c
int					find_player_start_y(t_map_data *map);
int					find_player_start_x(t_map_data *map);
void				init_player(t_player *player, t_map_data *map);

// background.c
void				draw_tile(t_mlx_data *mlx, char indicator, int x, int y);
void				redraw_window(t_mlx_data *mlx, t_map_data *map);
void				ft_write(t_mlx_data *mlx);

// image_init.c
void				image_init(t_mlx_data *mlx, t_map_data map);
void				free_map(t_map_data *map);
void				free_mlx(t_mlx_data *data);
void				free_img(t_mlx_data *data);

// free
void				free_all(t_mlx_data *lee, t_map_data *mmsp);
#endif
