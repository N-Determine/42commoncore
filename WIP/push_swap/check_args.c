/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeters <adeters@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 18:42:44 by adeters           #+#    #+#             */
/*   Updated: 2024/12/02 20:46:35 by adeters          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_args(int ac, char **av, t_fails *fails, int str_in)
{
	int	i;
	int	current;

	i = 1 - str_in;
	init_fails(fails);
	while (i < ac)
	{
		current = check_overflow(av[i]);
		if (current == 1)
			fails->overflows++;
		if (current == -1)
			fails->underflows++;
		if (current == -2)
			fails->formats++;
		i++;
	}
	if (fails->overflows > 0 || fails->underflows > 0)
		return (1);
	if (fails->formats > 0)
		return (1);
	return (0);
}
