/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeters <adeters@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 13:12:06 by adeters           #+#    #+#             */
/*   Updated: 2024/10/09 21:05:28 by adeters          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int		ft_check_nl(char *str);
char	*free_foo(char **buffer, char *line);
char	*ft_update(char *buffer);
char	*make_line(char **buffer, char *line, int code);

char	*get_next_line(int fd)
{
	static char	*buffer[1024];
	char		*line;
	ssize_t		bytes_read;

	line = NULL;
	if (fd < 0 || fd >= 1024)
		return (NULL);
	bytes_read = 1;
	while (!ft_check_nl(buffer[fd]) && bytes_read > 0)
	{
		buffer[fd] = ft_update(buffer[fd]);
		if (!buffer[fd])
			return (NULL);
		bytes_read = read(fd, buffer[fd] + ft_strlen(buffer[fd]), BUFFER_SIZE);
		if (bytes_read < 0)
			return (free_foo(&buffer[fd], NULL));
	}
	if (ft_check_nl(buffer[fd]))
		return (make_line(&buffer[fd], line, 1));
	if (buffer[fd] && ft_strlen(buffer[fd]))
		line = make_line(&buffer[fd], line, 0);
	free(buffer[fd]);
	buffer[fd] = NULL;
	return (line);
}

int	ft_check_nl(char *str)
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

char	*free_foo(char **buffer, char *line)
{
	free(*buffer);
	free(line);
	*buffer = NULL;
	return (NULL);
}

char	*ft_update(char *buffer)
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

char	*make_line(char **buffer, char *line, int code)
{
	if (code == 1)
	{
		line = ft_calloc(1, (ft_strchr(*buffer, '\n') + 1 - *buffer) + 1);
		ft_strlcpy(line, *buffer, (ft_strchr(*buffer, '\n') + 1 - *buffer) + 1);
		*buffer = ft_update(*buffer);
		if (!*buffer || !line)
			return (free_foo(buffer, line));
		return (line);
	}
	line = ft_calloc(1, ft_strlen(*buffer) + 1);
	ft_strlcpy(line, *buffer, ft_strlen(*buffer) + 1);
	*buffer = ft_update(*buffer);
	if (!*buffer || !line)
		return (free_foo(buffer, line));
	return (line);
}
/* 
#include <stdio.h>

int main(void)
{
	int fd1 = open("t1.txt", O_RDWR);
	int fd2 = open("t2.txt", O_RDWR);
	int fd3 = open("t3.txt", O_RDWR);
	int i;
	int j = 0;
	char *str;
	
	while (j < 7)
	{
		i = 0;
		while (i < 3)
		{
			str = get_next_line(fd1);
			printf("%s", str);
			free(str);
			i++;
		}
		i = 0;
		while (i < 3)
		{
			str = get_next_line(fd2);
			printf("%s", str);
			free(str);
			i++;
		}
		i = 0;
		while (i < 3)
		{
			str = get_next_line(fd3);
			printf("%s", str);
			free(str);
			i++;
		}
		j++;
	}
	free(str);
	close(fd1);
	close(fd2);
	close(fd3);
} */