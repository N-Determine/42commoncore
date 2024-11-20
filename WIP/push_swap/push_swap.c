/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeters <adeters@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 20:38:40 by adeters           #+#    #+#             */
/*   Updated: 2024/11/20 19:59:40 by adeters          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_fails		fails;
	t_stacks	stacks;

	if (ac < 2)
		return (0);
	if (check_args(ac, av, &fails))
		return (print_errors_args(ARGS, &fails), 1);
	if (fill_stacks(ac, av, &stacks, &fails))
		return (1);
	if (is_sorted(stacks.stack_a))
		return (free(stacks.sorted), clear_stack_a(&stacks), 0);
	stacks.stack_b = NULL;
	test_push_swap(&stacks);
	clear_stack_a(&stacks);
	free(stacks.sorted);
}
