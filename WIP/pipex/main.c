/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeters <adeters@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 13:43:35 by adeters           #+#    #+#             */
/*   Updated: 2024/12/17 16:26:10 by adeters          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

#define ARG "ls -w"

// Pass the error as int * to controll the output
char	**execve_arr_maker(char **paths, char *arg, int *error)
{
	int		index;
	char	*tmp;
	char	**arr;

	arr = ft_split(arg, ' ');
	if (!arr)
		return (*error = SPLIT, NULL);
	index = check_access(paths, arr[0], X_OK);
	if (index < 0)
		return (*error = ACCESS, free(arr), NULL);
	tmp = allo_trip_strcat(paths[index], "/", arr[0]);
	if (!tmp)
		return (*error = MALLOC, free(arr), NULL);
	free(arr[0]);
	arr[0] = ft_strdup(tmp);
	free(tmp);
	return (arr);
}

int	main(int ac, const char **av, const char **env)
{
	char	**paths;
	char	**exe;
	int		error;

	paths = get_paths(env);
	if (!paths)
		return (print_errors(PATHS));
	exe = execve_arr_maker(paths, ARG, &error);
	if (!exe)
		return (print_errors(error));
	execve(exe[0], exe, NULL);
	ft_free_list(exe);
	ft_free_list(paths);
}
