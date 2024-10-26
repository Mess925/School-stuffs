#include <stdio.h>
#include "../so_long.h"

int main(int ac, char **av)
{
	map_data map;

	if (ac != 2)
		return 0;
	get_map_size(&map,av);
	ft_check_map(&map);
	return 0;
}