/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   locate_pois.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeters <adeters@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 22:35:31 by adeters           #+#    #+#             */
/*   Updated: 2024/11/11 18:35:09 by adeters          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * @brief sets the coordinates for the player and 
 * increases the player count by one.
*/
static void	place_player(int *counts, t_data *data, int i, int j)
{
	data->map.pos_x = j;
	data->map.pos_y = i;
	*counts += 1;
}

/**
 * @brief sets the coordinates for the exit and increases the exit count by one.
 */
static void	place_exit(int *counts, t_data *data, int i, int j)
{
	data->map.e_pos_x = j;
	data->map.e_pos_y = i;
	*counts += 1;
}

/**
 * @brief Checks if there are too many player or exit characters in the map
 *
 * @return
 * `0` - if there are not too many player or exit characters in the map
 * `1` - if there are too many player or exit characters in the map
 */
static int	player_exit_error(int p_count, int e_count)
{
	if (p_count == 0)
	{
		error_printer(5, 0);
		return (1);
	}
	if (p_count > 1)
	{
		error_printer(6, 0);
		return (1);
	}
	if (e_count == 0)
	{
		error_printer(7, 0);
		return (1);
	}
	if (e_count > 1)
	{
		error_printer(8, 0);
		return (1);
	}
	return (0);
}

/**
 * @brief Locates points of interest by setting the coordinates of
 * the player and the exit. At the same time the amount of
 * collectables is counted.
 *
 * @return `1` - if multiple players or exits have been spotted
 *
 * `0`- if the location process was successful
 */
int	locate_pois(t_data *data)
{
	int	i;
	int	j;
	int	p_count;
	int	e_count;

	i = 0;
	p_count = 0;
	e_count = 0;
	while (i < data->map.hight)
	{
		j = 0;
		while (j < data->map.width)
		{
			if (data->map.map[i][j] == 'P')
				place_player(&p_count, data, i, j);
			if (data->map.map[i][j] == 'E')
				place_exit(&e_count, data, i, j);
			if (data->map.map[i][j] == 'C')
				data->map.colls += 1;
			j++;
		}
		i++;
	}
	return (player_exit_error(p_count, e_count));
}
