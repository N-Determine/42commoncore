/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftw.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeters <adeters@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 16:35:12 by adeters           #+#    #+#             */
/*   Updated: 2025/01/05 16:35:33 by adeters          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int ft_wifexited(int status)
{
	if ((status & 0x7f) == 0)
	{
		return (1);
	}
	return (0);
}

int ft_wexitstatus(int status)
{
	return (((status) & 0xff00) >> 8);
}
