/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeters <adeters@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 21:02:23 by adeters           #+#    #+#             */
/*   Updated: 2024/11/18 16:22:05 by adeters          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_errors_args(int code, t_fails *fails)
{
	ft_fprintf(2, "Error\n");
	if (code == ARGS)
	{
		if (fails->overflows > 1)
			ft_fprintf(2, "%i inputs overflowing an integer\n",
				fails->overflows);
		else if (fails->overflows > 0)
			ft_fprintf(2, "1 input overflowing an integer\n");
		if (fails->underflows > 1)
			ft_fprintf(2, "%i inputs underflowing an integer\n",
				fails->underflows);
		else if (fails->underflows > 0)
			ft_fprintf(2, "1 input underflowing an integer\n");
		if (fails->formats > 1)
			ft_fprintf(2, "%i inputs with formatting error\n", fails->formats);
		else if (fails->formats > 0)
			ft_fprintf(2, "1 input with formatting error\n");
		if (fails->duplicates > 0)
			ft_fprintf(2, "Input contains at least one duplicate\n");
	}
}

void	print_errors(int code)
{
	ft_fprintf(2, "Error\n");
	if (code == MAL_SORTED)
		ft_fprintf(2, "Malloc failed allocating the \"sorted\" array\n");
}
