/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeters <adeters@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 13:43:35 by adeters           #+#    #+#             */
/*   Updated: 2025/01/06 16:47:08 by adeters          ###   ########.fr       */
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
	int		wstatus;

	//if (ac < 5)
	//	return (print_errors(USAGE));

	
	paths = get_paths(env);
	if (!paths)
		return (print_errors(PATHS));
	// get stuff from a file using cat
	if (pipe(fd[0]) < 0)
	{
		ft_free_list(paths);
		return(print_errors(PIPE));
	}
	pid1 = fork();
	if (pid1 == -1)
	{
		ft_fprintf(2, "%s\n", strerror(errno));
		ft_free_list(paths);
	}
	if (pid1 == 0)
	{
		dup2(fd[0][1], STDOUT_FILENO);
		close(fd[0][0]);
		close(fd[0][1]);
		exe = execve_arr_maker(paths, av[1], &error);
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
		ft_fprintf(2, "%s\n", strerror(errno));
		ft_free_list(paths);
	}
	if (pid2 == 0)
	{
		dup2(fd[0][0], STDIN_FILENO);
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
	// Close the pipe once here
	close(fd[0][0]);
	close(fd[0][1]);
	
	// Wait for every single process here
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
	
	// wait(&wstatus);
	// if (ft_wifexited(wstatus))
	// {	
	// 	ft_printf("Exit status child: %i\n", ft_wexitstatus(wstatus));
	// }
	ft_free_list(paths);
}
