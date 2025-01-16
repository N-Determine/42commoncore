/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeters <adeters@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 16:03:52 by adeters           #+#    #+#             */
/*   Updated: 2025/01/16 17:04:33 by adeters          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	parse_args(t_data *data, int ac, char **av)
{
	// Look for proper limitations for these values
	if (ac < 5 || ac > 6)
		return (data->error = USAGE);
	data->nbp = ft_atoi(av[1]);
	data->ttd = ft_atoi(av[2]);
	data->tte = ft_atoi(av[3]);
	data->tts = ft_atoi(av[4]);
	if (ac > 5)
		data->nbte = ft_atoi(av[5]);
	else
		data->nbte = -1;
	return (0);
}

int	init_prog(t_data *data, int ac, char **av)
{
	if (parse_args(data, ac, av))
		return (data->error);
	return (0);
}

int	main(int ac, char **av)
{
	t_data	data;

	// Use this code block as soon as the simulation starts
	// so that the first timestamp is 0
	if (gettimeofday(&data.start, NULL) < 0)
		return (GTOD);

	if (init_prog(&data, ac, av))
		return (p_err(data.error));
	usleep(213 * 1000);
	p_log(&data, 5, FORK);
}
