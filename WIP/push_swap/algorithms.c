/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeters <adeters@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 19:56:22 by adeters           #+#    #+#             */
/*   Updated: 2024/11/28 13:36:52 by adeters          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Puts everything from stack_b to stack_a in ascending order
 * (from bottom to top). It takes into account if it is faster to do
 * a rotate or a rrotate.
 *
 * It means "directed brute-force sort to stack_a"
 */
int	dir_bf_sort_to_a(t_stacks *stacks)
{
	int	i;
	int	steps;

	steps = 0;
	i = stacks->len - 1;
	while (i > 0)
	{
		if (stacks->stack_b->nb == stacks->sorted[i])
		{
			push_a(stacks);
			i--;
		}
		else if (nb_pos_down(stacks->stack_b,
				stacks->sorted[i]) < nb_pos_up(stacks->stack_b,
				stacks->sorted[i]))
			rotate_b(stacks, 1);
		else
			rrotate_b(stacks, 1);
		steps++;
	}
	push_a(stacks);
	return (steps + 1);
}

int	check_direction(int start, int end, t_stacks *stacks)
{
	if (nb_pos_down_range(stacks->stack_a, stacks->sorted[start],
			stacks->sorted[end]) < nb_pos_up_range(stacks->stack_a,
			stacks->sorted[start], stacks->sorted[end]))
		return (1);
	return (0);
}

int	block_pre_sort_to_b(t_stacks *stacks, int turn, int divider)
{
	int	i;
	int	steps;
	int	s;
	int	e;
	int	range;

	steps = 0;
	i = 0;
	range = stacks->len / divider;
	s = (turn - 1) * range;
	e = s + range - 1;
	while (i < range)
	{
		if (in_ran(stacks->stack_a->nb, stacks->sorted[s], stacks->sorted[e]))
		{
			push_b(stacks);
			i++;
		}
		else if (check_direction(s, e, stacks))
			rotate_a(stacks, 1);
		else
			rrotate_a(stacks, 1);
		steps++;
	}
	return (steps);
}

int	block_sort(t_stacks *stacks, int divider)
{
	int	steps;
	int	i;

	steps = 0;
	i = 0;
	while (i < divider)
	{
		steps += block_pre_sort_to_b(stacks, i + 1, divider);
		i++;
	}
	while (stacks->nodes_stack_a > 0)
	{
		push_b(stacks);
		steps++;
	}
	steps += dir_bf_sort_to_a(stacks);
	return (steps);
}

int	push_swap(t_stacks *stacks)
{
	int	i;

	if (is_sorted(stacks->stack_a))
		return (0);
	if (stacks->len >= 500)
		return (block_sort(stacks, 14));
	else if (stacks->len >= 100)
		return (block_sort(stacks, 6));
	else if (stacks->len > 10)
		return (block_sort(stacks, 4));
	if (stacks->len == 2)
		rotate_a(stacks, 1);
	return (1);
}
