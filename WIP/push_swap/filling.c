/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filling.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeters <adeters@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 15:04:21 by adeters           #+#    #+#             */
/*   Updated: 2024/11/28 15:16:52 by adeters          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	clear_stack_a(t_stacks *stacks)
{
	t_dlist	*tmp;
	int		i;
	int		allocs;

	i = 0;
	allocs = stacks->nodes_stack_a;
	while (i < allocs)
	{
		tmp = stacks->stack_a->next;
		free(stacks->stack_a);
		stacks->nodes_stack_a--;
		stacks->stack_a = tmp;
		i++;
	}
}

// Make this a quick sort algorithm for improved performance
int	create_stack(t_stacks *stacks)
{
	int		i;
	t_dlist	*start;

	stacks->stack_a = malloc(sizeof(t_stacks));
	if (!stacks->stack_a)
		return (1);
	stacks->nodes_stack_a = 1;
	stacks->nodes_stack_b = 0;
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

void	sort_arr(t_stacks *stacks)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < stacks->len)
	{
		j = i + 1;
		while (j < stacks->len)
		{
			if (stacks->sorted[i] > stacks->sorted[j])
			{
				tmp = stacks->sorted[i];
				stacks->sorted[i] = stacks->sorted[j];
				stacks->sorted[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

int	count_duplicates(t_stacks *stacks, t_fails *fails)
{
	int	i;

	i = 0;
	while (i < stacks->len - 1)
	{
		if (stacks->sorted[i] == stacks->sorted[i + 1])
			fails->duplicates++;
		i++;
	}
	if (fails->duplicates > 0)
		return (1);
	return (0);
}

int	fill_stacks(int ac, char **av, t_stacks *stacks, t_fails *fails)
{
	int	i;

	stacks->len = ac - 1 + stacks->str_in;
	stacks->sorted = malloc(stacks->len * sizeof(int));
	if (!stacks->sorted)
		return (print_errors(MAL), 1);
	i = -1;
	while (++i < stacks->len)
		stacks->sorted[i] = ft_atoi(av[i + 1 - stacks->str_in]);
	if (create_stack(stacks))
		return (print_errors(MAL), free(stacks->sorted), 1);
	sort_arr(stacks);
	if (count_duplicates(stacks, fails))
		return (print_errors_args(ARGS, fails), clear_stack_a(stacks),
			free(stacks->sorted), 1);
	return (0);
}
