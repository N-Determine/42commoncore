/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeters <adeters@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 20:38:40 by adeters           #+#    #+#             */
/*   Updated: 2024/11/16 19:40:12 by adeters          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

// Make this one create a new node and add it to the back
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

// Make this one create a doubly linked list
int fill_stacks(int ac, char **av, t_stacks *stacks)
{
	return (0);
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
		return (1); // Add error from new printer
}
