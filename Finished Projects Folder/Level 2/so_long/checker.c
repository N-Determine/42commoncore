/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeters <adeters@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 19:39:26 by adeters           #+#    #+#             */
/*   Updated: 2024/11/12 16:02:32 by adeters          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_valid_char(char c)
{
	int	valid;

	valid = 0;
	if (c == 'C' || c == 'E' || c == 'P')
		valid = 1;
	if (c == '1' || c == '0')
		valid = 1;
	return (valid);
}

/**
 * @brief Checks the dimensions of the map and if the map is rectangular
 *
 * @return
 * `0` - if the operation was succesful
 *
 * `1`- if the get_next_line function failes (e.g. failed read function)
 *
 * `2`- if the map is not rectangular
 */
int	check_map_dimensions(char *map_adress, int *width, int *hight)
{
	char	*line;
	int		fd;
	int		last;

	fd = open(map_adress, O_RDONLY);
	if (fd < 0)
		return (10);
	line = rid_of_nl(get_next_line(fd));
	if (!line)
		return (1);
	last = ft_strlen(line);
	*width = last;
	*hight = 1;
	while (line)
	{
		free(line);
		line = rid_of_nl(get_next_line(fd));
		if (!line)
			break ;
		if (last != ft_strlen(line))
			return (get_next_line(-1), free(line), 2);
		*hight += 1;
	}
	return (get_next_line(-1), close(fd), free(line), 0);
}

int	check_border(char **arr, t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < data->map.hight)
	{
		j = 0;
		while (j < data->map.width)
		{
			if (i == 0 && arr[i][j] != '1')
				return (1);
			if (i == data->map.hight - 1 && arr[i][j] != '1')
				return (1);
			if (j == 0 && arr[i][j] != '1')
				return (1);
			if (j == data->map.width - 1 && arr[i][j] != '1')
				return (1);
			if (!is_valid_char(arr[i][j]))
				data->map.invalid_chars += 1;
			j++;
		}
		i++;
	}
	return (0);
}
