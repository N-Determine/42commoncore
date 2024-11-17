/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeters <adeters@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 16:47:23 by adeters           #+#    #+#             */
/*   Updated: 2024/11/17 16:54:54 by adeters          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a(t_stacks *stacks)
{
	if (stacks->nodes_stack_b > 0)
	{
		// Add head of b on top of a
		// Update alloc numbers for every stack
		stacks->nodes_stack_a++;
		stacks->nodes_stack_b--;
		print_ops(PA);
	}
}

void	push_b(t_stacks *stacks)
{
	if (stacks->nodes_stack_a > 0)
	{
		// Add head of a on top of b
		// Update alloc numbers for every stack
		stacks->nodes_stack_a++;
		stacks->nodes_stack_b--;
		print_ops(PB);
	}
}
