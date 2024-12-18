/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reachability.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeters <adeters@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 19:40:47 by adeters           #+#    #+#             */
/*   Updated: 2024/12/18 20:27:28 by adeters          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	flood_fill(int i, int j, char **map, t_data *data)
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

int	check_reachability(char *map_adress, t_data *data)
{
	char	**map_dup;

	map_dup = allocate_map(data->map.width, data->map.hight);
	if (!map_dup)
		return (1);
	map_dup = fill_array(map_dup, map_adress, data->map.width, data->map.hight);
	if (!map_dup)
		return (free_all(map_dup, data->map.hight), err_pr(17, 0), 1);
	data->map.exit_reached = 0;
	data->map.colls_reached = 0;
	flood_fill(data->map.pos_y, data->map.pos_x, map_dup, data);
	data->map.colls_unreachable = data->map.colls - data->map.colls_reached;
	free_all(map_dup, data->map.hight);
	if (data->map.colls == data->map.colls_reached
		&& data->map.exit_reached == 1)
		return (0);
	return (1);
}
