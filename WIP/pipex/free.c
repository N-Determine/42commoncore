/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeters <adeters@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 16:09:05 by adeters           #+#    #+#             */
/*   Updated: 2025/01/11 15:50:14 by adeters          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_free_list(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
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
