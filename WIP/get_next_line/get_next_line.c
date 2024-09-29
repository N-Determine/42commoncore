/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeters <adeters@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 19:32:35 by adeters           #+#    #+#             */
/*   Updated: 2024/09/29 23:41:51 by adeters          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdint.h>
#include <stdio.h>

int	make_line(char *saver, char *line);

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_calloc(size_t nmemb, size_t size)
{
	char	*ptr;
	int		i;

	i = 0;
	if (size != 0 && nmemb > SIZE_MAX / size)
		return (NULL);
	ptr = malloc(nmemb * size);
	if (ptr == NULL)
		return (NULL);
	while (i < nmemb * size)
	{
		ptr[i] = '\0';
		i++;
	}
	return (ptr);
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
			return (index);
		index++;
	}
	return (0);
}

/**
 * Probably very unsafe because it can segfault if dest is to small, 
 * don't forgett to allocate for \0
 */
char	*ft_copy_until_char(char *dest, char *src, char c)
{
	int	index;

	index = 0;
	if (dest == NULL)
		return (src);
	if (src == NULL)
		return (NULL);
	while (src[index] != c && src[index])
	{
		dest[index] = src[index];
		index++;
	}
	dest[index] = c;
	return (dest);
}

/**
 * @brief Updates the static string 'saver' to either contain the 
 * new buffer if there is no newline
 * or the rest after the newline. 
 * It free's the saver everytime before overwritting it.
 */
char	*ft_update_saver(char *buf, char *old_saver)
{
	int		nl_pos;
	int		size;
	char	*new_saver;

	free(old_saver);
	size = 0;
	nl_pos = ft_check_nl(buf);
	if (nl_pos == 0)
		size = ft_strlen(buf) + 1;
	else
		size = ft_strlen(buf + nl_pos + 1) + 1;
	new_saver = ft_calloc(size, sizeof(char));
	if (new_saver == NULL)
		return (NULL);
	if (nl_pos == 0)
		new_saver = ft_copy_until_char(new_saver, buf, '\0');
	else
		new_saver = ft_copy_until_char(new_saver, (buf + nl_pos + 1), '\0');
	free(buf);
	return (new_saver);
}

int		ft_line_len(char *buffer)
{
	if (ft_check_nl(buffer))
		return (ft_check_nl(buffer) + 1);
	else
		return (ft_strlen(buffer));
}

char	*get_next_line(int fd)
{
	char			*buffer;
	static char		*saver;
	char			*line;
	size_t			isn_eof;

	if (fd < 0)
		return (NULL);
	isn_eof = 1;
	while (isn_eof)
	{
		buffer = ft_calloc(sizeof(char), BUFFER_SIZE + 1 + ft_strlen(saver));
		if (buffer == NULL)
			return (NULL);
		ft_copy_until_char(buffer, saver, '\0');
		isn_eof = read(fd, buffer + ft_strlen(saver), BUFFER_SIZE);
		if (isn_eof < 0)
		{
			free(buffer);
			return (NULL);
		}
		if (ft_check_nl(buffer))
		{
			line = ft_calloc(sizeof(char), ft_line_len(buffer) + 1);
			if (line == NULL)
				return (NULL);
			line = ft_copy_until_char(line, buffer, '\n');
			saver = ft_update_saver(buffer, saver);
			return (line);
		}
		saver = ft_update_saver(buffer, saver);
	}
	if (saver && ft_strlen(saver) > 0)
	{
		line = ft_calloc(sizeof(char), ft_line_len(saver) + 1);
		if (line == NULL)
			return (NULL);
		line = ft_copy_until_char(line, saver, '\0');
		free(saver);
		saver = NULL;
		return (line);
	}
	free(saver);
	return (NULL);
}

int	main(void)
{
	int i = 0;
	int lines_per_frame = 10;
	int frame_line = 1;
	int frames = 11;
	int index = 0;
	int fd = open("./texts/text3.txt", O_RDWR);
	char *str = get_next_line(fd);
	printf("%s", str);
	while (str)
	{
		// Print frames * a single frame
		while (str && index < frames)
		{
			// Clear screen & Print a single frame
			printf("\033[H\033[J"); fflush(stdout);
			frame_line = 0;
			while (str && frame_line < lines_per_frame)
			{
				free(str);
				str = get_next_line(fd);
				if (str)
					printf("%s", str);
				frame_line++;
			}
			// Delay für 6 fps
			usleep(166667);
			index++;
		}
	}
	free(str);
	close(fd);
}