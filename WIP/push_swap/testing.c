/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeters <adeters@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 17:35:28 by adeters           #+#    #+#             */
/*   Updated: 2024/11/18 18:31:40 by adeters          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_list(t_dlist *stack)
{
	int	i;

	i = 0;
	if (stack)
	{
		while (stack->next)
		{
			ft_printf("[%i]:\t%i\n", i + 1, stack->nb);
			stack = stack->next;
			i++;
		}
		ft_printf("[%i]:\t%i\n", i + 1, stack->nb);
	}
	else
		ft_printf("This stack is empty\n");
}

void	test_push_swap(t_stacks *stacks)
{
	int	steps;

	steps = 0;
	ft_printf("operations:\n");
	steps = push_swap(stacks);
	ft_printf("-----------\n");
	ft_printf("stack_a post-sorting:\n");
	print_list(stacks->stack_a);
	ft_printf("-----------\n");
	if (stacks->len <= 100 && steps >= 700)
		ft_printf("Inputs:\t\t%i\nOperations:\t\x1B[31m%i\n", stacks->len,
			steps);
	else if (stacks->len <= 500 && steps >= 5500)
		ft_printf("Inputs:\t\t%i\nOperations:\t\x1B[31m%i\n", stacks->len,
			steps);
	else
		ft_printf("Inputs:\t\t%i\nOperations:\t\x1B[32m%i\n", stacks->len,
			steps);
}
