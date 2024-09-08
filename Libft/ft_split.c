/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeters <adeters@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 13:50:08 by adeters           #+#    #+#             */
/*   Updated: 2024/09/08 16:15:59 by adeters          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	ft_arr_len(char const *s, char c);
static void	ft_free_all(char **arr, int index, int arr_len);
size_t		ft_strlcpy(char *dest, const char *src, size_t size);
static int	ft_allo_and_copy(char **arr, int arr_len, char const *s, char c);

char	**ft_split(char const *s, char c)
{
	int		arr_len;
	char	**arr;

	arr_len = ft_arr_len(s, c);
	arr = (char **) malloc((1 + arr_len) * sizeof(char *));
	if (arr == 0)
		return (0);
	arr[arr_len] = (char *)malloc (sizeof(char));
	if (arr[arr_len] == 0)
	{
		free(arr);
		return (0);
	}
	arr[arr_len][0] = '\0';
	if (!ft_allo_and_copy(arr, arr_len, s, c))
		return (0);
	return (arr);
}

static int	ft_arr_len(char const *s, char c)
{
	int	counter;
	int	check;
	int	i;
	int	j;

	counter = 0;
	i = 0;
	while (s[i])
	{
		j = 0;
		check = 0;
		while (s[i + j] && s[i + j] == c)
			j++;
		while (s[i + j] && s[i + j] != c)
		{
			j++;
			check = 1;
		}
		i = i + j;
		if (check)
			counter++;
	}
	return (counter);
}

static int	ft_allo_and_copy(char **arr, int arr_len, char const *s, char c)
{
	int	index;
	int	i;
	int	j;

	index = 0;
	i = 0;
	while (s[i] && index < arr_len)
	{
		while (s[i] == c && s[i])
			i++;
		j = 0;
		while (s[i + j] != c && s[i + j])
			j++;
		arr[index] = (char *) malloc(j * sizeof(char) + 1);
		if (arr[index] == 0)
		{
			ft_free_all(arr, index, arr_len);
			return (0);
		}
		ft_strlcpy(arr[index], &s[i], j + 1);
		i = i + j;
		index++;
	}
	return (1);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;
	int		y;

	i = 0;
	y = 0;
	while (src[y])
		y++;
	if (size > 0)
	{
		while (i < (size - 1))
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (y);
}

static void	ft_free_all(char **arr, int index, int arr_len)
{
	free(arr[arr_len]);
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
/*
#include <stdio.h>

int main(void)
{
	char *s = ",,,,,hello,,,,,,,,,,,there,my,frend,,,,,";
	char **arr = ft_split(s, ',');
	printf("%i\n", ft_arr_len(s, ','));
	printf("%s\n", arr[0]);
	printf("%s\n", arr[1]);
	printf("%s\n", arr[2]);
	printf("%s\n", arr[3]);
	printf("%s\n", arr[4]);
	ft_free_all(arr, 4, 4);
}*/