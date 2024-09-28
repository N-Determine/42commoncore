#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

char	*ft_strcpy(char *dest, char *src, int loop_nbr);
int		ft_check_nl(char *str);

char *make_node(int fd)
{
	char	*buffer;
	char	*save_str;
	int		nl_check;
	int		loop_nbr;

	loop_nbr = 1;
	if (fd < 0)
		return (NULL);
	buffer = malloc(BUFFER_SIZE * sizeof(char));
	if (buffer == NULL)
		return (NULL);
	read(fd, buffer, BUFFER_SIZE);
	nl_check = ft_check_nl(buffer);
	save_str = malloc ((BUFFER_SIZE * loop_nbr) * sizeof(char));
	if (save_str == NULL)
		return (NULL);
	save_str = ft_strcpy(save_str, buffer, loop_nbr);


	return (save_str);
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

int	ft_check_nl(char *str)
{
	int	index;

	index = -1;
	while (index++ < BUFFER_SIZE && str[index])
	{
		if (str[index] == '\n')
			return (index);
	}
	return (0);
}


/* int	main(void)
{
	int fd = open("text.txt", O_RDWR);
	printf("%s\n", make_node(fd));
} */