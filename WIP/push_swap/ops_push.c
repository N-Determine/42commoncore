/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeters <adeters@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 16:47:23 by adeters           #+#    #+#             */
/*   Updated: 2024/11/18 12:49:38 by adeters          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a(t_stacks *stacks)
{
	t_dlist	*tmp;

	if (stacks->nodes_stack_b > 0)
	{
		tmp = stacks->stack_a;
		stacks->stack_a = stacks->stack_b;
		stacks->stack_b = stacks->stack_b->next;
		if (stacks->stack_b)
			stacks->stack_b->pre = NULL;
		stacks->stack_a->next = tmp;
		if (tmp)
			stacks->stack_a->next->pre = stacks->stack_a;
		stacks->nodes_stack_a++;
		stacks->nodes_stack_b--;
		print_ops(PA);
	}
}

void	push_b(t_stacks *stacks)
{
	t_dlist	*tmp;

	if (stacks->nodes_stack_a > 0)
	{
		tmp = stacks->stack_b;
		stacks->stack_b = stacks->stack_a;
		stacks->stack_a = stacks->stack_a->next;
		if (stacks->stack_a)
			stacks->stack_a->pre = NULL;
		stacks->stack_b->next = tmp;
		if (tmp)
			stacks->stack_b->next->pre = stacks->stack_b;
		stacks->nodes_stack_a--;
		stacks->nodes_stack_b++;
		print_ops(PB);
	}
}
