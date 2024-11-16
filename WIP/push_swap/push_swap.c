/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeters <adeters@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 20:38:40 by adeters           #+#    #+#             */
/*   Updated: 2024/11/16 18:37:42 by adeters          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	check_args(int ac, char **av, t_fails *fails)
{
	int	i;
	int	current;

	i = 1;
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

int	main(int ac, char **av)
{
	t_fails fails;

	init_fails(&fails);
	if (ac < 2)
		return (print_errors(ARGS), 1);
	check_args(ac, av, &fails);
	printf("Underflows: %zu\n", fails.underflows); fflush(stdout);
	printf("Overflows: %zu\n", fails.overflows); fflush(stdout);
	printf("Formatting Errors: %zu\n", fails.formats); fflush(stdout);
}
