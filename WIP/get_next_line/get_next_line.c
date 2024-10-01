/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeters <adeters@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 19:32:35 by adeters           #+#    #+#             */
/*   Updated: 2024/10/01 20:21:05 by adeters          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdint.h>
#include <stdio.h>

int		make_line(char *saver, char *line);

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
		return (-1);
	while (str[index])
	{
		if (str[index] == '\n')
			return (index);
		index++;
	}
	return (-1);
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
	if (nl_pos == -1)
		size = ft_strlen(buf) + 1;
	else
		size = ft_strlen(buf + nl_pos + 1) + 1;
	new_saver = ft_calloc(size, sizeof(char));
	if (new_saver == NULL)
		return (NULL);
	if (nl_pos == -1)
		new_saver = ft_copy_until_char(new_saver, buf, '\0');
	else
		new_saver = ft_copy_until_char(new_saver, (buf + nl_pos + 1), '\0');
	free(buf);
	return (new_saver);
}

int	ft_line_len(char *buffer)
{
	if (ft_check_nl(buffer) == -1)
		return (ft_strlen(buffer));
	else
		return (ft_check_nl(buffer) + 1);
}

void	*free_foo(char *str1, char *str2)
{
	free(str1);
	str1 = NULL;
	free(str2);
	str2 = NULL;
	return (NULL);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	static char	*saver = NULL;
	char		*line;
	size_t		isn_eof;

	if (fd < 0)
		return (NULL);
	isn_eof = 1;
	while (isn_eof)
	{
		// this is a test
		buffer = ft_calloc(sizeof(char), BUFFER_SIZE + 1 + ft_strlen(saver));
		if (buffer == NULL)
			return(free_foo(saver, NULL));
		ft_copy_until_char(buffer, saver, '\0');
		isn_eof = read(fd, buffer + ft_strlen(saver), BUFFER_SIZE);
		if (isn_eof < 0)
			return(free_foo(buffer, saver));
		if (ft_check_nl(buffer) != -1)
		{
			line = ft_calloc(sizeof(char), ft_line_len(buffer) + 1);
			if (line == NULL)
				return (free_foo(buffer, saver));
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
			return (free_foo(saver, NULL));
		line = ft_copy_until_char(line, saver, '\0');
		free_foo(saver, NULL);
		return (line);
	}
	free_foo(saver, NULL);
	return (NULL);
}

/* int	main(void)
{
	int fd = open("./texts/text.txt", O_RDWR);
	char *str = get_next_line(fd);
	printf("%s", str);
	free(str);
	str = get_next_line(fd);
	printf("%s", str);
	free(str);
	str = get_next_line(fd);
	printf("%s", str);
	free(str);
	str = get_next_line(fd);
	printf("%s", str);
	free(str);
	str = get_next_line(fd);
	printf("%s", str);
	free(str);
	str = get_next_line(fd);
	printf("%s", str);
	free(str);
	close(fd);
	return (0);
} */

#include "libft.h"
#include <stdlib.h>
#include <string.h>
#include <time.h>

int decode_file(int *lpf, int *f, int *fr, char *str);
int	error_handler(int code);


ssize_t frame_proc_duration(clock_t start, clock_t end)
{
	printf("%zi", (end-start) / CLOCKS_PER_SEC * 1000000);
	return ((end - start) / CLOCKS_PER_SEC * 1000000);
}

int	main(int argc, char **argv)
{
	int 	lines_per_frame; int frames; int frame_rate;
	ssize_t	proc_time;
	clock_t	start, end;
	char	*str = NULL;

	if (argc != 3)
		return (error_handler(1));
	ssize_t duration = atoi(argv[2]) * 1000000;
	if (duration <= 0)
		return (error_handler(2));
	int fd = open(argv[1], O_RDWR);
	if (fd < 0)
		return (error_handler(3));
	str = get_next_line(fd);
	if (!decode_file(&lines_per_frame, &frames, &frame_rate, str))
		return (error_handler(4));
	// Play movie for chosen duration
	do {
		int frame_line = 0;
		int index = 0;
		// Print a single frame
		while (index < frames && duration > 0)
		{
			start = clock();
			//system("clear");
			frame_line = 0;
			while (frame_line < lines_per_frame)
			{
				if (str)
					free(str);
				str = get_next_line(fd);
				if (str)
					ft_putstr_fd(str, 1); fflush(stdout);
				frame_line++;
			}
			duration -= 1000000 / frame_rate;
			index++;
			end = clock();
			proc_time = frame_proc_duration(start, end);
			printf("%zi", proc_time); fflush(stdout);
			if (proc_time < (1000000 / frame_rate))
				usleep((1000000 / frame_rate) - proc_time);
			else
				usleep(1000000 / frame_rate);
		}
		close(fd);
		fd = open(argv[1], O_RDWR);
		str = get_next_line(fd);
	} while (duration > 0);
	system("clear");
	get_next_line(-1);
	free(str);
}

int decode_file(int *lpf, int *f, int *fr, char *str)
{

	*lpf = atoi(str);
	*f = atoi(strchr(str, '-') + 1);
	*fr = atoi(strchr(strchr(str, '-') + 1, '-') + 1);
	if (!*lpf || !*f || !*fr)
		return (0);
	return (1);
}

int	error_handler(int code)
{
	if (code == 1)
	{
		fprintf(stderr, "Usage: ./a.out [file.txt] [duration in s]\n");
		return (1);
	}
	if (code == 2)
	{
		fprintf(stderr, "Not a valid duration");
		return (2);
	}
	if (code == 3)
	{
		fprintf(stderr, "Could not open file.\n");
		return(3);
	}
	if (code == 4)
	{
		fprintf(stderr, "Error reading formating code.\n");
		return (4);
	}
	return (0);
}