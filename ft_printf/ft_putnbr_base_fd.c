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

static int	find_divider(int number, int base_number)
{
	int	i;
	int	n;
	int	base2;

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

static int	base_is_valid(char *base, int base_number)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	if (base_number <= 1)
		return (0);
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		i++;
	}
	while (base[i])
	{
		k = i + 1;
		while (base[k])
		{
			if (base[i] == base[k])
				return (0);
			k++;
		}
		i++;
	}
	return (1);
}

void	ft_putnbr_base_fd(int nbr, char *base, int fd)
{
	int	base_number;
	int	min_div;

	if (nbr < 0)
		write(1, "-", fd);
	if (nbr < 0)
		nbr = nbr * -1;
	base_number = 0;
	if (nbr == 0)
		write(1, &base[0], fd);
	if (nbr == 0)
		return ;
	while (base[base_number])
		base_number++;
	if (!base_is_valid(base, base_number))
		return ;
	min_div = find_divider(nbr, base_number);
	while (min_div != 1)
	{
		write(1, &base[nbr / min_div], fd);
		nbr = nbr % min_div;
		min_div = min_div / base_number;
	}
	write(1, &base[nbr / min_div], fd);
}
