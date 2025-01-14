/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeters <adeters@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 16:35:12 by adeters           #+#    #+#             */
/*   Updated: 2025/01/14 20:37:25 by adeters          ###   ########.fr       */
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

char	*allo_strcat(const char *s1, const char *s2)
{
	int		size;
	char	*res;
	int		i;
	int		j;

	if (!s1 | !s2)
		return (NULL);
	size = ft_strlen(s1) + ft_strlen(s2) + 1;
	res = ft_calloc(size, sizeof(char));
	if (!res)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		res[i] = s2[j];
		i++;
		j++;
	}
	return (res);
}

char	*allo_trip_strcat(const char *s1, const char *s2, const char *s3)
{
	char	*tmp;
	char	*res;

	if (!s1 | !s2 | !s3)
		return (NULL);
	tmp = allo_strcat(s1, s2);
	if (!tmp)
		return (NULL);
	res = allo_strcat(tmp, s3);
	if (!res)
		return (free(tmp), NULL);
	return (free(tmp), res);
}
