/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeters <adeters@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 21:02:23 by adeters           #+#    #+#             */
/*   Updated: 2024/11/16 18:53:36 by adeters          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_errors(int code)
{
	ft_fprintf(2, "Error\n");
	if (code == USAGE)
		ft_fprintf(2, "Usage: ./push_swap [int-0] [int-1] ... [int-n] \n");
}
