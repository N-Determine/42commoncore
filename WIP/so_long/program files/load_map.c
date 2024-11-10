/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeters <adeters@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 15:45:58 by adeters           #+#    #+#             */
/*   Updated: 2024/11/10 20:46:51 by adeters          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft.h"
#include "get_next_line.h"
#include <stdio.h>

/*
int is_valid_char(char c)
{
	int valid; 

	valid = 0;
	if (c == 'C' || c == 'E' || c == 'P')
		valid = 1;
	if (c == '1' || c == '0')
		valid = 1;
	return (valid);
}

int is_valid_str(char *str)
{
	int i;

	i = 0;
	while(str[i])
	{
		if (!is_valid_char(str[i]))
			return (0);
		i++;
	}
	return (1);
}
*/

/**
 * @brief Removes the newline character (`\n`) from the end of a string, if present.
 *        This allows `count_lines` to function correctly regardless of whether the
 *        map file ends with a newline character.
 *
 * @param str The string from which to remove the newline character.
 * 
 * @return A pointer to the modified string with any trailing newline replaced by `\0`.
 */
char	*rid_of_nl(char *str)
{
	int i;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i])
	{
		if (str[i] == '\n')
			str[i] = '\0';
		i++;
	}
	return (str);
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
	char *line;
	int fd;
	fd = open(map_adress, O_RDONLY);
	if (fd < 0)
		return (10);
	line = rid_of_nl(get_next_line(fd));
	if (!line)
		return (1);
	int last = ft_strlen(line);
	*width = last;
	*hight = 1;
	while (line)
	{
		free(line);
		line = rid_of_nl(get_next_line(fd));
		if (!line)
			break;
		if (last != ft_strlen(line))
			return (2);
		*hight += 1;
	}
	close(fd);
	free(line);
	return (0);
}

char **allocate_map(width, hight)
{
	char **arr = malloc(sizeof(char *) * hight);
	if (!arr)
		return (NULL);
	int i = 0;
	while (i < hight)
	{
		arr[i] = malloc(sizeof(char) * width);
		if (!arr[i])
			return (free_all(arr, i), NULL);
		i++;
	}
	return (arr);
}

char **fill_array(char **arr, char *map_adress, int width, int hight)
{
	int		fd;
	int		i;
	int		j;
	char	*line;

	fd = open(map_adress, O_RDONLY);
	j = 0;
	i = 0;
	while (i < hight)
	{
		if (i > 0)
			free(line);
		line = rid_of_nl(get_next_line(fd));
		if (!line)
			return (get_next_line(-1), close(fd), NULL);
		j = 0;
		while (j < width)
		{
			arr[i][j] = line[j];
			j++;
		}
		i++;
	}
	get_next_line(-1);
	free(line);
	close(fd);
	return (arr);
	
}


int	check_border(char **arr, t_data *data)
{
	int i = 0;
	int j = 0;
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
			j++;
		}
		i++;
	}
	return (0);
}

char	**load_map(char *map_adress, t_data *data)
{
	char	**arr;
	int		code;

	code = check_map_dimensions(map_adress, &data->map.width, &data->map.hight);
	if(code != 0)
		return (error_printer(code), NULL);
	arr = allocate_map(data->map.width, data->map.hight);
	if (!arr)
		return (error_printer(3), NULL);
	arr = fill_array(arr, map_adress, data->map.width, data->map.hight);
	if (!arr)
		return (free_all(arr, data->map.hight), error_printer(4), NULL);
	if (check_border(arr, data) != 0)
		return (free_all(arr, data->map.hight), error_printer(11), NULL);
	return (arr);
}
