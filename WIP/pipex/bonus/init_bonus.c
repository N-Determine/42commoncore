/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeters <adeters@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 15:50:53 by adeters           #+#    #+#             */
/*   Updated: 2025/01/14 18:06:53 by adeters          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	init_prog(t_data *data, int ac, const char **av, const char **env)
{
	if (ac < 5)
		return (p_err(USAGE));
	if (ft_strncmp(av[1], "here_doc", 8) == 0)
		data->mode = 1;
	else
		data->mode = 0;
	data->procs = ac - data->mode - 3;
	data->init_fd = -1;
	data->final_fd = -1;
	if (data->procs > FD_LIMIT)
		return (p_err(LIMIT));
	data->paths = get_paths(env);
	if (!data->paths)
		return (fd_cl(data, 0), p_err(PATHS));
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

char	*make_limiter(const char **av)
{
	char	*limiter;
	int		size;

	size = ft_strlen(av[2]) + 2;
	limiter = ft_calloc(sizeof(char), size);
	if (!limiter)
		return (NULL);
	ft_strlcpy(limiter, av[2], size - 1);
	limiter[size - 2] = '\n';
	return (limiter);
}

int	get_here_doc(t_data *data, const char **av)
{
	char	*line;
	char	*limiter;

	limiter = make_limiter(av);
	if (!limiter)
		return (p_err(GNL));
	ft_printf("pipe heredoc> ");
	line = get_next_line(STDIN_FILENO);
	if (!line)
		return (free(limiter), p_err(GNL));
	while (ft_strcmp(line, limiter) != 0)
	{
		ft_fprintf(data->fd[0][1], "%s", line);
		free(line);
		ft_printf("pipe heredoc> ");
		line = get_next_line(0);
		if (!line)
			return (free(limiter), p_err(GNL));
	}
	return (free(limiter), free(line), 0);
}
