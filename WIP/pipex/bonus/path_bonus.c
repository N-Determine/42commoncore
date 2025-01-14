/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeters <adeters@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 14:47:11 by adeters           #+#    #+#             */
/*   Updated: 2025/01/14 18:21:56 by adeters          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

char	**get_paths(const char **env)
{
	int		i;
	char	**paths;

	i = 0;
	while (env[i])
	{
		if (ft_strnstr(env[i], "PATH=", 5) != 0)
			break ;
		i++;
	}
	paths = ft_split(env[i] + 5, ':');
	if (!paths)
		return (NULL);
	return (paths);
}

int	check_access(char **paths, char *prog)
{
	char	*tmp;
	int		i;

	i = 0;
	if (!paths | !prog)
		return (-1);
	if (access(prog, F_OK) == 0 && access(prog, X_OK) == 0)
		return (1);
	else if (access(prog, F_OK) == 0 && access(prog, X_OK) != 0)
		return (-2);
	while (paths[i])
	{
		tmp = allo_trip_strcat(paths[i], "/", prog);
		if (!tmp)
			return (-1);
		if (access(tmp, X_OK) == 0 && access(tmp, F_OK) == 0)
			return (free(tmp), i);
		else if (access(tmp, F_OK) == 0 && access(prog, X_OK) != 0)
			return (free(tmp), -2);
		free(tmp);
		i++;
	}
	return (-1);
}

char	*allo_strcat(const char *s1, const char *s2)
{
	int		size;
	char	*res;
	int		i;
	int		j;

	if (!s1 | !s2)
		return (NULL);
	size = ft_strlen(s1) + ft_strlen(s2) + 1;
	res = ft_calloc(size, sizeof(char));
	if (!res)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		res[i] = s2[j];
		i++;
		j++;
	}
	return (res);
}

char	*allo_trip_strcat(const char *s1, const char *s2, const char *s3)
{
	char	*tmp;
	char	*res;

	if (!s1 | !s2 | !s3)
		return (NULL);
	tmp = allo_strcat(s1, s2);
	if (!tmp)
		return (NULL);
	res = allo_strcat(tmp, s3);
	if (!res)
		return (free(tmp), NULL);
	return (free(tmp), res);
}
