/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeters <adeters@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 13:52:34 by adeters           #+#    #+#             */
/*   Updated: 2025/01/14 18:06:38 by adeters          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	first_command(t_data *data, const char **av)
{
	data->pid[0] = fork();
	if (data->pid[0] == -1)
	{
		fr_lst(data->paths);
		return (fd_cl(data, data->procs), p_err(FORK));
	}
	if (data->pid[0] == 0)
		return (first_help(data, av));
	return (0);
}

int	first_help(t_data *data, const char **av)
{
	if (data->mode == 0)
	{
		if (access(av[1], R_OK) != 0)
			return (stop_it(data, PERM, av[1]));
		data->init_fd = open(av[1], O_RDONLY, 0644);
		if (data->init_fd == -1)
			return (stop_it(data, OPEN, av[1]));
		if (dup2(data->init_fd, STDIN_FILENO) == -1)
			return (stop_it(data, DUP, NULL));
	}
	else
	{
		if (dup2(data->fd[0][0], STDIN_FILENO) == -1)
			return (stop_it(data, DUP, NULL));
	}
	if (dup2(data->fd[1][1], STDOUT_FILENO) == -1)
		return (stop_it(data, DUP, NULL));
	fd_cl(data, data->procs);
	data->exe = mk_exe(data->paths, av[2 + data->mode], &data->error);
	fr_lst(data->paths);
	if (!data->exe)
		return (exit(p_err_arg(data->error, av[2 + data->mode])), 0);
	if (execve(data->exe[0], data->exe, NULL) == -1)
		return (fr_lst(data->exe), exit(p_err(EXEC)), 0);
	return (0);
}

int	mid_commands(t_data *data, const char **av, int i)
{
	data->pid[i] = fork();
	if (data->pid[i] == -1)
		return (fr_lst(data->paths), fd_cl(data, data->procs), p_err(FORK));
	if (data->pid[i] == 0)
	{
		if (dup2(data->fd[i][0], STDIN_FILENO) == -1)
			return (stop_it(data, DUP, NULL));
		if (dup2(data->fd[i + 1][1], STDOUT_FILENO) == -1)
			return (stop_it(data, DUP, NULL));
		fd_cl(data, data->procs);
		data->exe = mk_exe(data->paths, av[2 + i + data->mode], &data->error);
		fr_lst(data->paths);
		if (!data->exe)
			exit(p_err_arg(data->error, av[2 + i + data->mode]));
		if (execve(data->exe[0], data->exe, NULL) == -1)
			return (fr_lst(data->exe), exit(p_err(EXEC)), 0);
	}
	return (0);
}

int	last_command(t_data *data, const char **av, int ac)
{
	data->pid[data->procs - 1] = fork();
	if (data->pid[data->procs - 1] == -1)
	{
		fr_lst(data->paths);
		return (fd_cl(data, data->procs), p_err(FORK));
	}
	if (data->pid[data->procs - 1] == 0)
		return (last_help(data, av, ac));
	return (0);
}

int	last_help(t_data *data, const char **av, int ac)
{
	if (access(av[ac - 1], W_OK) != 0 && access(av[ac - 1], F_OK) == 0)
		return (stop_it(data, PERM, av[ac - 1]));
	data->final_fd = open(av[ac - 1], write_mode(data->mode), 0644);
	if (data->final_fd == -1)
		return (stop_it(data, OPEN, NULL));
	if (dup2(data->fd[data->procs - 1][0], STDIN_FILENO) == -1)
		return (stop_it(data, DUP, NULL));
	if (dup2(data->final_fd, STDOUT_FILENO) == -1)
		return (stop_it(data, DUP, NULL));
	fd_cl(data, data->procs);
	data->exe = mk_exe(data->paths, av[ac - 2], &data->error);
	fr_lst(data->paths);
	if (!data->exe)
		exit(p_err_arg(data->error, av[ac - 2]));
	if (execve(data->exe[0], data->exe, NULL) == -1)
		return (fr_lst(data->exe), exit(p_err(EXEC)), 0);
	return (0);
}
