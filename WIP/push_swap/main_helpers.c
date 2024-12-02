/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_helpers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeters <adeters@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 15:34:25 by adeters           #+#    #+#             */
/*   Updated: 2024/12/02 19:47:34 by adeters          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isdigit_str(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]) && str[i] != '-' && str[i] != '+')
			return (0);
		i++;
	}
	return (1);
}

int	new_count(char **arr)
{
	int	i;

	i = 0;
	while (arr[i] != NULL)
		i++;
	return (i);
}

void	ft_free_all(char **arr, t_stacks *stacks)
{
	int	index;

	index = stacks->len;
	if (stacks->str_in && index)
	{
		while (index >= 0)
		{
			free(arr[index]);
			index--;
		}
		free(arr);
	}
}

int	check_single_str(int ac, char **av, t_fails *fails)
{
	if (check_args(ac, av, fails))
		return (print_errors_args(ARGS, fails), 1);
	else
		return (0);
}

char	**new_av_maker(char *input, int *ac, t_stacks *stacks)
{
	char	**new_av;

	new_av = ft_split(input, ' ');
	if (!new_av)
		return (print_errors(MAL), NULL);
	if (!new_av[0])
		return (free(new_av), print_errors(SPACE), NULL);
	*ac = new_count(new_av);
	stacks->len = *ac;
	stacks->str_in = 1;
	return (new_av);
}
