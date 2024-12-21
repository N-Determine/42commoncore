/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_swap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeters <adeters@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 16:31:04 by adeters           #+#    #+#             */
/*   Updated: 2024/11/18 13:14:28 by adeters          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_stacks *stacks, int code)
{
	int	tmp;

	if (stacks->nodes_stack_a > 1)
	{
		tmp = stacks->stack_a->nb;
		stacks->stack_a->nb = stacks->stack_a->next->nb;
		stacks->stack_a->next->nb = tmp;
	}
	if (code == 1)
		print_ops(SA);
}

void	swap_b(t_stacks *stacks, int code)
{
	int	tmp;

	if (stacks->nodes_stack_b > 1)
	{
		tmp = stacks->stack_b->nb;
		stacks->stack_b->nb = stacks->stack_b->next->nb;
		stacks->stack_b->next->nb = tmp;
	}
	if (code == 1)
		print_ops(SB);
}

void	swap_s(t_stacks *stacks)
{
	swap_a(stacks, 0);
	swap_b(stacks, 0);
	print_ops(SS);
}
