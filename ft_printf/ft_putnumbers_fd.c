/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnumbers_fd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeters <adeters@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 14:29:51 by adeters           #+#    #+#             */
/*   Updated: 2024/09/18 14:32:34 by adeters          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libft.h"

int	ft_putnumbers_fd(char code, va_list list, int fd)
{
	int	i;

	i = 0;
	if (code == 'i' || code == 'd')
	{
		i = va_arg(list, int);
		ft_putnbr_fd(i, fd);
		return (ft_count_bytes(i));
	}
	else if (code == 'u')
		return (ft_putunbr_fd(va_arg(list, unsigned int), fd));
	return (-1);
}