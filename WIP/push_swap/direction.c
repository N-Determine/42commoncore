/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   direction.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeters <adeters@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 19:28:01 by adeters           #+#    #+#             */
/*   Updated: 2024/11/27 19:00:52 by adeters          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	in_ran(int nb, int start, int end)
{
	if (nb >= start && nb <= end)
		return (1);
	return (0);
}

int	nb_pos_down(t_dlist *head, int n)
{
	int		steps;
	t_dlist	*tmp;

	steps = 0;
	tmp = head;
	while (tmp)
	{
		if (tmp->nb == n)
			break ;
		steps++;
		tmp = tmp->next;
	}
	return (steps);
}

int	nb_pos_up(t_dlist *head, int n)
{
	int		steps;
	t_dlist	*tmp;

	steps = 0;
	tmp = last_node(head);
	while (tmp)
	{
		if (tmp->nb == n)
			break ;
		steps++;
		tmp = tmp->pre;
	}
	return (steps);
}

int	nb_pos_down_range(t_dlist *head, int start, int end)
{
	int		steps;
	t_dlist	*tmp;

	steps = 0;
	tmp = head;
	while (tmp)
	{
		if (in_ran(tmp->nb, start, end))
			break ;
		steps++;
		tmp = tmp->next;
	}
	return (steps);
}

int	nb_pos_up_range(t_dlist *head, int start, int end)
{
	int		steps;
	t_dlist	*tmp;

	steps = 0;
	tmp = last_node(head);
	while (tmp)
	{
		if (in_ran(tmp->nb, start, end))
			break ;
		steps++;
		tmp = tmp->pre;
	}
	return (steps);
}
