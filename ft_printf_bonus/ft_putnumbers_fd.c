/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnumbers_fd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeters <adeters@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 14:29:51 by adeters           #+#    #+#             */
/*   Updated: 2024/09/18 22:07:42 by adeters          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	ft_putnumbers_fd(char code, va_list list, t_bonus_flags flag, int fd)
{
	int	i;
	int	extra_byte;

	i = 0;
	extra_byte = 0;
	if (code == 'i' || code == 'd')
	{
		i = va_arg(list, int);
		if (flag.plus_ident == 1 && i >= 0)
		{
			write(fd, "+", 1);
			extra_byte = 1;
		}
		else if (flag.space_ident == 1 && i >= 0)
		{
			write(fd, " ", 1);
			extra_byte = 1;
		}
		ft_putnbr_fd(i, fd);
		return (ft_count_bytes(i));
	}
	else if (code == 'u')
		return (ft_putunbr_fd(va_arg(list, unsigned int), fd) + extra_byte);
	return (-1);
}
