/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeters <adeters@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 18:39:29 by adeters           #+#    #+#             */
/*   Updated: 2024/09/15 19:06:46 by adeters          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static long long	find_divider(long long number, long long base_number)
{
	long long	i;
	long long	n;
	long long	base2;

	i = 0;
	n = base_number;
	base2 = base_number;
	while (number / base_number)
	{
		i++;
		base_number = base_number * n;
	}
	i = i - 1;
	while (i-- > 0)
		base2 = base2 * n;
	return (base2);
}
void	ft_putnbr_base_fd(long long nbr, char *base, int fd)
{
	long long	min_div;
	if (nbr < 0)
		write(fd, "-", 1);
	if (nbr < 0)
		nbr = nbr * -1;
	if (nbr == 0)
	{
		write(fd, &base[0], 1);
		return ;
	}
	min_div = find_divider(nbr, 16);
	while (min_div != 1)
	{
		write(1, &base[nbr / min_div], fd);
		nbr = nbr % min_div;
		min_div = min_div / 16;
	}
	write(fd, &base[nbr], 1);
}
