/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeters <adeters@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 15:50:53 by adeters           #+#    #+#             */
/*   Updated: 2025/01/11 16:27:45 by adeters          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	init_prog(t_data *data, int ac, const char **av, const char **env)
{
	if (ac < 5)
		return (print_errors(USAGE));
	if (ft_strncmp(av[1], "here_doc", 8) == 0)
		data->mode = 0;
	else
		data->mode = 1;
	data->final_fd = open(av[ac - 1], write_mode(data->mode), 0644);
	if (data->final_fd == -1)
		return (print_errors(OPEN));
	data->init_fd = open(av[1], O_RDONLY, 0644);
	if (data->init_fd == -1)
		return (close(data->final_fd), print_errors(OPEN));
	data->paths = get_paths(env);
	if (!data->paths)
		return (fd_closer(data, 0), print_errors(PATHS));
	if (!pipe_maker(data, ac - 3 - data->mode))
	{
		fd_closer(data, 0);
		return (ft_free_list(data->paths), print_errors(PIPE));
	}
	return (0);
}

char	**execve_arr_maker(char **paths, const char *arg, int *error)
{
	int		index;
	char	*tmp;
	char	**arr;

	arr = ft_split(arg, ' ');
	if (!arr)
		return (*error = SPLIT, NULL);
	index = check_access(paths, arr[0], X_OK);
	if (index < 0)
	{
		ft_fprintf(2, "%s: %s\n", strerror(errno), arr[0]);
		return (*error = ACCESS, ft_free_list(arr), NULL);
	}
	if (ft_strchr(arr[0], '/') == 0)
	{
		tmp = allo_trip_strcat(paths[index], "/", arr[0]);
		if (!tmp)
			return (*error = MALLOC, ft_free_list(arr), NULL);
		free(arr[0]);
		arr[0] = ft_strdup(tmp);
		if (!arr[0])
			return (*error = MALLOC, ft_free_list(arr), NULL);
		free(tmp);
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
			return (fd_closer(data, i), 0);
		i++;
	}
	return (1);
}
