/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeters <adeters@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 14:47:11 by adeters           #+#    #+#             */
/*   Updated: 2025/01/15 13:35:25 by adeters          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

char	**get_paths(const char **env)
{
	int		i;
	char	**paths;

	i = 0;
	paths = NULL;
	while (env[i])
	{
		if (ft_strnstr(env[i], "PATH=", 5) != 0)
			break ;
		i++;
	}
	if (env[i])
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
	if (!prog)
		return (-1);
	if (access(prog, F_OK) == 0 && access(prog, X_OK) == 0)
		return (1);
	else if (access(prog, F_OK) == 0 && access(prog, X_OK) != 0)
		return (-2);
	if (!paths)
		return (-1);
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
