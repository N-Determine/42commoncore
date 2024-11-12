/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_gamestate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeters <adeters@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 21:24:40 by adeters           #+#    #+#             */
/*   Updated: 2024/11/09 21:31:40 by adeters          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	printer_a(t_data *data, int i, int j)
{
	if (data->map.map[i][j] == 'C')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->tiles.c.img,
			j * data->tiles.c.width, i * data->tiles.c.hight);
	else if (data->map.map[i][j] == 'E')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->tiles.ec.img, j * data->tiles.ec.width, i
			* data->tiles.ec.hight);
	else if (data->map.map[i][j] == 'e')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->tiles.eo.img, j * data->tiles.eo.width, i
			* data->tiles.eo.hight);
	else if (data->map.map[i][j] == 'S')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->tiles.pd.img, j * data->tiles.pd.width, i
			* data->tiles.pd.hight);
	else if (data->map.map[i][j] == 'A')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->tiles.pl.img, j * data->tiles.pl.width, i
			* data->tiles.pl.hight);
}

static void	printer_b(t_data *data, int i, int j)
{
	if (data->map.map[i][j] == 'P')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->tiles.pr.img, j * data->tiles.pr.width, i
			* data->tiles.pr.hight);
	else if (data->map.map[i][j] == 'W')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->tiles.pu.img, j * data->tiles.pu.width, i
			* data->tiles.pu.hight);
	else if (data->map.map[i][j] == '1')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->tiles.thc.img, j * data->tiles.thc.width, i
			* data->tiles.thc.hight);
	else if (data->map.map[i][j] == '0')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->tiles.zero.img, j * data->tiles.zero.width, i
			* data->tiles.zero.hight);
}

/**
 * @brief Prints the gamestate by going through the 2D Array of the
 * map at the current gamestate and defining which tiles to print
 * on which position.
 */
void	print_gamestate(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->map.hight)
	{
		j = 0;
		while (j < data->map.width)
		{
			printer_a(data, i, j);
			printer_b(data, i, j);
			j++;
		}
		i++;
	}
}
