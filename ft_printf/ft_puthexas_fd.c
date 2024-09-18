/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexas_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeters <adeters@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 14:30:43 by adeters           #+#    #+#             */
/*   Updated: 2024/09/18 14:35:59 by adeters          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libftprintf.h"

int	ft_puthexas_fd(char code, va_list list, int fd)
{
	long long	vptr;

	if (code == 'p')
	{
		vptr = (long long)va_arg(list, void *);
		if (vptr != 0)
		{
			ft_puthexaident_fd('x', fd);
			return (ft_putnbr_base_fd(vptr, "0123456789abcdef", fd) + 2);
		}
		else
		{
			ft_putstr_fd("(nil)", fd);
			return (0);
		}
	}
	else if (code == 'x')
		return (ft_putnbr_base_fd(va_arg(list, int), "0123456789abcdef", fd));
	else if (code == 'X')
		return (ft_putnbr_base_fd(va_arg(list, int), "0123456789ABCDEF", fd));
	return (-1);
}