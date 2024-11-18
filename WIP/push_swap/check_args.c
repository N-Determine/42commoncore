/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeters <adeters@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 18:42:44 by adeters           #+#    #+#             */
/*   Updated: 2024/11/18 16:21:43 by adeters          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	if (!s1 || !s2)
		return (0);
	i = 0;
	while (s1[i])
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	while (s2[i])
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

int	check_duplicates(int ac, char **av, t_fails *fails)
{
	int	i;
	int	j;

	i = 1;
	while (i < ac)
	{
		j = i + 1;
		while (j < ac)
		{
			if (ft_strcmp(av[i], av[j]) == 0)
				fails->duplicates = 1;
			j++;
		}
		i++;
	}
	if (fails->duplicates > 0)
		return (1);
	return (0);
}

int	check_args(int ac, char **av, t_fails *fails)
{
	int	i;
	int	current;

	i = 1;
	init_fails(fails);
	while (i < ac)
	{
		current = check_overflow(av[i]);
		if (current == 1)
			fails->overflows++;
		if (current == -1)
			fails->underflows++;
		if (current == -2)
			fails->formats++;
		i++;
	}
	if (check_duplicates(ac, av, fails))
		return (1);
	if (fails->overflows > 0 || fails->underflows > 0)
		return (1);
	if (fails->formats > 0)
		return (1);
	return (0);
}
