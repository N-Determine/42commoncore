/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeters <adeters@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 20:38:40 by adeters           #+#    #+#             */
/*   Updated: 2024/11/18 15:29:29 by adeters          ###   ########.fr       */
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
			ft_printf("Pos: %i - Number: %i\n", i, stack->nb);
			stack = stack->next;
			i++;
		}
		ft_printf("Pos: %i - Number: %i\n", i, stack->nb);
	}
	else
		ft_printf("This stack is empty\n");
}

int	main(int ac, char **av)
{
	t_fails		fails;
	t_stacks	stacks;

	if (ac < 2)
		return (print_errors_args(USAGE, &fails), 1);
	if (check_args(ac, av, &fails))
		return (print_errors_args(ARGS, &fails), 1);
	if (fill_stacks(ac, av, &stacks))
		return (1);
	if (is_sorted(stacks.stack_a))
		return (free(stacks.sorted), clear_stack_a(&stacks), 0);
	stacks.stack_b = NULL;
	free(stacks.sorted);
}
