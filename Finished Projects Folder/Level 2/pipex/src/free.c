/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeters <adeters@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 16:09:05 by adeters           #+#    #+#             */
/*   Updated: 2025/01/15 13:52:47 by adeters          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	fr_lst(char **arr)
{
	int	i;

	i = 0;
	if (arr)
	{
		while (arr[i])
		{
			free(arr[i]);
			i++;
		}
		free(arr);
		arr = NULL;
	}
}

void	fd_cl(t_data *data, int pipes_open)
{
	int	i;

	i = 0;
	if (data->init_fd != -1)
		close(data->init_fd);
	if (data->final_fd != -1)
		close(data->final_fd);
	while (i < pipes_open)
	{
		close(data->fd[i][0]);
		close(data->fd[i][1]);
		i++;
	}
}

int	stop_it(t_data *data, int err, const char *arg)
{
	fr_lst(data->paths);
	fd_cl(data, data->procs);
	if (arg)
		exit (p_err_arg(err, arg));
	else
		exit (p_err(err));
	return (0);
}
