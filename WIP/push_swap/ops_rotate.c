/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeters <adeters@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 16:56:43 by adeters           #+#    #+#             */
/*   Updated: 2024/11/18 13:15:23 by adeters          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_stacks *stacks, int code)
{
	t_dlist	*last;
	t_dlist	*tmp;

	last = last_node(stacks->stack_a);
	if (stacks->nodes_stack_a > 1)
	{
		tmp = stacks->stack_a->next;
		last->next = stacks->stack_a;
		stacks->stack_a->pre = last;
		stacks->stack_a->next = NULL;
		stacks->stack_a = tmp;
		stacks->stack_a->pre = NULL;
	}
	if (code == 1)
		print_ops(RA);
}

void	rotate_b(t_stacks *stacks, int code)
{
	t_dlist	*last;
	t_dlist	*tmp;

	last = last_node(stacks->stack_b);
	if (stacks->nodes_stack_b > 1)
	{
		tmp = stacks->stack_b->next;
		last->next = stacks->stack_b;
		stacks->stack_b->pre = last;
		stacks->stack_b->next = NULL;
		stacks->stack_b = tmp;
		stacks->stack_b->pre = NULL;
	}
	if (code == 1)
		print_ops(RB);
}

void	rotate_r(t_stacks *stacks)
{
	rotate_a(stacks, 0);
	rotate_b(stacks, 0);
	print_ops(RR);
}