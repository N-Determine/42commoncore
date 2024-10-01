#include "get_next_line.h"
#include <fcntl.h>
#include <stdint.h>
#include <stdio.h>

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

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	y;

	i = 0;
	y = 0;
	while (src[y])
		y++;
	if (size > 0)
	{
		while (i < (size - 1) && i < y)
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (y);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	c = c % 256;
	while (s[i])
	{
		if (s[i] == c)
			return ((char *)&s[i]);
		i++;
	}
	if (s[i] == c)
		return ((char *)&s[i]);
	return (0);
}

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

void	ft_strcpy(char *dest, char *src)
{
	int i;

	i = 0;
	while (src && src[i])
	{
		dest[i] = src[i];
		i++;
	}
}

char	*ft_update(char *buffer)
{
	char *tmp_buffer;

	if (buffer == NULL)
	{
		buffer = ft_calloc(BUFFER_SIZE + 1, 1);
		return (buffer);
	}
	else if (!(ft_check_nl(buffer)))
	{
		tmp_buffer = ft_calloc(BUFFER_SIZE + 1 + ft_strlen(buffer), 1); // Protect
		ft_strcpy(tmp_buffer, buffer);
		free(buffer);
		return (tmp_buffer);
	}
	tmp_buffer = ft_calloc(ft_strlen(ft_strchr(buffer, '\n') + 1) + 1, 1);
	ft_strcpy(tmp_buffer, (ft_strchr(buffer, '\n') + 1));
	free(buffer);
	return (tmp_buffer);
}

char *get_next_line(int fd)
{
	static char	*buffer = NULL;
	char		*line;
	size_t		bytes_read;

	line = NULL;
	if (fd < 0)
	{
		free(buffer);
		return (NULL);
	}
	bytes_read = 1;
	while (!ft_check_nl(buffer) && bytes_read > 0)
	{
		buffer = ft_update(buffer); // Protect
		bytes_read = read(fd, buffer + ft_strlen(buffer), BUFFER_SIZE); // Protect
	}
	// Buffer included nl -> return nl
	if (ft_check_nl(buffer))
	{
		line = ft_calloc(1, (ft_strchr(buffer, '\n') + 2 - buffer) + 1); // Protect
		ft_strlcpy(line, buffer, (ft_strchr(buffer, '\n') + 2 - buffer));
		buffer = ft_update(buffer);
		return (line);
	}
	// Does not work if buffer size is smaller than the last line without a newline
	if (buffer && ft_strlen(buffer))
	{
		line = ft_calloc(1, ft_strlen(buffer) + 1); // Protect
		ft_strlcpy(line, buffer, ft_strlen(buffer) + 1);
		buffer = ft_update(buffer); // Protect
	}
	free(buffer);
	buffer = NULL;
	return (line);
}

int	main(void)
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
}