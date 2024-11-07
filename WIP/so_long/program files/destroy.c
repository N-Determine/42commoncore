/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeters <adeters@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 22:59:15 by adeters           #+#    #+#             */
/*   Updated: 2024/11/07 22:59:16 by adeters          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
