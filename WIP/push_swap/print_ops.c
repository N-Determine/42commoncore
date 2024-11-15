/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeters <adeters@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 20:52:38 by adeters           #+#    #+#             */
/*   Updated: 2024/11/15 20:52:42 by adeters          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_ops(int operation)
{
	if (operation == SA)
		ft_printf("sa\n");
	if (operation == SB)
		ft_printf("sb\n");
	if (operation == SS)
		ft_printf("ss\n");
	if (operation == PA)
		ft_printf("pa\n");
	if (operation == PB)
		ft_printf("pb\n");
	if (operation == RA)
		ft_printf("ra\n");
	if (operation == RB)
		ft_printf("rb\n");
	if (operation == RR)
		ft_printf("rr\n");
	if (operation == RRA)
		ft_printf("rra\n");
	if (operation == RRB)
		ft_printf("rrb\n");
	if (operation == RRR)
		ft_printf("rrr\n");
}
