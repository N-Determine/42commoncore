/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeters <adeters@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 13:43:35 by adeters           #+#    #+#             */
/*   Updated: 2025/01/09 11:06:12 by adeters          ###   ########.fr       */
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

	// !!! ONLY CHECK PATHS IF IT ISNT PUT INTO THE PROGRAMM ITSELF

	// Create the 2 necessary pipes
	if (pipe(data.fd[0]) == -1 | pipe(data.fd[1]) == -1)
	{
		ft_free_list(data.paths);
		return (print_errors(PIPE));
	}

	// First command block
	data.pid1 = fork();
	if (data.pid1 == -1)
		return (cleaner(data.fd, data.paths, data.final_fd), print_errors(FORK));
	if (data.pid1 == 0)
	{
		// Redirecting output
		dup2(data.fd[0][1], STDOUT_FILENO);
		close(data.fd[0][0]);
		close(data.fd[0][1]);
		// Redirecting input
		dup2(data.init_fd, STDIN_FILENO);
		close(data.fd[1][0]);
		close(data.fd[1][1]);
		close(data.init_fd);

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
	data.pid2 = fork();
	if (data.pid2 == -1)
		return (cleaner(data.fd, data.paths, data.final_fd), print_errors(FORK));
	if (data.pid2 == 0)
	{
		// Redirect input
		dup2(data.fd[0][0], STDIN_FILENO);
		close(data.fd[0][0]);
		close(data.fd[0][1]);
		// Redirect output
		dup2(data.fd[1][1], STDOUT_FILENO);
		close(data.fd[1][0]);
		close(data.fd[1][1]);
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

  	// Last Command block (from Mid command block 1)
	data.pid1 = fork();
	if (data.pid1 == -1)
		return (cleaner(data.fd, data.paths, data.final_fd), print_errors(FORK));
	if (data.pid1 == 0)
	{
		// Redirect input
		dup2(data.fd[1][0], STDIN_FILENO);
		close(data.fd[1][0]);
		close(data.fd[1][1]);
		// Redirect output
		close(data.fd[0][0]);
		close(data.fd[0][1]);
		dup2(data.final_fd, STDOUT_FILENO);
		close(data.final_fd);
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
	cleaner(data.fd, data.paths, data.final_fd);
	close(data.init_fd);
	
	// Wait for every single process here -> Make it a loop
	waitpid(data.pid1, &data.wstatus, 0);
	if (ft_wifexited(data.wstatus))
	{	
		ft_printf("Exit status child: %i\n", ft_wexitstatus(data.wstatus));
	}
	waitpid(data.pid2, &data.wstatus, 0);
	if (ft_wifexited(data.wstatus))
	{	
		ft_printf("Exit status child: %i\n", ft_wexitstatus(data.wstatus));
	}
	waitpid(data.pid1, &data.wstatus, 0);
	if (ft_wifexited(data.wstatus))
	{	
		ft_printf("Exit status child: %i\n", ft_wexitstatus(data.wstatus));
	}




	// Getting the exit status for the last execution
	// wait(&wstatus);
	// if (ft_wifexited(wstatus))
	// {	
	// 	ft_printf("Exit status child: %i\n", ft_wexitstatus(wstatus));
	// }
}
