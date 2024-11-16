/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeters <adeters@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 20:38:40 by adeters           #+#    #+#             */
/*   Updated: 2024/11/16 19:37:24 by adeters          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

t_dlist	*ft_dlstnew(t_dlist *pre, int *number)
{
	t_dlist	*new_node;

	new_node = (t_dlist *)malloc(sizeof(t_dlist));
	if (new_node == 0)
		return (0);
	new_node->nb = number;
	new_node->next = NULL;
	new_node->pre = pre;
	return (new_node);
}

// Initialize stack b as empty thing
// In a loop from 1 to ac
	// create a new node from a t_dlist with ft_atoi(av[i]) as content
int fill_stacks(int ac, char **av, t_stacks *stacks)
{
	int i;

	i = 2;
	stacks->stack_a->pre = NULL;
	stacks->stack_a->nb = ft_atoi(av[1]);
	while (i <= ac)
	{
		i++;
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_fails		fails;
	t_stacks	stacks;

	if (ac < 2)
		return (print_errors_args(USAGE, &fails), 1);
	if (check_args(ac, av, &fails))
		return (print_errors_args(ARGS, &fails), 1);
}
