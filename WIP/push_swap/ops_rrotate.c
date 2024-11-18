/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_rrotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeters <adeters@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 16:56:41 by adeters           #+#    #+#             */
/*   Updated: 2024/11/18 13:31:27 by adeters          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void				rrotate_a(t_stacks *stacks, int code)
{
	t_dlist	*last;

	last = last_node(stacks->stack_a);
	if (stacks->nodes_stack_a > 1)
	{
		last->pre->next = NULL;
		last->pre = NULL;
		last->next = stacks->stack_a;
		stacks->stack_a->pre = last;
		stacks->stack_a = last;
	}
	if (code == 1)
		print_ops(RRA);
}

void				rrotate_b(t_stacks *stacks, int code)
{
	t_dlist	*last;

	last = last_node(stacks->stack_b);
	if (stacks->nodes_stack_b > 1)
	{
		last->pre->next = NULL;
		last->pre = NULL;
		last->next = stacks->stack_b;
		stacks->stack_b->pre = last;
		stacks->stack_b = last;
	}
	if (code == 1)
		print_ops(RRB);
}

void				rrotate_r(t_stacks *stacks)
{
	rrotate_a(stacks, 0);
	rrotate_b(stacks, 0);
	print_ops(RRR);
}
