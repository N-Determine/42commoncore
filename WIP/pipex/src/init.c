/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeters <adeters@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 15:50:53 by adeters           #+#    #+#             */
/*   Updated: 2025/01/14 20:42:35 by adeters          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	init_prog(t_data *data, int ac, const char **env)
{
	if (ac != 5)
		return (p_err(USAGE));
	data->procs = ac - 3;
	data->init_fd = -1;
	data->final_fd = -1;
	if (data->procs > FD_LIMIT)
		return (p_err(LIMIT));
	data->paths = get_paths(env);
	if (!data->paths)
		return (p_err(PATHS));
	return (0);
}

char	**mk_exe(char **paths, const char *arg, int *error)
{
	int		index;
	char	*tmp;
	char	**arr;

	arr = ft_split(arg, ' ');
	if (!arr)
		return (*error = SPLIT, NULL);
	index = check_access(paths, arr[0]);
	if (index < 0)
	{
		*error = PERM;
		if (index == -1)
			*error = ACCESS;
		return (fr_lst(arr), NULL);
	}
	if (ft_strchr(arr[0], '/') == 0)
	{
		tmp = allo_trip_strcat(paths[index], "/", arr[0]);
		if (!tmp)
			return (*error = MALLOC, fr_lst(arr), NULL);
		free(arr[0]);
		arr[0] = tmp;
	}
	return (arr);
}

int	pipe_maker(t_data *data, int pipes_amt)
{
	int	i;

	i = 0;
	while (i < pipes_amt)
	{
		if (pipe(data->fd[i]) == -1)
			return (fd_cl(data, i), p_err(PIPE));
		i++;
	}
	return (0);
}
