/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeters <adeters@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 19:57:24 by adeters           #+#    #+#             */
/*   Updated: 2024/11/12 19:57:39 by adeters          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// Destroying
int	free_all(char **arr, int index)
{
	if (!arr)
		return (0);
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
	return (1);
}

void	destroy_everything(t_data *data, int loaded)
{
	if (loaded > 0)
		mlx_destroy_image(data->mlx_ptr, data->tiles.c.img);
	if (loaded > 1)
		mlx_destroy_image(data->mlx_ptr, data->tiles.ec.img);
	if (loaded > 2)
		mlx_destroy_image(data->mlx_ptr, data->tiles.eo.img);
	if (loaded > 3)
		mlx_destroy_image(data->mlx_ptr, data->tiles.pd.img);
	if (loaded > 4)
		mlx_destroy_image(data->mlx_ptr, data->tiles.pl.img);
	if (loaded > 5)
		mlx_destroy_image(data->mlx_ptr, data->tiles.pr.img);
	if (loaded > 6)
		mlx_destroy_image(data->mlx_ptr, data->tiles.pu.img);
	if (loaded > 7)
		mlx_destroy_image(data->mlx_ptr, data->tiles.thc.img);
	if (loaded > 8)
		mlx_destroy_image(data->mlx_ptr, data->tiles.zero.img);
	if (loaded == TILES)
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free_all(data->map.map, data->map.hight);
	free(data->mlx_ptr);
}
