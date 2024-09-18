/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_foo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeters <adeters@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 21:07:03 by adeters           #+#    #+#             */
/*   Updated: 2024/09/18 21:26:56 by adeters          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_init_flags(t_bonus_flags *flag)
{
	flag->hexa_ident = 0;
	flag->plus_ident = 0;
	flag->space_ident = 0;
}

void	ft_check_flags(t_bonus_flags *flag, char flag_code)
{
	if (flag_code == '#')
		flag->hexa_ident = 1;
	if (flag_code == '+')
		flag->plus_ident = 1;
	if (flag_code == ' ')
		flag->space_ident = 1;
}
