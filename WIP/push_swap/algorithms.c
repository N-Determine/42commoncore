/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeters <adeters@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 19:56:22 by adeters           #+#    #+#             */
/*   Updated: 2024/11/20 20:19:23 by adeters          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Absolute brute-force method
int	push_swap1(t_stacks *stacks)
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

// Shortened rotation movement brute-force
int	push_swap2(t_stacks *stacks)
{
	int	i;
	int	steps;

	i = 0;
	steps = 0;
	while (i < stacks->len)
	{
		while (stacks->stack_a->nb != stacks->sorted[i])
		{
			if (is_sorted(stacks->stack_a) && stacks->stack_b == NULL)
				return (steps);
			if (nb_pos_down(stacks->stack_a, stacks->sorted[i]) < nb_pos_up(stacks->stack_a, stacks->sorted[i]))
				rotate_a(stacks, 1);
			else
				rrotate_a(stacks, 1);
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

int push_swap3(t_stacks *stacks)
{
	
}