/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeters <adeters@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 20:38:40 by adeters           #+#    #+#             */
/*   Updated: 2024/11/18 17:37:02 by adeters          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push_swap(t_stacks *stacks)
{
	int	i;
	int	steps;

	i = 0;
	steps = 0;
	while (i < stacks->len)
	{
		while (stacks->stack_a->nb != stacks->sorted[i])
		{
			rotate_a(stacks, 1);
			steps++;
		}
		push_b(stacks);
		steps++;
		i++;
	}
	i = 0;
	while (i < stacks->len)
	{
		push_a(stacks);
		steps++;
		i++;
	}
	return (steps);
}

int	main(int ac, char **av)
{
	t_fails		fails;
	t_stacks	stacks;

	if (ac < 2)
		return (0);
	if (check_args(ac, av, &fails))
		return (print_errors_args(ARGS, &fails), 1);
	if (fill_stacks(ac, av, &stacks, &fails))
		return (1);
	if (is_sorted(stacks.stack_a))
		return (free(stacks.sorted), clear_stack_a(&stacks), 0);
	stacks.stack_b = NULL;
	test_push_swap(&stacks);
	clear_stack_a(&stacks);
	free(stacks.sorted);
}
