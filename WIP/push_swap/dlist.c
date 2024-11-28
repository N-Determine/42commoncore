/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlist.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeters <adeters@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 13:05:44 by adeters           #+#    #+#             */
/*   Updated: 2024/11/28 17:38:48 by adeters          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_dlist	*last_node(t_dlist *head)
{
	if (!head)
		return (NULL);
	while (head->next)
	{
		head = head->next;
	}
	return (head);
}

int	is_sorted(t_dlist *head)
{
	if (!head)
		return (1);
	while (head->next)
	{
		if (head->nb > head->next->nb)
			return (0);
		head = head->next;
	}
	return (1);
}

int	find_biggest(t_dlist *head)
{
	int	biggest;

	if (head)
	{
		biggest = head->nb;
		while (head->next)
		{
			if (head->nb > biggest)
				biggest = head->nb;
			head = head->next;
		}
		if (head->nb > biggest)
			biggest = head->nb;
		return (biggest);
	}
	return (0);
}

int	find_smallest(t_dlist *head)
{
	int	smallest;

	if (head)
	{
		smallest = head->nb;
		while (head->next)
		{
			if (head->nb < smallest)
				smallest = head->nb;
			head = head->next;
		}
		if (head->nb < smallest)
			smallest = head->nb;
		return (smallest);
	}
	return (0);
}
