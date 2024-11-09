#include "so_long.h"

/**
 * @brief sets the coordinates for the player and increases the player count by one. 
 */
static void place_player(int *counts, t_data *data, int i, int j)
{
	data->map.pos_x = j;
	data->map.pos_y = i;
	*counts += 1;
}

/**
 * @brief sets the coordinates for the exit and increases the exit count by one. 
 */
static void place_exit(int *counts, t_data *data, int i, int j)
{
	data->map.e_pos_x = j;
	data->map.e_pos_y = i;
	*counts += 1;
}

/**
 * @brief Locates points of interest by setting the coordinates of 
 * the player and the exit. At the same time the amount of 
 * collectables is counted.
 * 
 * @return `-1` - if multiple players or exits have been spotted
 * 
 * `0`- if the location process was successful
 */
int locate_pois(t_data *data)
{
	int i;
	int j;
	int p_count;
	int e_count;

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
			if (p_count > 1 || e_count > 1)
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}