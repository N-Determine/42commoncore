/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeters <adeters@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 13:43:35 by adeters           #+#    #+#             */
/*   Updated: 2025/01/11 16:36:12 by adeters          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

#define AMOUNT 3

int	main(int ac, const char **av, const char **env)
{
	t_data	data;

	data.code = init_prog(&data, ac, av, env);
	if (data.code)
		return (data.code);
	
	// First command block
	data.pid[0] = fork();
	if (data.pid[0] == -1)
		return (ft_free_list(data.paths), fd_closer(&data, AMOUNT), print_errors(FORK));
	if (data.pid[0] == 0)
	{
		dup2(data.init_fd, STDIN_FILENO);
		dup2(data.fd[1][1], STDOUT_FILENO);
		fd_closer(&data, AMOUNT);
		data.exe = execve_arr_maker(data.paths, av[2], &data.error);
		if (!data.exe)
			return (ft_free_list(data.paths), print_errors(data.error));
		ft_free_list(data.paths);
		if (execve(data.exe[0], data.exe, NULL) == -1)
		{
			ft_free_list(data.exe);
			exit (1);
		}
	}

	// Mid command block 1 -> only use in bonus
	data.pid[1] = fork();
	if (data.pid[1] == -1)
		return (ft_free_list(data.paths), fd_closer(&data, AMOUNT), print_errors(FORK));
	if (data.pid[1] == 0)
	{
		dup2(data.fd[1][0], STDIN_FILENO);
		dup2(data.fd[2][1], STDOUT_FILENO);
		fd_closer(&data, AMOUNT);
		data.exe = execve_arr_maker(data.paths, av[3], &data.error);
		if (!data.exe)
			return (ft_free_list(data.paths), print_errors(data.error));
		ft_free_list(data.paths);
		if (execve(data.exe[0], data.exe, NULL) == -1)
		{
			ft_free_list(data.exe);
			exit (1);
		}
	}

	// Last Command block
	data.pid[ac - 2] = fork();
	if (data.pid[ac - 2] == -1)
		return (ft_free_list(data.paths), fd_closer(&data, AMOUNT), print_errors(FORK));
	if (data.pid[ac - 2] == 0)
	{
		dup2(data.fd[2][0], STDIN_FILENO);
		dup2(data.final_fd, STDOUT_FILENO);
		fd_closer(&data, AMOUNT);
		data.exe = execve_arr_maker(data.paths, av[4], &data.error);
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
	fd_closer(&data, AMOUNT);
	return (ft_free_list(data.paths), wait_all(&data, AMOUNT));
}


