/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeters <adeters@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 19:57:17 by adeters           #+#    #+#             */
/*   Updated: 2024/11/12 19:57:31 by adeters          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// Initializing
/**
 * @brief initialises the big data struct to set certain values to 0,
 * load the map and locate points of interest within the map
 */
int	data_init(t_data *data, char *map_adress)
{
	data->close_request = 0;
	data->map.colls_found = 0;
	data->map.invalid_chars = 0;
	data->map.colls = 0;
	data->map.step_count = 0;
	data->close_request = 0;
	data->map.map = load_map(map_adress, data);
	if (!data->map.map)
		return (1);
	if (locate_pois(data) != 0)
		return (free_all(data->map.map, data->map.hight), 1);
	if (data->map.colls == 0)
		return (err_pr(12, 0), free_all(data->map.map, data->map.hight), 1);
	if (data->map.invalid_chars != 0)
		return (err_pr(14, data), free_all(data->map.map, data->map.hight), 1);
	if (check_reachability(map_adress, data) != 0)
	{
		if (data->map.exit_reached == 0)
			err_pr(15, 0);
		if (data->map.colls_reached != data->map.colls)
			err_pr(16, data);
		return (free_all(data->map.map, data->map.hight), 1);
	}
	return (0);
}

int	load_tiles_a(t_data *data)
{
	data->tiles.c.img = mlx_xpm_file_to_image(data->mlx_ptr, "./img/c.xpm",
			&data->tiles.c.width, &data->tiles.c.hight);
	if (!data->tiles.c.img)
		return (0);
	data->tiles.ec.img = mlx_xpm_file_to_image(data->mlx_ptr, "./img/ec.xpm",
			&data->tiles.ec.width, &data->tiles.ec.hight);
	if (!data->tiles.ec.img)
		return (1);
	data->tiles.eo.img = mlx_xpm_file_to_image(data->mlx_ptr, "./img/eo.xpm",
			&data->tiles.eo.width, &data->tiles.eo.hight);
	if (!data->tiles.eo.img)
		return (2);
	data->tiles.pd.img = mlx_xpm_file_to_image(data->mlx_ptr, "./img/pd.xpm",
			&data->tiles.pd.width, &data->tiles.pd.hight);
	if (!data->tiles.pd.img)
		return (3);
	data->tiles.pl.img = mlx_xpm_file_to_image(data->mlx_ptr, "./img/pl.xpm",
			&data->tiles.pl.width, &data->tiles.pl.hight);
	if (!data->tiles.pl.img)
		return (4);
	return (-1);
}

int	load_tiles_b(t_data *data)
{
	data->tiles.pr.img = mlx_xpm_file_to_image(data->mlx_ptr, "./img/pr.xpm",
			&data->tiles.pr.width, &data->tiles.pr.hight);
	if (!data->tiles.pr.img)
		return (5);
	data->tiles.pu.img = mlx_xpm_file_to_image(data->mlx_ptr, "./img/pu.xpm",
			&data->tiles.pu.width, &data->tiles.pu.hight);
	if (!data->tiles.pu.img)
		return (6);
	data->tiles.thc.img = mlx_xpm_file_to_image(data->mlx_ptr, "./img/thc.xpm",
			&data->tiles.thc.width, &data->tiles.thc.hight);
	if (!data->tiles.thc.img)
		return (7);
	data->tiles.zero.img = mlx_xpm_file_to_image(data->mlx_ptr, "./img/0.xpm",
			&data->tiles.zero.width, &data->tiles.zero.hight);
	if (!data->tiles.zero.img)
		return (8);
	return (TILES);
}

/**
 * @brief Loads all the seperate images into the tiles struct
 */
int	load_tiles(t_data *data)
{
	int	checker;

	checker = load_tiles_a(data);
	if (checker != -1)
		return (checker);
	checker = load_tiles_b(data);
	if (checker != TILES)
		return (checker);
	return (TILES);
}
