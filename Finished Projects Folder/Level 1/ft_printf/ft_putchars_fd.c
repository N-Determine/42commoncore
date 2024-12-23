/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchars_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeters <adeters@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 14:30:19 by adeters           #+#    #+#             */
/*   Updated: 2024/09/25 12:56:23 by adeters          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	ft_putchars_fd(char code, va_list list, int fd)
{
	if (code == 'c')
		ft_putchar_fd((char)va_arg(list, int), fd);
	else if (code == '%')
		ft_putchar_fd('%', fd);
	return (1);
}
