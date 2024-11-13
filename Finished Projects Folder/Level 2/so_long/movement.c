/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeters <adeters@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 19:07:09 by adeters           #+#    #+#             */
/*   Updated: 2024/11/13 15:21:42 by adeters          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * @brief Checks if the new coordinates are reachable.
 *
 * This function checks if the target position on the map is accessible
 * by verifying that it is neither a wall ('1') nor an exit ('E').
 *
 * @param data Pointer to the game data structure containing the map.
 * @param new_x Target x-coordinate for the movement.
 * @param new_y Target y-coordinate for the movement.
 *
 * @return 1 if the position is reachable,
 * 0 if it's blocked by a wall or (closed) exit.
 */
static int	is_reachable(t_data *data, int new_x, int new_y)
{
	if (data->map.map[new_y][new_x] == '1')
		return (0);
	return (1);
}

void	print_steps(t_data *data)
{
	ft_putstr_fd("Step ", 1);
	ft_putnbr_fd(++data->map.step_count, 1);
	ft_putstr_fd("\n", 1);
}

void	handle_movement(t_data *data, char dir, int move_x, int move_y)
{
	int	new_x;
	int	new_y;

	new_x = move_x + data->map.pos_x;
	new_y = move_y + data->map.pos_y;
	if (is_reachable(data, new_x, new_y))
	{
		print_steps(data);
		if (data->map.map[new_y][new_x] == 'C')
			data->map.colls_found += 1;
		if (data->map.map[new_y][new_x] == 'e')
		{
			ft_putstr_fd(WIN_MSG, 1);
			destroy_everything(data, TILES);
			exit(0);
		}
		if (data->map.pos_y == data->map.e_pos_y
			&& data->map.pos_x == data->map.e_pos_x)
			data->map.map[data->map.pos_y][data->map.pos_x] = 'E';
		else
			data->map.map[data->map.pos_y][data->map.pos_x] = '0';
		data->map.map[new_y][new_x] = dir;
		data->map.pos_x += move_x;
		data->map.pos_y += move_y;
	}
}
