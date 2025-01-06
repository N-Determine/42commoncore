/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeters <adeters@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 13:43:35 by adeters           #+#    #+#             */
/*   Updated: 2025/01/06 17:54:43 by adeters          ###   ########.fr       */
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
	tmp = allo_trip_strcat(paths[index], "/", arr[0]);
	if (!tmp)
		return (*error = MALLOC, ft_free_list(arr), NULL);
	free(arr[0]);
	arr[0] = ft_strdup(tmp);
	if (!arr[0])
		return (*error = MALLOC, ft_free_list(arr), NULL);
	free(tmp);
	return (arr);
}

int	main(int ac, const char **av, const char **env)
{
	char	**paths;
	char	**exe;
	int		pid1;
	int		pid2;
	int		error;
	int		fd[2][2];
	int		final_fd;
	int		init_fd;
	int		wstatus;
	int		mode;


	// Usage Protection
	//if (ac < 5)
	//	return (print_errors(USAGE));


	// Only in bonus! Change the write mode for the final file
	if (ft_strncmp(av[1], "here_doc", 8) == 0)
		mode = 0;
	else
		mode = 1;

	// Making the fds for the file to read and to write to
	final_fd = open(av[ac - 1], write_mode(mode), 0644); // Protect
	init_fd = open(av[1], O_RDONLY, 0644); // Protect

	// Getting the paths for the binarys
	paths = get_paths(env);
	if (!paths)
		return (print_errors(PATHS));









	if (pipe(fd[0]) == -1 | pipe(fd[1]) == -1)
	{
		ft_free_list(paths);
		return (print_errors(PIPE));
	}
	pid1 = fork();
	if (pid1 == -1)
	{
		close(final_fd);
		close(fd[0][0]);
		close(fd[0][1]);
		close(fd[1][0]);
		close(fd[1][1]);
		ft_free_list(paths);
		return (print_errors(FORK));
	}
	if (pid1 == 0)
	{
		
		// Redirecting to write into stdout
		dup2(fd[0][1], STDOUT_FILENO);
		close(fd[0][0]);
		close(fd[0][1]);


		
		exe = execve_arr_maker(paths, av[2], &error);
		if (!exe)
			return (ft_free_list(paths), print_errors(error));
		ft_free_list(paths);
		if (execve(exe[0], exe, NULL) == -1)
		{
			ft_free_list(exe);
			exit (1);
		}
	}
	
	pid2 = fork();
	if (pid2 == -1)
	{
		close(final_fd);
		close(fd[0][0]);
		close(fd[0][1]);
		close(fd[1][0]);
		close(fd[1][1]);
		ft_free_list(paths);
		return (print_errors(FORK));
	}
	if (pid2 == 0)
	{
		// Redirect input
		dup2(fd[0][0], STDIN_FILENO);
		close(fd[0][0]);
		close(fd[0][1]);
		// Redirect output
		dup2(fd[1][1], STDOUT_FILENO);
		close(fd[1][0]);
		close(fd[1][1]);
		exe = execve_arr_maker(paths, av[3], &error);
		if (!exe)
			return (ft_free_list(paths), print_errors(error));
		ft_free_list(paths);
		if (execve(exe[0], exe, NULL) == -1)
		{
			ft_free_list(exe);
			exit (1);
		}
	}
	pid1 = fork();
	if (pid1 == -1)
	{
		close(final_fd);
		close(fd[0][0]);
		close(fd[0][1]);
		close(fd[1][0]);
		close(fd[1][1]);
		ft_free_list(paths);
		return (print_errors(FORK));
	}
	if (pid1 == 0)
	{
		// Redirect input
		dup2(fd[1][0], STDIN_FILENO);
		close(fd[1][0]);
		close(fd[1][1]);
		// Redirect output
		dup2(final_fd, STDOUT_FILENO);
		close(fd[0][0]);
		close(fd[0][1]);
		close(final_fd);
		exe = execve_arr_maker(paths, av[4], &error);
		if (!exe)
			return (ft_free_list(paths), print_errors(error));
		ft_free_list(paths);
		if (execve(exe[0], exe, NULL) == -1)
		{
			ft_free_list(exe);
			exit (1);
		}
	}

	// Close every fd and free any memory here
	close(fd[0][0]);
	close(fd[0][1]);
	close(fd[1][0]);
	close(fd[1][1]);
	close(init_fd);
	close(final_fd);
	ft_free_list(paths);
	
	// Wait for every single process here -> Make it a loop
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
	waitpid(pid1, NULL, 0);





	// Getting the exit status for the last execution
	// wait(&wstatus);
	// if (ft_wifexited(wstatus))
	// {	
	// 	ft_printf("Exit status child: %i\n", ft_wexitstatus(wstatus));
	// }
}
