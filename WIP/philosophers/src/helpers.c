/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeters <adeters@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 16:38:47 by adeters           #+#    #+#             */
/*   Updated: 2025/01/16 15:47:18 by adeters          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include <stdio.h>

static int	ft_count_chars(int n);

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	p_nbr_fd(int fd, int n)
{
	char	nbr[10];
	int		chars;
	int		i;
	int		first_ind;
	long	long_n;

	long_n = (long)n;
	chars = ft_count_chars(long_n);
	first_ind = 10 - chars;
	if (long_n < 0)
	{
		write(fd, "-", 1);
		long_n = long_n * (-1);
	}
	i = 0;
	if (long_n == 0)
		write (fd, "0", 1);
	while (long_n > 0)
	{
		nbr[(first_ind + (chars - 1)) - i] = long_n % 10 + '0';
		long_n = long_n / 10;
		i++;
	}
	write(fd, &nbr[first_ind], chars);
}

static int	ft_count_chars(int n)
{
	int	chars;

	chars = 0;
	if (n == 0)
		chars = 0;
	while (n)
	{
		n = n / 10;
		chars++;
	}
	return (chars);
}

unsigned int	time_passed(t_data *data)
{
	double	elapsed;

	if (gettimeofday(&data->curr, NULL) == -1)
		return (0);
	elapsed = (data->curr.tv_sec - data->start.tv_sec) + ((data->curr.tv_usec
				- data->start.tv_usec) / 1000000.0);
	return (1000 * elapsed);
}

int	ft_atoi(const char *nptr)
{
	int	sign;
	int	nmb;
	int	i;

	sign = 1;
	nmb = 0;
	i = 0;
	while (nptr[i] && (nptr[i] == 32 || (nptr[i] >= 9 && nptr[i] <= 13)))
		i++;
	if (nptr[i] == '+')
		i++;
	else if (nptr[i] == '-')
	{
		sign = -1;
		i++;
	}
	if (!(nptr[i] >= '0' && nptr[i] <= '9'))
		return (0);
	while (nptr[i] && (nptr[i] >= '0' && nptr[i] <= '9'))
	{
		nmb = nmb * 10 + (nptr[i] - 48);
		i++;
	}
	return (nmb * sign);
}
