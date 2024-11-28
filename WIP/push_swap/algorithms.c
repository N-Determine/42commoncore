/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeters <adeters@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 19:56:22 by adeters           #+#    #+#             */
/*   Updated: 2024/11/28 17:48:35 by adeters          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_sort_three_a(t_stacks *stacks, int *big, int *small, int *steps)
{
	*steps = 1;
	*big = find_biggest(stacks->stack_a);
	*small = find_smallest(stacks->stack_a);
}

int	sort_three_a(t_stacks *stacks)
{
	int		steps;
	int		big;
	int		small;

	init_sort_three_a(stacks, &big, &small, &steps);
	if (big == last_node(stacks->stack_a)->nb)
		swap_a(stacks, 1);
	else if (is_sorted(stacks->stack_a->next) && big == stacks->stack_a->nb)
		rotate_a(stacks, 1);
	else if (big == stacks->stack_a->nb)
	{
		swap_a(stacks, 1);
		rrotate_a(stacks, 1);
		steps++;
	}
	else if (small == last_node(stacks->stack_a)->nb)
		rrotate_a(stacks, 1);
	else
	{
		rrotate_a(stacks, 1);
		swap_a(stacks, 1);
		steps++;
	}
	return (steps);
}

int	sort_smol(t_stacks *stacks)
{
	int	steps;

	steps = 0;
	while (stacks->nodes_stack_a > 3)
	{
		push_b(stacks);
		steps++;
	}
	sort_three_a(stacks);
	while (stacks->stack_b)
	{
		push_a(stacks);
		steps++;
	}
	return (steps);
}

int	push_swap(t_stacks *stacks)
{
	int	i;

	stacks->stack_b = NULL;
	if (is_sorted(stacks->stack_a))
		return (0);
	if (stacks->len >= 500)
		return (block_sort(stacks, 14));
	else if (stacks->len >= 100)
		return (block_sort(stacks, 6));
	else if (stacks->len > 10)
		return (block_sort(stacks, 4));
	else if (stacks->len > 3)
		return (sort_smol(stacks));
	else if (stacks->len == 3)
		return (sort_three_a(stacks));
	else if (stacks->len == 2)
		rotate_a(stacks, 1);
	return (1);
}
