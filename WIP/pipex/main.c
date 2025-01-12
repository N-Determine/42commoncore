/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeters <adeters@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 13:43:35 by adeters           #+#    #+#             */
/*   Updated: 2025/01/12 13:14:23 by adeters          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char *make_limiter(const char **av)
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

int	main(int ac, const char **av, const char **env)
{
	t_data	data;

	data.code = init_prog(&data, ac, av, env);
	if (data.code)
		return (data.code);

	// Try if you can use ft_fprintf to write directly into the initial file descriptor.
	// That might be the easiest way without any weird get next line stuff
	if (data.mode == 1)
	{
		char *line;
		char *limiter;
		
		limiter = make_limiter(av);
		if (!limiter)
			return (1);
		ft_printf("pipe heredoc> ");
		line = get_next_line(STDIN_FILENO);
		if (!line)
			return (free(limiter), 1);
		while (ft_strcmp(line, limiter) != 0)
		{
			ft_fprintf(data.fd[0][1], "%s", line);
			free(line);
			ft_printf("pipe heredoc > ");
			line = get_next_line(0);
			if (!line)
				return (1);
		}
	}

	
	// First command block
	data.pid[0] = fork();
	if (data.pid[0] == -1)
		return (ft_free_list(data.paths), fd_closer(&data, data.processes), print_errors(FORK));
	if (data.pid[0] == 0)
	{
		if (data.mode == 0)
			dup2(data.init_fd, STDIN_FILENO);
		else
			dup2(data.fd[0][0], STDIN_FILENO);
		dup2(data.fd[1][1], STDOUT_FILENO);
		fd_closer(&data, data.processes);
		data.exe = execve_arr_maker(data.paths, av[2 + data.mode], &data.error);
		if (!data.exe)
			return (ft_free_list(data.paths), print_errors(data.error));
		ft_free_list(data.paths);
		if (execve(data.exe[0], data.exe, NULL) == -1)
		{
			ft_free_list(data.exe);
			exit (1);
		}
	}

	if (data.processes > 2)
	{
		int	i;

		i = 1;
		while (i < data.processes - 1)
		{
			data.pid[i] = fork();
			if (data.pid[i] == -1)
				return (ft_free_list(data.paths), fd_closer(&data, data.processes), print_errors(FORK));
			if (data.pid[i] == 0)
			{
				dup2(data.fd[i][0], STDIN_FILENO);
				dup2(data.fd[i + 1][1], STDOUT_FILENO);
				fd_closer(&data, data.processes);
				data.exe = execve_arr_maker(data.paths, av[2 + i + data.mode], &data.error);
				if (!data.exe)
					return (ft_free_list(data.paths), print_errors(data.error));
				ft_free_list(data.paths);
				if (execve(data.exe[0], data.exe, NULL) == -1)
				{
					ft_free_list(data.exe);
					exit (1);
				}
			}
			i++;
		}
	}

	// Last Command block
	data.pid[data.processes - 1] = fork();
	if (data.pid[data.processes - 1] == -1)
		return (ft_free_list(data.paths), fd_closer(&data, data.processes), print_errors(FORK));
	if (data.pid[data.processes - 1] == 0)
	{
		dup2(data.fd[data.processes - 1][0], STDIN_FILENO);
		dup2(data.final_fd, STDOUT_FILENO);
		fd_closer(&data, data.processes);
		data.exe = execve_arr_maker(data.paths, av[ac - 2], &data.error);
		if (!data.exe)
			return (ft_free_list(data.paths), print_errors(data.error));
		ft_free_list(data.paths);
		if (execve(data.exe[0], data.exe, NULL) == -1)
		{
			ft_free_list(data.exe);
			exit (1);
		}
	}

	// Close every fd and free any memory here
	fd_closer(&data, data.processes);
	return (ft_free_list(data.paths), wait_all(&data, data.processes));
}


