/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeters <adeters@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 13:43:35 by adeters           #+#    #+#             */
/*   Updated: 2024/12/30 18:28:17 by adeters          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

#define ARG "ls"

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
	pid_t	p;
	int		error;

	paths = get_paths(env);
	if (!paths)
		return (print_errors(PATHS));
	p = fork();
	if (p == 0)
	{
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
	else if (p >= 1)
	{
		wait(NULL);
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
	else
	{
		ft_free_list(paths);
	}
}
