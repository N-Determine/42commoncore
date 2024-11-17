/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filling.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeters <adeters@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 15:04:21 by adeters           #+#    #+#             */
/*   Updated: 2024/11/17 15:55:07 by adeters          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void	clear_stack_a(t_stacks *stacks)
{
	t_dlist	*tmp;
	int		i;

	i = 0;
	while (i < stacks->nodes_stack_a)
	{
		tmp = stacks->stack_a->next;
		free(stacks->stack_a);
		stacks->stack_a = tmp;
		i++;
	}	
}


int		create_stack(t_stacks *stacks)
{
	int		i;
	t_dlist	*start;

	stacks->stack_a = malloc(sizeof(t_stacks));
	if (!stacks->stack_a)
		return (1);
	stacks->nodes_stack_a = 1;
	stacks->stack_a->pre = NULL;
	stacks->stack_a->nb = stacks->sorted[0];
	start = stacks->stack_a;
	i = 1;
	while (i < stacks->len)
	{
		start->next = malloc(sizeof(t_stacks));
		if (!start->next)
			return (clear_stack_a(stacks), 1);
		stacks->nodes_stack_a++;
		start->next->nb = stacks->sorted[i];
		start->next->pre = start;
		start = start->next;
		i++;
	}
	start->next = NULL;
	return (0);
}

int		fill_stacks(int ac, char **av, t_stacks *stacks)
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
