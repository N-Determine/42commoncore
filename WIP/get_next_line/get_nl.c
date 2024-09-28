
#include "get_next_line.h"
#include <fcntl.h>
#include <stdint.h>
#include <stdio.h>

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

char	*ft_copy_until_char(char *dest, char *src, char c)
{
	int	index;

	index = 0;
	if (dest == NULL)
		return (src);
	if (src == NULL)
		return (NULL);
	while (src[index] != c)
	{
		dest[index] = src[index];
		index++;
	}
	dest[index] = src[index];
	if (c == '\0')
		dest[index] = '\0';
	return (dest);
}

/**

	* @brief This function updates the saver to only contain the characters after the first newline
 */
char	*ft_update_saver(char *old_saver)
{
	int		nl_pos;
	char	*new_saver;

	nl_pos = ft_check_nl(old_saver);
	if (nl_pos == 0)
	{
		new_saver = ft_calloc(ft_strlen(old_saver) + 1, sizeof(char));
		if (new_saver == NULL)
			return (NULL);
		new_saver = ft_copy_until_char(new_saver, old_saver, '\0');
		free(old_saver);
	}
	else
	{
		new_saver = ft_calloc(ft_strlen(old_saver + nl_pos + 1) + 1,
				sizeof(char));
		if (new_saver == NULL)
			return (NULL);
		new_saver = ft_copy_until_char(new_saver, (old_saver + nl_pos + 1),
				'\0');
		free(old_saver);
	}
	return (new_saver);
}

char	*get_next_line(int fd)
{
	char		*new_saver;
	// Does not have to be initialized
	static char	*old_saver;
	char		*line;
	size_t		isn_eof;

	if (fd < 0)
		return (NULL);
	isn_eof = 1;
	while (isn_eof)
	{
		new_saver = ft_calloc(sizeof(char), BUFFER_SIZE + 1
				+ ft_strlen(old_saver));
		if (new_saver == NULL)
			return (NULL);
		ft_copy_until_char(new_saver, old_saver, '\0');
		isn_eof = read(fd, new_saver + ft_strlen(old_saver), BUFFER_SIZE);
		if (isn_eof < 0)
		{
			free(new_saver);
			return (NULL);
		}
		if (ft_check_nl(new_saver))
		{
			line = ft_calloc(sizeof(char), ft_check_nl(new_saver) + 2);
			if (line == NULL)
				return (NULL);
			line = ft_copy_until_char(line, new_saver, '\n');
			old_saver = ft_update_saver(new_saver);
			return (line);
		}
		// Don't have to allocate memory for the old_saver but now I do
		old_saver = ft_update_saver(new_saver);
	}
	return (NULL);
}

int	main(void)
{
	int i = 0;
	int fd = open("text.txt", O_RDWR);
	char *str = get_next_line(fd);
	printf("%s", str);
	free(str);
	close(fd);
}