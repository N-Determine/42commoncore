/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeters <adeters@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 13:43:35 by adeters           #+#    #+#             */
/*   Updated: 2025/01/12 16:36:43 by adeters          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, const char **av, const char **env)
{
	t_data	data;

	// The commands shoud never return anything unless fork fails!
	// instead of letting them return anything they should exit
	// Chaning data->error in them will not change shit because it is in another
	// process
	// the thing in the waitall will not work as execve was never exectued


	data.code = init_prog(&data, ac, av, env);
	if (data.code)
		return (data.code);
	if (pipe_maker(&data, data.procs))
		return (fd_closer(&data, 0), ft_free_list(data.paths), PIPE);
	if (data.mode == 1 && get_here_doc(&data, av))
		return (fd_closer(&data, data.procs), ft_free_list(data.paths), GNL);
	data.code = first_command(&data, av);
	if (data.code)
		return (data.code);
	data.index = 1;
	while (data.index < data.procs - 1 && data.procs > 2)
	{
		data.code = mid_commands(&data, av, data.index);
		if (data.code)
			return (data.code);
		data.index++;
	}
	data.code = last_command(&data, av, ac);
	if (data.code)
		return (data.code);
	fd_closer(&data, data.procs);
	return (ft_free_list(data.paths), wait_all(&data, data.procs));
}
