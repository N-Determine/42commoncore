/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeters <adeters@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 16:14:34 by adeters           #+#    #+#             */
/*   Updated: 2025/01/15 18:40:44 by adeters          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	p_str_fd(int fd, char *str)
{
	write(fd, str, ft_strlen(str));
}

void	p_timestamp(t_data *data)
{
	unsigned int	elapsed;

	elapsed = time_passed(data);
	p_nbr_fd(1, elapsed);
}

void	p_log(t_data *data, int philo_nb, int action)
{
	p_timestamp(data);
	p_str_fd(1, "ms:\t");
	p_nbr_fd(1, philo_nb);
	if (action == FORK)
		p_str_fd(1, " has taken fork\n");
	if (action == EAT)
		p_str_fd(1, " is eating\n");
	if (action == SLEEP)
		p_str_fd(1, " is sleeping\n");
	if (action == THINK)
		p_str_fd(1, " is thinking\n");
	if (action == DIE)
		p_str_fd(1, " died\n");
}
