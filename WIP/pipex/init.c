/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeters <adeters@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 15:50:53 by adeters           #+#    #+#             */
/*   Updated: 2025/01/12 13:55:12 by adeters          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	init_prog(t_data *data, int ac, const char **av, const char **env)
{
	if (ac < 5)
		return (print_errors(USAGE));
	if (ft_strncmp(av[1], "here_doc", 8) == 0)
		data->mode = 1;
	else
		data->mode = 0;
	data->procs = ac - data->mode - 3;
	if (data->procs > FD_LIMIT)
		return (print_errors(LIMIT));
	data->final_fd = open(av[ac - 1], write_mode(data->mode), 0644);
	if (data->final_fd == -1)
		return (print_errors(OPEN));
	if (data->mode == 0)
	{
		data->init_fd = open(av[1], O_RDONLY, 0644);
		if (data->init_fd == -1)
			return (close(data->final_fd), print_errors(OPEN));
	}
	data->paths = get_paths(env);
	if (!data->paths)
		return (fd_closer(data, 0), print_errors(PATHS));
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
			return (fd_closer(data, i), print_errors(PIPE));
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
		return (print_errors(GNL));
	ft_printf("pipe heredoc> ");
	line = get_next_line(STDIN_FILENO);
	if (!line)
		return (free(limiter), print_errors(GNL));
	while (ft_strcmp(line, limiter) != 0)
	{
		ft_fprintf(data->fd[0][1], "%s", line);
		free(line);
		ft_printf("pipe heredoc> ");
		line = get_next_line(0);
		if (!line)
			return (free(limiter), print_errors(GNL));
	}
	return (free(limiter), free(line), 0);
}
