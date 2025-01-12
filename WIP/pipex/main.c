/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeters <adeters@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 13:43:35 by adeters           #+#    #+#             */
/*   Updated: 2025/01/12 13:46:09 by adeters          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int first_command(t_data *data, const char **av)
{
	data->pid[0] = fork();
	if (data->pid[0] == -1)
		return (ft_free_list(data->paths), fd_closer(data, data->procs), print_errors(FORK));
	if (data->pid[0] == 0)
	{
		if (data->mode == 0)
			dup2(data->init_fd, STDIN_FILENO);
		else
			dup2(data->fd[0][0], STDIN_FILENO);
		dup2(data->fd[1][1], STDOUT_FILENO);
		fd_closer(data, data->procs);
		// Check if error handling still works here
		data->exe = execve_arr_maker(data->paths, av[2 + data->mode], &data->error);
		if (!data->exe)
			return (ft_free_list(data->paths), print_errors(data->error));
		ft_free_list(data->paths);
		if (execve(data->exe[0], data->exe, NULL) == -1)
		{
			ft_free_list(data->exe);
			// Change this value maybe
			return (1);
		}
	}
	return (0);
}

int mid_commands(t_data *data, const char **av)
{
	int i;

	if (data->procs > 2)
	{
		i = 1;
		while (i < data->procs - 1)
		{
			data->pid[i] = fork();
			if (data->pid[i] == -1)
				return (ft_free_list(data->paths), fd_closer(data, data->procs), print_errors(FORK));
			if (data->pid[i] == 0)
			{
				dup2(data->fd[i][0], STDIN_FILENO);
				dup2(data->fd[i + 1][1], STDOUT_FILENO);
				fd_closer(data, data->procs);
				// Check if error handling still works here
				data->exe = execve_arr_maker(data->paths, av[2 + i + data->mode], &data->error);
				if (!data->exe)
					return (ft_free_list(data->paths), print_errors(data->error));
				ft_free_list(data->paths);
				if (execve(data->exe[0], data->exe, NULL) == -1)
				{
					ft_free_list(data->exe);
					// Change this value maybe
					return (1);
				}
			}
			i++;
		}
	}
	return (0);
}

int	main(int ac, const char **av, const char **env)
{
	t_data	data;

	data.code = init_prog(&data, ac, av, env);
	if (data.code)
		return (data.code);
	
	if (pipe_maker(&data, data.procs))
		return (fd_closer(&data, 0), ft_free_list(data.paths), PIPE);
	if (data.mode == 1 && get_here_doc(&data, av))
		return (fd_closer(&data, data.procs), ft_free_list(data.paths), GNL);


	data.code = first_command(&data, av);
	if (data.code)
		return (data.code);
	data.code = mid_commands(&data, av);
	if (data.code)
		return (data.code);
	


	// Last Command block
	data.pid[data.procs - 1] = fork();
	if (data.pid[data.procs - 1] == -1)
		return (ft_free_list(data.paths), fd_closer(&data, data.procs), print_errors(FORK));
	if (data.pid[data.procs - 1] == 0)
	{
		dup2(data.fd[data.procs - 1][0], STDIN_FILENO);
		dup2(data.final_fd, STDOUT_FILENO);
		fd_closer(&data, data.procs);
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

	fd_closer(&data, data.procs);
	return (ft_free_list(data.paths), wait_all(&data, data.procs));
}


