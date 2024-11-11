#include "so_long.h"

static int flood_fill(int i, int j, char **map, t_data *data)
{
	if (map[i][j] == '1' || map[i][j] == '2')
		return (1);
	if (map[i][j] == 'C')
		data->map.colls_reached += 1;
	if (map[i][j] == 'E')
		data->map.exit_reached = 1;
	map[i][j] = '2';
	flood_fill(i + 1, j, map, data);
	flood_fill(i - 1, j, map, data);
	flood_fill(i, j + 1, map, data);
	flood_fill(i, j - 1, map, data);
	return (1);
}

int	check_reachability(t_data *data, char *map_adress)
{
	char **map_dup;

	data->map.exit_reached = 0;
	data->map.colls_reached = 0;
	map_dup = load_map(map_adress, data);
	if (!map_dup)
		return (1);
	// Flood fill on the map_dup: Turn everything reachable into a two and counts colls and exits along the way
	flood_fill(data->map.pos_y, data->map.pos_x, map_dup, data);
	free_all(map_dup, data->map.hight);
	data->map.colls_unreachable = data->map.colls - data->map.colls_reached;
	if (data->map.colls == data->map.colls_reached && data->map.exit_reached == 1)
		return (0);
	return (1);
}