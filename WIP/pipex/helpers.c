/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeters <adeters@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 16:35:12 by adeters           #+#    #+#             */
/*   Updated: 2025/01/11 17:14:18 by adeters          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_wifexited(int status)
{
	if ((status & 0x7f) == 0)
	{
		return (1);
	}
	return (0);
}

int	ft_wexitstatus(int status)
{
	return (((status) & 0xff00) >> 8);
}

int	write_mode(int code)
{
	if (code == 0)
		return (O_WRONLY | O_CREAT | O_TRUNC);
	return (O_WRONLY | O_CREAT | O_APPEND);
}

int	wait_all(t_data *data, int processes)
{
	int	i;

	i = 0;
	while (i < processes - 1)
	{
		wait(NULL);
		i++;
	}
	waitpid(data->pid[processes - 1], &data->wstatus, 0);
	if (ft_wifexited(data->wstatus))
		return (ft_wexitstatus(data->wstatus));
	return (1);
}
