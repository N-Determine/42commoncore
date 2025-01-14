/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeters <adeters@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 13:43:35 by adeters           #+#    #+#             */
/*   Updated: 2025/01/14 20:40:21 by adeters          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, const char **av, const char **env)
{
	t_data	data;

	data.error = init_prog(&data, ac, env);
	if (data.error)
		return (data.error);
	if (pipe_maker(&data, data.procs))
		return (fd_cl(&data, 0), fr_lst(data.paths), PIPE);
	data.error = cmd1(&data, av);
	if (data.error)
		return (fd_cl(&data, data.procs), fr_lst(data.paths), data.error);
	data.error = cmd2(&data, av, ac);
	if (data.error)
		return (fd_cl(&data, data.procs), fr_lst(data.paths), data.error);
	fd_cl(&data, data.procs);
	return (fr_lst(data.paths), wait_all(&data, data.procs));
}
