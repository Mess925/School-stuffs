#include <stdio.h>
#include "../so_long.h"

int main(int ac, char **av)
{
	map_data map;
	int start_x;
	int start_y;

	if (ac != 2)
		return 0;
	get_map_size(&map,av);
	ft_check_map(&map);
    start_x = find_player_start_x(&map);
    start_y = find_player_start_y(&map);
    if (!is_map_valid(&map, start_x, start_y))
		ft_write_error_msg("Error: Map has unreachable items or exit\n");
	else
		printf("map is valid\n");
	
	free_map(map.map);

    return 0;
}