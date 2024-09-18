/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchars_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeters <adeters@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 14:30:19 by adeters           #+#    #+#             */
/*   Updated: 2024/09/18 14:50:44 by adeters          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libft.h"

int	ft_putchars_fd(char code, va_list list)
{
	if (code == 'c')
		ft_putchar_fd((char)va_arg(list, int), 1);
	else if (code == '%')
		ft_putchar_fd('%', 1);
	return (1);
}
