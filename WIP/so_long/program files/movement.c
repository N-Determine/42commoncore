/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeters <adeters@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 19:07:09 by adeters           #+#    #+#             */
/*   Updated: 2024/11/10 19:42:08 by adeters          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

/**
 * @brief Sets the movement direction for x and y coordinates.
 * 
 * Given a character representing a direction, this function updates the 
 * values pointed to by move_x and move_y to indicate movement on a 2D grid.
 * The direction char is expected to be:
 * - 'P' for right (positive x direction),
 * - 'A' for left (negative x direction),
 * - 'W' for up (negative y direction), 
 * - 'S' for down (positive y direction).
 *
 * @param move_x Pointer to an integer to set movement in the x direction.
 * @param move_y Pointer to an integer to set movement in the y direction.
 * @param dir Character representing the direction ('P', 'A', 'W', 'S').
 */
static void	set_direction(int *move_x, int *move_y, char dir)
{
	if (dir == 'P')
	{
		*move_x = 1;
		*move_y = 0;
	}
	if (dir == 'A')
	{
		*move_x = -1;
		*move_y = 0;
	}
	if (dir == 'W')
	{
		*move_x = 0;
		*move_y = -1;
	}
	if (dir == 'S')
	{
		*move_x = 0;
		*move_y = 1;
	}
}

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
	if (data->map.map[new_y][new_x] == 'E')
		return (0);
	return (1);
}

/**
 * @brief Executes player movement in the specified direction.
 * 
 * This function handles player movement on a 2D map based on the input 
 * direction. It first determines the movement offset with set_direction, 
 * then calculates the new position. If the new position is reachable, 
 * it updates the player’s position on the map, increments the step count, 
 * and checks for collectible items ('C') or the exit ('e'). If the exit is 
 * reached, the game ends.
 *
 * @param data Pointer to the game data structure.
 * @param dir Character indicating the movement direction ('P', 'A', 'W', 'S').
 */
void	handle_movement(t_data *data, char dir)
{
	int	move_x;
	int	move_y;
	int	new_x;
	int	new_y;

	set_direction(&move_x, &move_y, dir);
	new_x = move_x + data->map.pos_x;
	new_y = move_y + data->map.pos_y;
	if (is_reachable(data, new_x, new_y))
	{
		printf("Step %i\n", ++data->map.step_count);
		if (data->map.map[new_y][new_x] == 'C')
			data->map.colls_found += 1;
		if (data->map.map[new_y][new_x] == 'e')
		{
			ft_putstr_fd(WIN_MSG, 1);
			destroy_everything(data);
			exit(0);
		}
		data->map.map[data->map.pos_y][data->map.pos_x] = '0';
		data->map.map[new_y][new_x] = dir;
		data->map.pos_x += move_x;
		data->map.pos_y += move_y;
	}
}
