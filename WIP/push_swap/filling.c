/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filling.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeters <adeters@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 15:04:21 by adeters           #+#    #+#             */
/*   Updated: 2024/11/17 15:23:59 by adeters          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	create_stack(t_stacks *stacks)
{
	int		i;
	t_dlist	*start;

	stacks->stack_a = malloc(sizeof(t_stacks));
	if (!stacks->stack_a)
		return (1);
	stacks->stack_a->pre = NULL;
	stacks->stack_a->nb = stacks->sorted[0];
	start = stacks->stack_a;
	i = 1;
	while (i < stacks->len)
	{
		start->next = malloc(sizeof(t_stacks));
		// In case of a fuck up we are going to need to clear the whole list!
		if (!start->next)
			return (1);
		start->next->nb = stacks->sorted[i];
		start->next->pre = start;
		start = start->next;
		i++;
	}
	start->next = NULL;
	return (0);
}

int	fill_stacks(int ac, char **av, t_stacks *stacks)
{
	int	i;

	stacks->len = ac - 1;
	stacks->sorted = malloc(stacks->len * sizeof(int));
	if (!stacks->sorted)
		return (print_errors(MAL_SORTED), 1);
	i = -1;
	while (++i < stacks->len)
		stacks->sorted[i] = ft_atoi(av[i + 1]);
	if (create_stack(stacks))
		return (free(stacks->sorted), 1);
	return (0);
}
