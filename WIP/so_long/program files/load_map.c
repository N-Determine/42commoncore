/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeters <adeters@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 15:45:58 by adeters           #+#    #+#             */
/*   Updated: 2024/11/05 17:18:27 by adeters          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft.h"
#include "get_next_line.h"

#include <stdio.h>

char *map_adress = MAP_ADRESS;

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

int	check_map_dimensions(char *map_adress, int *width, int *hight)
{
	char *line;
	int fd;
	fd = open(MAP_ADRESS, O_RDONLY);
	line = rid_of_nl(get_next_line(fd));
	if (!line)
		return (-1);
	int last = ft_strlen(line);
	*width = last;
	*hight = 1;
	while (line)
	{
		free(line);
		line = rid_of_nl(get_next_line(fd));
		if (!line)
			break;
		if (last != ft_strlen(line) || !is_valid_str(line))
			return (-1);
		*hight += 1;
	}
	close(fd);
	free(line);
	return (1);
}

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

char **allocate_map(width, hight)
{
	// Allocate the space
	char **arr = malloc(sizeof(char *) * hight);
	if (!arr)
		return (NULL);
	int i = 0;
	while (i < hight)
	{
		arr[i] = malloc(sizeof(char) * width);
		if (!arr[i])
			return (free_all(arr, i), NULL); // Add function that frees previous allocations
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

	printf("width: %i, hight: %i\n", width, hight);
	fd = open(MAP_ADRESS, O_RDONLY);
	j = 0;
	i = 0;
	while (i < hight)
	{
		if (i > 0)
			free(line);
		line = rid_of_nl(get_next_line(fd));
		if (!line)
			return (NULL);
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

char	**load_map(char *map_adress, int *width, int *hight)
{
	//int		width;
	//int		hight;
	char	**arr;

	if(check_map_dimensions(map_adress, width, hight) == -1)
		return (NULL);
	arr = allocate_map(*width, *hight);
	if (!arr)
		return (NULL);
	arr = fill_array(arr, map_adress, *width, *hight);
	return (arr);
}
