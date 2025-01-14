/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeters <adeters@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 13:43:35 by adeters           #+#    #+#             */
/*   Updated: 2025/01/14 18:25:00 by adeters          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	main(int ac, const char **av, const char **env)
{
	t_data	data;

	data.error = init_prog(&data, ac, av, env);
	if (data.error)
		return (data.error);
	if (pipe_maker(&data, data.procs))
		return (fd_cl(&data, 0), fr_lst(data.paths), PIPE);
	if (data.mode == 1 && get_here_doc(&data, av))
		return (fd_cl(&data, data.procs), fr_lst(data.paths), GNL);
	data.error = first_command(&data, av);
	if (data.error)
		return (fd_cl(&data, data.procs), fr_lst(data.paths), data.error);
	data.index = 1;
	while (data.index < data.procs - 1 && data.procs > 2)
	{
		data.error = mid_commands(&data, av, data.index);
		if (data.error)
			return (fd_cl(&data, data.procs), fr_lst(data.paths), data.error);
		data.index++;
	}
	data.error = last_command(&data, av, ac);
	if (data.error)
		return (fd_cl(&data, data.procs), fr_lst(data.paths), data.error);
	fd_cl(&data, data.procs);
	return (fr_lst(data.paths), wait_all(&data, data.procs));
}
