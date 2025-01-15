/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeters <adeters@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 16:03:52 by adeters           #+#    #+#             */
/*   Updated: 2025/01/15 18:46:01 by adeters          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	init_prog(t_data *data)
{
	gettimeofday(&data->start, NULL);
	return (0);
}

int	main(void)
{
	t_data	data;

	if (init_prog(&data))
		return (1);
	usleep(213 * 1000);
	p_log(&data, 5, FORK);
}
