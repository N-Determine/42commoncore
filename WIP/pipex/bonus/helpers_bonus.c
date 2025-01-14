/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeters <adeters@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 16:35:12 by adeters           #+#    #+#             */
/*   Updated: 2025/01/14 18:21:46 by adeters          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

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
		waitpid(data->pid[i], NULL, 0);
		i++;
	}
	waitpid(data->pid[i], &data->wstatus, 0);
	if (WIFEXITED(data->wstatus))
		return (WEXITSTATUS(data->wstatus));
	return (1);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	if (!s1 || !s2)
		return (0);
	i = 0;
	while (s1[i])
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	while (s2[i])
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}
