#include "libft.h"
#include <stdio.h>
#include <string.h>

#define PATH "data.txt"

void	ft_free_all(char **arr, int len)
{
	if (len != 0)
	{
		len--;
		while (len >= 0)
		{
			free(arr[len]);
			len--;
		}
		free(arr);
	}
	else
	{
		free(arr[0]);
		free(arr);
	}
}

void	ft_free_dups(char **arr, int len)
{
	if (len != 0)
	{
		len--;
		while (len >= 0)
		{
			free(arr[len]);
			len--;
		}
	}
	else
	{
		free(arr[0]);
	}
}

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

int find_dir(int a, int b)
{
	if (a < b)
		return (1);
	return (-1);
}

/**
 * @brief Deletes one element out of an array
 * at the position index.
 */
char	**delete_one(char **values, char **new, int index)
{
	int i = 0;
	while(i < index)
	{
		new[i] = ft_strdup(values[i]);
		i++;
	}
	while(values[index + 1])
	{
		new[index] = ft_strdup(values[index + 1]);
		index++;
	}
	new[index] = NULL;
	return (new);
}

int	is_safe(char *line)
{
	line = rid_of_nl(line);
	char **values = ft_split(line, ' ');
	if (!values)
		return (0);
	int i = 0;
	while(values[i])
		i++;
	int len = i;
	int j = 0;
	char **new;
	int a;
	int b;
	int direction;
	new = calloc(len, sizeof(char **));
	if (!new)
		return (ft_free_all(values, len), 0);
	while (j < len)
	{
		int flag = 1;
		i = 0;
		ft_free_dups(new, len);
		new = delete_one(values, new, j);
		if (!new)
			return (ft_free_all(values, len), 0);
		a = atoi(new[i]);
		b = atoi(new[i + 1]);
		direction = find_dir(a, b);
		while (new[i + 1])
		{
			a = atoi(new[i]);
			b = atoi(new[i + 1]);
			if (find_dir(a, b) != direction)
			{
				flag = 0;
				break;
			}
			if ((abs(a - b) > 3 || abs(a - b) < 1))
			{
				flag = 0;
				break;
			}
			i++;
		}
		if (flag == 1)
			return (ft_free_all(new, len), ft_free_all(values, len), 1);
		j++;
	}
	return (ft_free_all(new, len), ft_free_all(values, len), 0);
}

int	main()
{
	int		fd = open(PATH, O_RDONLY);
	if (fd < 0)
		return (fprintf(stderr, "Whoopsies!\n"), 1);
	char	*line = get_next_line(fd);
	int safe = 0;
	while(line)
	{
		if(is_safe(line))
			safe++;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	printf("The number of safe reports equals %i\n", safe);
}
