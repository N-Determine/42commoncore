/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeters <adeters@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 15:45:58 by adeters           #+#    #+#             */
/*   Updated: 2024/11/11 19:57:59 by adeters          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * @brief Removes the newline character (`\n`) from the end of a string,
 * if present.
 *        This allows `count_lines` to function
 * correctly regardless of whether the
 *        map file ends with a newline character.
 *
 * @param str The string from which to remove
 * the newline character.
 *
 * @return A pointer to the modified string with any
 * trailing newline replaced by `\0`.
 */
char	*rid_of_nl(char *str)
{
	int	i;

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

char	**allocate_map(width, hight)
{
	char	**arr;
	int		i;

	arr = malloc(sizeof(char *) * hight);
	if (!arr)
		return (NULL);
	i = 0;
	while (i < hight)
	{
		arr[i] = malloc(sizeof(char) * width);
		if (!arr[i])
			return (free_all(arr, i), NULL);
		i++;
	}
	return (arr);
}

char	**fill_array(char **arr, char *map_adress, int width, int hight)
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
		j = -1;
		while (++j < width)
			arr[i][j] = line[j];
		i++;
	}
	get_next_line(-1);
	free(line);
	close(fd);
	return (arr);
}

char	**load_map(char *map_adress, t_data *data)
{
	char	**arr;
	int		code;

	code = check_map_dimensions(map_adress, &data->map.width, &data->map.hight);
	if (code != 0)
		return (err_pr2(code), NULL);
	arr = allocate_map(data->map.width, data->map.hight);
	if (!arr)
		return (err_pr2(3), NULL);
	arr = fill_array(arr, map_adress, data->map.width, data->map.hight);
	if (!arr)
		return (free_all(arr, data->map.hight), err_pr2(4), NULL);
	if (check_border(arr, data) != 0)
		return (free_all(arr, data->map.hight), err_pr2(11), NULL);
	return (arr);
}
