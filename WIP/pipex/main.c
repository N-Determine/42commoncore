/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeters <adeters@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 13:43:35 by adeters           #+#    #+#             */
/*   Updated: 2025/01/11 15:48:40 by adeters          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// Pass the error as int * to controll the output
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

void	fd_closer(t_data *data, int pipes_open)
{
	int	i;

	i = 0;
	close(data->init_fd);
	close(data->final_fd);
	while (i < pipes_open)
	{
		close(data->fd[i][0]);
		close(data->fd[i][1]);
		i++;
	}
}

int	pipe_maker(t_data *data, int pipes_amt)
{
	int i;

	i = 0;
	while (i < pipes_amt)
	{
		if (pipe(data->fd[i]) == -1)
			return (fd_closer(data, i), 0);
		i++;
	}
	return (1);
}

#define AMOUNT 4

int	main(int ac, const char **av, const char **env)
{
	t_data data;

	// Usage Protection
	if (ac < 5)
		return (print_errors(USAGE));

	// Only in bonus! Change the write mode for the final file
	if (ft_strncmp(av[1], "here_doc", 8) == 0)
		data.mode = 0;
	else
		data.mode = 1;

	// Making the fds for the file to read and to write to
	data.final_fd = open(av[ac - 1], write_mode(data.mode), 0644);
	if (data.final_fd == -1)
		return (1);
	data.init_fd = open(av[1], O_RDONLY, 0644);
	if (data.init_fd == -1)
		return (1);

	// Getting the paths for the binarys
	data.paths = get_paths(env);
	if (!data.paths)
		return (print_errors(PATHS));


	// Create the 2 necessary pipes
	if (!pipe_maker(&data, AMOUNT))
		return (ft_free_list(data.paths), print_errors(PIPE));

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
	
	// Mid command block 1
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
	data.pid[2] = fork();
	if (data.pid[2] == -1)
		return (ft_free_list(data.paths), fd_closer(&data, AMOUNT), print_errors(FORK));
	if (data.pid[2] == 0)
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
	close(data.init_fd);
	fd_closer(&data, AMOUNT);
	ft_free_list(data.paths);
	// Wait for every single process here -> Make it a loop

	wait(NULL);
	waitpid(data.pid[2], &data.wstatus, 0);
	if (ft_wifexited(data.wstatus))
		return (ft_wexitstatus(data.wstatus));
}


