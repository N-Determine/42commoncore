/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeters <adeters@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 15:50:53 by adeters           #+#    #+#             */
/*   Updated: 2025/01/11 15:52:41 by adeters          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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

int	pipe_maker(t_data *data, int pipes_amt)
{
	int	i;

	i = 0;
	while (i < pipes_amt)
	{
		if (pipe(data->fd[i]) == -1)
			return (fd_closer(data, i), 0);
		i++;
	}
	return (1);
}
