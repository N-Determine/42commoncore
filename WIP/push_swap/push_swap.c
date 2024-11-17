/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeters <adeters@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 20:38:40 by adeters           #+#    #+#             */
/*   Updated: 2024/11/17 15:01:19 by adeters          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

// Make this one create a doubly linked list
int	fill_stacks(int ac, char **av, t_stacks *stacks)
{
	int	i;

	stacks->len = ac - 1;
	stacks->sorted = malloc(stacks->len * sizeof(int));
	if (!stacks->sorted)
		return (print_errors(MAL_SORTED), 1);
	i = -1;
	while (++i < stacks->len)
		stacks->sorted[i] = ft_atoi(av[i + 1]);
	return (0);
}

int	main(int ac, char **av)
{
	t_fails		fails;
	t_stacks	stacks;

	if (ac < 2)
		return (print_errors_args(USAGE, &fails), 1);
	if (check_args(ac, av, &fails))
		return (print_errors_args(ARGS, &fails), 1);
	if (fill_stacks(ac, av, &stacks))
		return (1);
	// Free everything!!
	free(stacks.sorted);
}
