/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeters <adeters@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 13:52:34 by adeters           #+#    #+#             */
/*   Updated: 2025/01/12 16:30:22 by adeters          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	first_command(t_data *data, const char **av)
{
	data->pid[0] = fork();
	if (data->pid[0] == -1)
	{
		ft_free_list(data->paths);
		return (fd_closer(data, data->procs), print_errors(FORK));
	}
	if (data->pid[0] == 0)
	{
		if (data->mode == 0)
			dup2(data->init_fd, STDIN_FILENO);
		else
			dup2(data->fd[0][0], STDIN_FILENO);
		dup2(data->fd[1][1], STDOUT_FILENO);
		fd_closer(data, data->procs);
		data->exe = execve_arr_maker(data->paths, av[2 + data->mode], &data->error);
		ft_free_list(data->paths);
		if (!data->exe)
			return (print_errors(data->error));
		if (execve(data->exe[0], data->exe, NULL) == -1)
		{
			ft_free_list(data->exe);
			exit(print_errors(EXEC));
		}
	}
	return (0);
}

int	mid_commands(t_data *data, const char **av, int i)
{
	data->pid[i] = fork();
	if (data->pid[i] == -1)
		return (ft_free_list(data->paths), fd_closer(data, data->procs), print_errors(FORK));
	if (data->pid[i] == 0)
	{
		dup2(data->fd[i][0], STDIN_FILENO);
		dup2(data->fd[i + 1][1], STDOUT_FILENO);
		fd_closer(data, data->procs);
		data->exe = execve_arr_maker(data->paths, av[2 + i + data->mode], &data->error);
		ft_free_list(data->paths);
		if (!data->exe)
			return (print_errors(data->error));
		if (execve(data->exe[0], data->exe, NULL) == -1)
		{
			ft_free_list(data->exe);
			exit(print_errors(EXEC));
		}
	}
	return (0);
}

int	last_command(t_data *data, const char **av, int ac)
{
	data->pid[data->procs - 1] = fork();
	if (data->pid[data->procs - 1] == -1)
	{
		ft_free_list(data->paths);
		return (fd_closer(data, data->procs), print_errors(FORK));
	}
	if (data->pid[data->procs - 1] == 0)
	{
		dup2(data->fd[data->procs - 1][0], STDIN_FILENO);
		dup2(data->final_fd, STDOUT_FILENO);
		fd_closer(data, data->procs);
		data->exe = execve_arr_maker(data->paths, av[ac - 2], &data->error);
		ft_free_list(data->paths);
		if (!data->exe)
			return (print_errors(data->error));
		if (execve(data->exe[0], data->exe, NULL) == -1)
		{
			ft_free_list(data->exe);
			exit(print_errors(EXEC));
		}
	}
	return (0);
}
