/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeters <adeters@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 13:43:35 by adeters           #+#    #+#             */
/*   Updated: 2024/12/16 16:27:18 by adeters          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**get_paths(char **env)
{
	int		i;
	char	**paths;

	i = 0;
	while (env[i])
	{
		if (ft_strnstr(env[i], "PATH=/home", 20) != 0)
			break ;
		i++;
	}
	paths = ft_split(env[i] + 5, ':');
	if (!paths)
		return (NULL);
	return (paths);
}

char	*allo_strcat(char *str1, char *str2)
{
	int		size;
	char	*res;
	int		i;
	int		j;

	if (!str1 | !str2)
		return (NULL);
	size = ft_strlen(str1) + ft_strlen(str2) + 1;
	res = ft_calloc(size, sizeof(char));
	if (!res)
		return (NULL);
	i = 0;
	j = 0;
	while (str1[i])
	{
		res[i] = str1[i];
		i++;
	}
	while (str2[j])
	{
		res[i] = str2[j];
		i++;
		j++;
	}
	return (res);
}

char	*allo_trip_strcat(char *str1, char *str2, char *str3)
{
	char	*tmp;
	char	*res;

	if (!str1 | !str2 | !str3)
		return (NULL);
	tmp = allo_strcat(str1, str2);
	if (!tmp)
		return (NULL);
	res = allo_strcat(tmp, str3);
	if (!res)
		return (free(tmp), NULL);
	return (free(tmp), res);
}

int	main(int ac, char **av, char **env)
{
	char **paths = get_paths(env);
	if (!paths)
		return (1);
	char *first = allo_trip_strcat(paths[0], "/", "ls");
	ft_printf("first path: %s\n", first);
	free(first);
	ft_free_list(paths);
	return (0);
}
