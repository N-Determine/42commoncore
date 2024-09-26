// Create a buffer:
// allocate memory once more than last iteration of the loop
// read into the buffer from the saver variable
// free the saver variable
// read into the buffer the next buffer amount of the text file
// check for the newline character
// if nl is found -> create new string an copy into the full string from the saver
// 			free the buffer
// 			return the newly created string

// else 
// 	allote memory for saver and copy into it
//	free the buffer

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	ft_check_nl(char *str)
{
	int	index;

	index = -1;
	while (index++ < BUFFER_SIZE && str[index])
	{
		if (str[index] == '\n')
			return (1);
	}
	return (0);
}

char	*ft_strcpy(char *dest, char *src, int loop_nbr)
{
	int index;

	index = 0;
	while (index < BUFFER_SIZE)
	{
		dest[index + (BUFFER_SIZE * (loop_nbr - 1))] = src[index];
		index++;
	}
	return (dest);
}

char	*get_next_line(int fd)
{
	int		nl_flag;
	int		index;
	int		i;
	int		loop_nbr;
	char	*buffer;
	char	*saver;
	char	*ret_val;

	if (fd < 0)
		return (NULL);
	nl_flag = 0;
	loop_nbr = 1;
	index = 0;
	i = 0;
	while (nl_flag == 0)
	{
		buffer = malloc(1 + BUFFER_SIZE * loop_nbr * sizeof(char));
		if (buffer == NULL)
			return (NULL);
		if (loop_nbr > 1)
		{
			buffer = ft_strcpy(buffer, saver, 1);
			free(saver);
		}
		read(fd, buffer + (BUFFER_SIZE * (loop_nbr - 1)), BUFFER_SIZE);
		nl_flag = ft_check_nl(buffer);
		if (nl_flag == 1)
		{
			
			while (buffer[index] && buffer[index] != '\n')
				index++;
			ret_val = malloc(1 + index * sizeof(char));
			while (i <= index)
			{
				ret_val[i] = buffer[i];
				i++;
			}
			free(buffer);
			return (ret_val);
		}
		saver = malloc(1 + BUFFER_SIZE * loop_nbr * sizeof(char));
		if (saver == NULL)
			return (NULL);
		saver = ft_strcpy(saver, buffer, loop_nbr);
		free(buffer);
		loop_nbr++;
	}
	saver[BUFFER_SIZE * loop_nbr] = 'A';
	return (saver);
}

int	main(void)
{
	int fd = open("text.txt", O_RDWR);
	char *ptr = get_next_line(fd);
	printf("%s", ptr);
	close(fd);
	free(ptr);
}
