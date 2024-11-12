/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeters <adeters@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 13:12:06 by adeters           #+#    #+#             */
/*   Updated: 2024/11/12 15:28:22 by adeters          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"
#include "so_long.h"

static int	ft_check_nl(char *str);
static char	*free_foo(char **buffer, char *line);
static char	*ft_update(char *buffer);
static char	*make_line(char **buffer, char *line, int code);

char	*get_next_line(int fd)
{
	static char	*buffer = NULL;
	char		*line;
	ssize_t		bytes_read;

	line = NULL;
	if (fd < 0 || fd >= 1024)
		return (free_foo(&buffer, NULL));
	bytes_read = 1;
	while (!ft_check_nl(buffer) && bytes_read > 0)
	{
		buffer = ft_update(buffer);
		if (!buffer)
			return (NULL);
		bytes_read = read(fd, buffer + ft_strlen(buffer), BUFFER_SIZE);
		if (bytes_read < 0)
			return (free_foo(&buffer, NULL));
	}
	if (ft_check_nl(buffer))
		return (make_line(&buffer, line, 1));
	if (buffer && ft_strlen(buffer))
		line = make_line(&buffer, line, 0);
	free(buffer);
	buffer = NULL;
	return (line);
}

static int	ft_check_nl(char *str)
{
	int	index;

	index = 0;
	if (str == NULL)
		return (0);
	while (str[index])
	{
		if (str[index] == '\n')
			return (1);
		index++;
	}
	return (0);
}

static char	*free_foo(char **buffer, char *line)
{
	free(*buffer);
	free(line);
	*buffer = NULL;
	return (NULL);
}

static char	*ft_update(char *buffer)
{
	char	*tmp_buffer;

	if (buffer == NULL)
	{
		buffer = ft_calloc(BUFFER_SIZE + 1, 1);
		if (!buffer)
			return (NULL);
		return (buffer);
	}
	else if (!(ft_check_nl(buffer)))
	{
		tmp_buffer = ft_calloc(BUFFER_SIZE + 1 + ft_strlen(buffer), 1);
		if (!tmp_buffer)
			return (free_foo(&buffer, NULL));
		ft_strlcpy(tmp_buffer, buffer, ft_strlen(buffer) + 1);
		free(buffer);
		return (tmp_buffer);
	}
	tmp_buffer = ft_calloc(ft_strlen(ft_strchr(buffer, '\n') + 1) + 1, 1);
	if (!tmp_buffer)
		return (free_foo(&buffer, NULL));
	ft_strlcpy(tmp_buffer, (ft_strchr(buffer, '\n') + 1),
		ft_strlen(ft_strchr(buffer, '\n') + 1) + 1);
	free(buffer);
	return (tmp_buffer);
}

static char	*make_line(char **buffer, char *line, int code)
{
	if (code == 1)
	{
		line = ft_calloc(1, (ft_strchr(*buffer, '\n') + 1 - *buffer) + 1);
		if (!line)
			return (free_foo(buffer, line));
		ft_strlcpy(line, *buffer, (ft_strchr(*buffer, '\n') + 1 - *buffer) + 1);
		*buffer = ft_update(*buffer);
		if (!*buffer || !line)
			return (free_foo(buffer, line));
		return (line);
	}
	line = ft_calloc(1, ft_strlen(*buffer) + 1);
	if (!line)
		return (free_foo(buffer, line));
	ft_strlcpy(line, *buffer, ft_strlen(*buffer) + 1);
	*buffer = ft_update(*buffer);
	if (!*buffer || !line)
		return (free_foo(buffer, line));
	return (line);
}
