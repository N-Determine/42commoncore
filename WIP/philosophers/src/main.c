/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeters <adeters@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 16:03:52 by adeters           #+#    #+#             */
/*   Updated: 2025/01/16 15:32:33 by adeters          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	init_prog(t_data *data, int ac, char **av)
{
	gettimeofday(&data->start, NULL);
	return (0);
}

int	main(int ac, char **av)
{
	t_data	data;

	// Add ft_atoi to parse the inputs properly
	// Then parse them within the init_prog function

	if (init_prog(&data, ac, av))
		return (1);
	usleep(213 * 1000);
	p_log(&data, 5, FORK);
}
