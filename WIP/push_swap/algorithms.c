/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeters <adeters@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 19:56:22 by adeters           #+#    #+#             */
/*   Updated: 2024/11/27 18:13:57 by adeters          ###   ########.fr       */
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
	int steps;
	int i;

	// Don't do shit if it is sorted already
	if (is_sorted(stacks->stack_a))
		return (0);
	steps = 0;
	i = 0;
	// Do until everything is in stack b
	while(i < stacks->len / 4)
	{
		if (in_range(stacks->stack_a->nb, stacks->sorted[0], stacks->sorted[stacks->len / 4 - 1]))
		{
			push_b(stacks);
			i++;
			steps++;
		}
		else if (nb_pos_down_range(stacks->stack_a, stacks->sorted[0], stacks->sorted[stacks->len / 4 - 1]) < nb_pos_up_range(stacks->stack_a, stacks->sorted[0], stacks->sorted[stacks->len / 4 - 1]))
		{
			rotate_a(stacks, 1);
			steps++;
		}
		else
		{
			rrotate_a(stacks, 1);
			steps++;
		}
	}
	i = 0;
	while(i < stacks->len / 4)
	{
		if (in_range(stacks->stack_a->nb, stacks->sorted[stacks->len / 4], stacks->sorted[stacks->len / 2 - 1]))
		{
			push_b(stacks);
			i++;
			steps++;
		}
		else if (nb_pos_down_range(stacks->stack_a, stacks->sorted[stacks->len / 4], stacks->sorted[stacks->len / 2 - 1]) < nb_pos_up_range(stacks->stack_a, stacks->sorted[stacks->len / 4], stacks->sorted[stacks->len / 2 - 1]))
		{
			rotate_a(stacks, 1);
			steps++;
		}
		else
		{
			rrotate_a(stacks, 1);
			steps++;
		}
	}
	i = 0;
	while(i < stacks->len / 4)
	{
		if (in_range(stacks->stack_a->nb, stacks->sorted[stacks->len / 2 - 1], stacks->sorted[stacks->len / 2 + stacks->len / 4 - 1]))
		{
			push_b(stacks);
			i++;
			steps++;
		}
		else if (nb_pos_down_range(stacks->stack_a, stacks->sorted[stacks->len / 2 - 1], stacks->sorted[stacks->len / 2 + stacks->len / 4 - 1]) < nb_pos_up_range(stacks->stack_a, stacks->sorted[stacks->len / 2 - 1], stacks->sorted[stacks->len / 2 + stacks->len / 4 - 1]))
		{
			rotate_a(stacks, 1);
			steps++;
		}
		else
		{
			rrotate_a(stacks, 1);
			steps++;
		}
	}
	while (stacks->nodes_stack_a > 0)
	{
		push_b(stacks);
	}
	i = stacks->len - 1;
	while (i > 0)
	{
		if (stacks->stack_b->nb == stacks->sorted[i])
		{
			push_a(stacks);
			steps++;
			i--;
		}
		else if (nb_pos_down(stacks->stack_b, stacks->sorted[i]) < nb_pos_up(stacks->stack_b, stacks->sorted[i]))
		{
			rotate_b(stacks, 1);
			steps++;
		}
		else
		{
			rrotate_b(stacks, 1);
			steps++;
		}
	}
	push_a(stacks);
	steps++;
	return (steps);
}