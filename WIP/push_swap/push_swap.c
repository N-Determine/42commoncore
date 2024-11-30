/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeters <adeters@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 19:56:22 by adeters           #+#    #+#             */
/*   Updated: 2024/11/30 16:51:59 by adeters          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_sort_three_a(t_stacks *stacks, int *big, int *small, int *steps)
{
	*steps = 1;
	*big = find_biggest(stacks->stack_a);
	*small = find_smallest(stacks->stack_a);
}

/**
 * @brief Sorts three numbers as efficiently as possible by covering every
 * possible case.
 */
int	sort_three_a(t_stacks *stacks)
{
	int	steps;
	int	big;
	int	small;

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

/**
 * @brief Sorts four numbers by outsourcing the smallest number
 * to the `stack_b`, sorting `stack_a` using the `sort_three_a`
 * algorithm and the pushing the smallest number back to `stack_a`
 */
int	sort_four_a(t_stacks *stacks)
{
	int	steps;
	int	smallest;
	int	direction;

	steps = 0;
	smallest = find_smallest(stacks->stack_a);
	direction = 0;
	if (nb_pos_down(stacks->stack_a, smallest) < nb_pos_up(stacks->stack_a,
			smallest))
		direction = 1;
	while (stacks->stack_a->nb != smallest)
	{
		if (direction == 0)
			rrotate_a(stacks, 1);
		else
			rotate_a(stacks, 1);
		steps++;
	}
	push_b(stacks);
	if (!is_sorted(stacks->stack_a))
		steps += sort_three_a(stacks);
	push_a(stacks);
	return (steps + 2);
}

/**
 * @brief Sorting five numbers using the `sort_four_a` function
 * after outsourcing the smallest number to `stack_b` and then
 * pushing it back.
 */
int	sort_five_a(t_stacks *stacks)
{
	int	steps;
	int	smallest;
	int	direction;

	steps = 0;
	smallest = find_smallest(stacks->stack_a);
	direction = 0;
	if (nb_pos_down(stacks->stack_a, smallest) < nb_pos_up(stacks->stack_a,
			smallest))
		direction = 1;
	while (stacks->stack_a->nb != smallest)
	{
		if (direction == 0)
			rrotate_a(stacks, 1);
		else
			rotate_a(stacks, 1);
		steps++;
	}
	push_b(stacks);
	if (!is_sorted(stacks->stack_a))
		steps += sort_four_a(stacks);
	push_a(stacks);
	return (steps + 2);
}

int	push_swap(t_stacks *stacks)
{
	stacks->stack_b = NULL;
	if (is_sorted(stacks->stack_a))
		return (0);
	if (stacks->len >= 500)
		return (block_sort(stacks, 14));
	else if (stacks->len >= 100)
		return (block_sort(stacks, 6));
	else if (stacks->len > 5)
		return (block_sort(stacks, 4));
	else if (stacks->len > 4)
		return (sort_five_a(stacks));
	else if (stacks->len > 3)
		return (sort_four_a(stacks));
	else if (stacks->len == 3)
		return (sort_three_a(stacks));
	else if (stacks->len == 2)
		rotate_a(stacks, 1);
	return (1);
}
