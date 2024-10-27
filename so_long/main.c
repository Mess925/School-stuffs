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
    if (!is_reachable(&map, start_x, start_y))
	{
        ft_write_error_msg("Error: Collectibles are not reachable from the starting position.\n");
        ft_write_error_msg("Error: Exit is not reachable from the starting position.\n");
	}

    // free_map(map.map);

    return 0;
}