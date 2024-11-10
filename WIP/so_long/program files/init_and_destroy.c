/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_and_destroy.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeters <adeters@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 22:59:15 by adeters           #+#    #+#             */
/*   Updated: 2024/11/10 21:18:59 by adeters          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

// Initializing
/**
 * @brief initialises the big data struct to set certain values to 0,
 * load the map and locate points of interest within the map
 */
int	data_init(t_data *data, char *map_adress)
{
	data->close_request = 0;
	data->map.colls_found = 0;
	data->map.free_flag = 0;
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
	{
		error_printer(12);
		return (free_all(data->map.map, data->map.hight), 1);
	}
	if (data->map.free_flag == 0)
	{
		error_printer(13);
		return (free_all(data->map.map, data->map.hight), 1);
	}
	if (data->map.invalid_chars != 0)
	{
		error_printer(14);
		return (free_all(data->map.map, data->map.hight), 1);
	}
	return (0);
}

/**
 * @brief Loads all the seperate images into the tiles struct
 */
int	load_tiles(t_data *data)
{
	data->tiles.c.img = mlx_xpm_file_to_image(data->mlx_ptr, "../img/c.xpm",
			&data->tiles.c.width, &data->tiles.c.hight);
	data->tiles.ec.img = mlx_xpm_file_to_image(data->mlx_ptr, "../img/ec.xpm",
			&data->tiles.ec.width, &data->tiles.ec.hight);
	data->tiles.eo.img = mlx_xpm_file_to_image(data->mlx_ptr, "../img/eo.xpm",
			&data->tiles.eo.width, &data->tiles.eo.hight);
	data->tiles.pd.img = mlx_xpm_file_to_image(data->mlx_ptr, "../img/pd.xpm",
			&data->tiles.pd.width, &data->tiles.pd.hight);
	data->tiles.pl.img = mlx_xpm_file_to_image(data->mlx_ptr, "../img/pl.xpm",
			&data->tiles.pl.width, &data->tiles.pl.hight);
	data->tiles.pr.img = mlx_xpm_file_to_image(data->mlx_ptr, "../img/pr.xpm",
			&data->tiles.pr.width, &data->tiles.pr.hight);
	data->tiles.pu.img = mlx_xpm_file_to_image(data->mlx_ptr, "../img/pu.xpm",
			&data->tiles.pu.width, &data->tiles.pu.hight);
	data->tiles.thc.img = mlx_xpm_file_to_image(data->mlx_ptr, "../img/thc.xpm",
			&data->tiles.thc.width, &data->tiles.thc.hight);
	data->tiles.zero.img = mlx_xpm_file_to_image(data->mlx_ptr, "../img/0.xpm",
			&data->tiles.zero.width, &data->tiles.zero.hight);
	if (!data->tiles.c.img || !data->tiles.ec.img || !data->tiles.eo.img)
		return (-1);
	if (!data->tiles.pd.img || !data->tiles.pl.img || !data->tiles.pr.img)
		return (-1);
	if (!data->tiles.thc.img || !data->tiles.pu.img)
		return (-1);
	return (1);
}

// Destroying
void	free_all(char **arr, int index)
{
	if (index != 0)
	{
		index = index - 1;
		while (index >= 0)
		{
			free(arr[index]);
			index--;
		}
		free(arr);
	}
	else
	{
		free(arr[0]);
		free(arr);
	}
}

void	destroy_everything(t_data *data)
{
	mlx_destroy_image(data->mlx_ptr, data->tiles.c.img);
	mlx_destroy_image(data->mlx_ptr, data->tiles.ec.img);
	mlx_destroy_image(data->mlx_ptr, data->tiles.eo.img);
	mlx_destroy_image(data->mlx_ptr, data->tiles.pd.img);
	mlx_destroy_image(data->mlx_ptr, data->tiles.pl.img);
	mlx_destroy_image(data->mlx_ptr, data->tiles.pr.img);
	mlx_destroy_image(data->mlx_ptr, data->tiles.pu.img);
	mlx_destroy_image(data->mlx_ptr, data->tiles.thc.img);
	mlx_destroy_image(data->mlx_ptr, data->tiles.zero.img);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free_all(data->map.map, data->map.hight);
	free(data->mlx_ptr);
}
