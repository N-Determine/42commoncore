/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeters <adeters@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 13:52:34 by adeters           #+#    #+#             */
/*   Updated: 2025/01/15 13:52:12 by adeters          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	cmd1(t_data *data, const char **av)
{
	data->pid[0] = fork();
	if (data->pid[0] == -1)
	{
		fr_lst(data->paths);
		return (fd_cl(data, data->procs), p_err(FORK));
	}
	if (data->pid[0] == 0)
		return (cmd1_help(data, av));
	return (0);
}

int	cmd1_help(t_data *data, const char **av)
{
	if (access(av[1], F_OK) == 0 && access(av[1], R_OK) != 0)
		return (stop_it(data, PERM, av[1]));
	data->init_fd = open(av[1], O_RDONLY);
	if (data->init_fd == -1)
		return (stop_it(data, OPEN, av[1]));
	if (dup2(data->init_fd, STDIN_FILENO) == -1)
		return (stop_it(data, DUP, NULL));
	if (dup2(data->fd[1][1], STDOUT_FILENO) == -1)
		return (stop_it(data, DUP, NULL));
	fd_cl(data, data->procs);
	data->exe = mk_exe(data->paths, av[2], &data->error);
	fr_lst(data->paths);
	if (!data->exe)
		return (exit(p_err_arg(data->error, av[2])), 0);
	if (execve(data->exe[0], data->exe, NULL) == -1)
		return (fr_lst(data->exe), exit(p_err(EXEC)), 0);
	return (0);
}

int	cmd2(t_data *data, const char **av, int ac)
{
	data->pid[data->procs - 1] = fork();
	if (data->pid[data->procs - 1] == -1)
	{
		fr_lst(data->paths);
		return (fd_cl(data, data->procs), p_err(FORK));
	}
	if (data->pid[data->procs - 1] == 0)
		return (cmd2_help(data, av, ac));
	return (0);
}

int	cmd2_help(t_data *data, const char **av, int ac)
{
	if (access(av[ac - 1], W_OK) != 0 && access(av[ac - 1], F_OK) == 0)
		return (stop_it(data, PERM, av[ac - 1]));
	data->final_fd = open(av[ac - 1], O_WRONLY | O_CREAT | O_TRUNC);
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
