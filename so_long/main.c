#include <stdio.h>
#include "../so_long.h"

int main(int ac, char **av)
{
	map_data map;
	if (ac != 2)
		return 0;
	
	get_map_size(&map,av);
	ft_is_rectangular(&map);
	ft_is_valid(&map);
	return 0;
}