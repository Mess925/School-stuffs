#ifndef SO_LONG_H
#define SO_LONG_H

#include "./mlx/mlx.h"
#include "./get_next_line/get_next_line.h"
#include <fcntl.h>

typedef struct s_data
{
	void *img;
	char *addr;
	int bits_per_pixel;
	int line_length;
	int endian;
} img_data;

typedef struct m_data
{
	void *mlx;
	void *win;
} mlx_data;

int close_window(mlx_data *vars);
int handle_keypress(int key, mlx_data *vars);

#endif
